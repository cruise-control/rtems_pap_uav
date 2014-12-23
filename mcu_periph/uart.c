/*
 * uart.c
 *
 *  Created on: May 24, 2013
 *      Author: Manish
 */
#include <rtems.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <rtems/libio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#if defined TARGET_PLATFORM && TARGET_PLATFORM == RPI
//<> is not working ... must not be properly linked to the project somehow
#include "/home/j3/dev/projects/utilities/rtems/built/4.11/arm-rtems4.11/raspberrypi/lib/include/bsp/usart.h"
#else
#include <apbuart.h>
#endif
#include "uart.h"

//#define _DEBUG

/*
 * All communication to UART device will be done through the
 * file system call of RTEMS. Therefore we will need to enable
 * posix api while building the RTEMS.
 */
#ifdef SERIO_TESTING
char pattern[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char test_send_buffer[37]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char test_recv_buffer[37];

#define size_send_buffer   (sizeof(test_send_buffer)/sizeof(test_send_buffer[0]))
#define size_recv_buffer   (sizeof(test_recv_buffer)/sizeof(test_recv_buffer[0]))
#endif

typedef struct {
	const char* uart_name; //name of the uart device.
	const char sem_name[4]; //semaphore name
	rtems_id semaphore_id; //id for the semaphore.
	int fd;                //file descriptor for uart.
	uint8_t byteAvailable;
} uart_dev_info_t;

// RTEMS has following names for the UART devices.
// Initially all UART devices has "-1" as their file
// descriptor which will be considered as "Invalid Descriptor".
#define MAX_UART_DEV_CNT                 3
#if defined TARGET_PLATFORM && TARGET_PLATFORM == RPI
static uart_dev_info_t uart_dev_arry[MAX_UART_DEV_CNT] = { { "/dev/console_a", {
		's', 'e', 'm', '0' }, 0, -1 }, { /*"/dev/console"*/"/dev/ttyS0", { 's',
		'e', 'm', '1' }, 0, -1 },
/*Add to this list if we do have more uart */
};
#else
static uart_dev_info_t uart_dev_arry[MAX_UART_DEV_CNT] = { {"/dev/console_a", {
			's', 'e', 'm', '0'}, 0, -1}, {"/dev/console_b",
		{	's', 'e', 'm', '1'}, 0, -1}, {"/dev/console_c", {'s', 'e', 'm',
			'2'}, 0, -1},
	/*Add to this list if we do have more uart */
};
#endif

/* uart_dev_arry[0] might being used as system console so watch for this */

/** Note:
 * While implementing each device interface to make it available to paparazzi I
 * needed to make a few assumptions. And for now these assumptions are valid according
 * to my current understanding. Therefore, modification in the code without considering
 * the assumptions might break something so please try to read them first before making
 * changes in the code. And if you also need to change the existing one or need to make
 * new assumptions please modify and add them to Assumption list in relevant source file.
 */
/*ASSUMPTIONS:
 * 1.All UART devices can be initialized once means once they are opened, they will have a
 * valid file descriptor and this descriptor will not be changed when some other task or same
 * task will try to initalize the opened UART again.
 * 2.We have assumed all calls like transmitting or recievng the data are non-blocking.
 * 3.If more than one task want to use the same UART at the same time access to device will
 * be synchronised.
 */
#define TX_BUFFER_LEN					 1024
#define RX_BUFFER_LEN					 1024
#define ISUARTOPENED(dev_index)          (uart_dev_arry[dev_index].fd != -1) ? TRUE : FALSE
#define ISVALIDUARTINDEX(dev_index)      (((dev_index >=0) && (dev_index < MAX_UART_DEV_CNT)) ? TRUE : FALSE)

static void uart_init(int dev_index);
static bool_t uart_checkfreespace(int dev_index, uint8_t len);
static void uart_transmit(int dev_index, uint8_t data);
static bool_t uart_chavailable(int dev_index);
static uint8_t uart_getch(int dev_index);
static bool_t uart_txrunning(int dev_index);
static void uart_setbaudrate(int dev_index, uint32_t baudrate,
		bool_t hw_Ctrl_flow);
static void uart_transmit_block(int dev_index, uint8_t *data, int length);

/*
 * The current driver which is being used for the UART is based upon termios.
 *  For details see "/c/src/libbsp/sparc/shared/uart/apbuart_cons.c"
 */
static void uart_init(int dev_index) {
	int fd;
	rtems_status_code status;
	rtems_name semaphore_name;
	rtems_id sem_id;
	struct termios tm;
	if (ISUARTOPENED(dev_index)) {
#ifdef _DEBUG
		printf("\nUART%d is already opened\n", dev_index);
#endif
		return;
	}

	/*Before opening the UART set the size of the receiver and transmitter buffer.*/
	rtems_termios_bufsize(256, RX_BUFFER_LEN, TX_BUFFER_LEN);

	fd = open(uart_dev_arry[dev_index].uart_name, O_RDWR | O_NONBLOCK);
	if (fd < 0) {
#ifdef _DEBUG
		printf("\nError:couldn't open uart%d\n", dev_index);
#endif
		return;
	}

	if (tcgetattr(fd, &tm) < 0) {
#ifdef _DEBUG
		printf("\nError:couldn't  get attr for uart%d\n", dev_index);
#endif
		close(fd);
		return;
	}

	/*set the flags for raw i/o. For flags description do man "termios"
	 * on your linux box.*/
	tm.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL
			| IXON);
	tm.c_oflag &= ~OPOST;
	tm.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	tm.c_cflag &= ~(CSIZE | PARENB);
	tm.c_cflag |= CS8;

	/*For Non Blocking I/O.*/
	tm.c_cc[VTIME] = 0;
	tm.c_cc[VMIN] = 0;

#if defined TARGET_PLATFORM && TARGET_PLATFORM == RPI
	/*set initial baud rate*/
	//This is hard coded in the RTEMS Rpi BSP for now. So, ensure that the termios is aware of it
	cfsetispeed(&tm, B115200);
	cfsetospeed(&tm, B115200);
#else
	/*set initial baud rate*/
	cfsetispeed(&tm, B230400);
	cfsetospeed(&tm, B230400);
#endif

	/*set and flush*/
	if (tcsetattr(fd, TCSANOW, &tm) < 0) {
#ifdef _DEBUG
		printf("\nError:couldn't  set attr for uart%d\n", dev_index);
#endif
		close(fd);
		return;
	}

	tcflush(fd, TCIOFLUSH);

	//create the binary semaphore for syncronization.
	semaphore_name = rtems_build_name(uart_dev_arry[dev_index].uart_name[0],
			uart_dev_arry[dev_index].uart_name[1],
			uart_dev_arry[dev_index].uart_name[2],
			uart_dev_arry[dev_index].uart_name[3]);
	/*
	 * Semaphore Options:
	 * FIFO
	 * BINARY Semaphore
	 * No_Inherit_Priority
	 * No_Priority_Ceiling
	 * Local
	 */
	status = rtems_semaphore_create(semaphore_name, 0,
	RTEMS_BINARY_SEMAPHORE | RTEMS_FIFO, 0, &sem_id);
	if (status != RTEMS_SUCCESSFUL) {
#ifdef _DEBUG
		printf("Error:couldn't create semaphore for uart%d", dev_index);
#endif
		close(fd);
		return;
	}

	uart_dev_arry[dev_index].byteAvailable = 0;
	uart_dev_arry[dev_index].fd = fd;
	uart_dev_arry[dev_index].semaphore_id = sem_id;
	return;
}

static void uart_transmit_block(int dev_index, uint8_t *data, int length) {
	int fd;
	size_t bytes;
	rtems_id sem_id;
	if (!ISUARTOPENED(dev_index)) {
		return;
	}

	fd = uart_dev_arry[dev_index].fd;
	sem_id = uart_dev_arry[dev_index].semaphore_id;

	if (rtems_semaphore_obtain(sem_id, RTEMS_WAIT, 0) != RTEMS_SUCCESSFUL) {
#ifdef _DEBUG
		printf("\nUART%d is already opened\n", dev_index);
#endif
		return;
	}
	bytes = write(fd, data, length);
	if (bytes < 0) {
		rtems_semaphore_release(sem_id);
#ifdef _DEBUG
		printf("Error in writing data to UART %d", dev_index);
#endif
	}
	rtems_semaphore_release(sem_id);
	return;
}

static void uart_transmit(int dev_index, uint8_t data) {
	int fd;
	size_t bytes;
	rtems_id sem_id;
	if (!ISUARTOPENED(dev_index)) {
		return;
	}

	fd = uart_dev_arry[dev_index].fd;
	sem_id = uart_dev_arry[dev_index].semaphore_id;

	if (rtems_semaphore_obtain(sem_id, RTEMS_WAIT, 0) != RTEMS_SUCCESSFUL) {
#ifdef _DEBUG
		printf("\nUART%d is already opened\n", dev_index);
#endif
		return;
	}
	bytes = write(fd, &data, 1);
	if (bytes < 0) {
		rtems_semaphore_release(sem_id);
#ifdef _DEBUG
		printf("Error in writing data to UART %d", dev_index);
#endif
	}
	rtems_semaphore_release(sem_id);
	return;
}
#ifdef SERIO_TESTING
static void spit_test_recvbuffer(void) {
	/*	int i=0;
	 for(i =0;i<size_recv_buffer;i++){
	 printf("%c",test_recv_buffer[i]);
	 }
	 memset(test_recv_buffer,0,size_recv_buffer);
	 printf("\n");*/
	return;
}
#endif
#if defined TARGET_PLATFORM && TARGET_PLATFORM == RPI

static uint8_t uart_getch(int dev_index) {
	int fd;
	uint8_t data = 0;
	size_t bytes;
	rtems_id sem_id;
	if (!ISUARTOPENED(dev_index)) {
		return 0;
	}
	fd = uart_dev_arry[dev_index].fd;
	sem_id = uart_dev_arry[dev_index].semaphore_id;

	if (rtems_semaphore_obtain(sem_id, RTEMS_WAIT, 0) != RTEMS_SUCCESSFUL) {
#ifdef _DEBUG
		printf("\nUART%d is already opened\n", dev_index);
#endif
		return data;
	}

	bytes = read(fd, &data, 1);

	//There was no new data read so bail
	if (bytes <= 0) {
		rtems_semaphore_release(sem_id);
		uart_dev_arry[dev_index].byteAvailable = 0;
#ifdef _DEBUG
		printf("Error in reading data to UART %d", dev_index);
#endif
		return 0x00;
	}
	uart_dev_arry[dev_index].byteAvailable = 1;
	rtems_semaphore_release(sem_id);

	return data;
}
#else
static uint8_t uart_getch(int dev_index) {
	int fd;
	uint8_t data = 0;
	size_t bytes;
	rtems_id sem_id;
#ifdef SERIO_TESTING
	static unsigned int test_index=0;
#endif
	if (!ISUARTOPENED(dev_index)) {
		return 0;
	}
	fd = uart_dev_arry[dev_index].fd;
	sem_id = uart_dev_arry[dev_index].semaphore_id;

	if (rtems_semaphore_obtain(sem_id, RTEMS_WAIT, 0) != RTEMS_SUCCESSFUL) {
#ifdef _DEBUG
		printf("\nUART%d is already opened\n", dev_index);
#endif
		return data;
	}

	bytes = read(fd, &data, 1);

	if (bytes < 0) {
		rtems_semaphore_release(sem_id);
#ifdef _DEBUG
		printf("Error in reading data to UART %d", dev_index);
#endif
		return data;
	}
#ifdef SERIO_TESTING
	if(test_index >=size_recv_buffer) {
		/*Now Buffer is full.*/
		spit_test_recvbuffer();
		test_index=0;
	} else {
		test_recv_buffer[test_index++]=data;
	}
#endif
	uart_dev_arry[dev_index].byteAvailable--;
	rtems_semaphore_release(sem_id);
	return data;
}
#endif

static void uart_setbaudrate(int dev_index, uint32_t baudrate,
		bool_t hw_Ctrl_flow) {
	int fd;
	struct termios tm;
	rtems_id sem_id;

	if (!ISUARTOPENED(dev_index)) {
		return;
	}

	fd = uart_dev_arry[dev_index].fd;
	sem_id = uart_dev_arry[dev_index].semaphore_id;

	if (rtems_semaphore_obtain(sem_id, RTEMS_WAIT, 0) != RTEMS_SUCCESSFUL) {
#ifdef _DEBUG
		printf("\nUART is already opened\n");
#endif
		return;
	}

	if (tcgetattr(fd, &tm) < 0) {
#ifdef _DEBUG
		printf("\nError:couldn't  get attr for uart\n");
#endif
		rtems_semaphore_release(sem_id);
		return;
	}

	if (cfsetospeed(&tm, baudrate) != 0) {

#ifdef _DEBUG
		printf("\nError: cfsetospeed couldn't  set baud rate for uart\n");
#endif
		rtems_semaphore_release(sem_id);
		return;
	}

	if (tcsetattr(fd, TCSANOW, &tm) < 0) {
#ifdef _DEBUG
		printf("\nError: tcsetattr couldn't  set attr for uart\n");
#endif
		rtems_semaphore_release(sem_id);
		return;
	}

	/*set initial baud rate*/
	if (cfsetispeed(&tm, baudrate) != 0) {
#ifdef _DEBUG
		printf("\nError: cfsetispeed couldn't  set baud for uart\n");
#endif
		rtems_semaphore_release(sem_id);
		return;
	}

	/*set and flush*/
	if (tcsetattr(fd, TCSANOW, &tm) < 0) {
#ifdef _DEBUG
		printf("\nError: tcsetattr couldn't  set attr for uart\n");
#endif
		close(fd);
		return;
	}

	rtems_semaphore_release(sem_id);
	return;
}

static bool_t uart_txrunning(int dev_index) {
	bool_t result = true;
	(void) dev_index;
	(void) result;
	return result;
}
static bool_t uart_checkfreespace(int dev_index, uint8_t len) {
	bool_t result = true;
	(void) dev_index;
	(void) len;
	(void) result;
	return result;

}
#if defined TARGET_PLATFORM && TARGET_PLATFORM == RPI
/**
 * Return true if the byte just read is valid. Otherwise, ignore it.
 */
static bool_t uart_chavailable(int dev_index) {

	if (!ISUARTOPENED(dev_index)) {
		return 0;
	}
	if (uart_dev_arry[dev_index].byteAvailable > 0) {
		return true;
	}

	return false;
}
#else
static bool_t uart_chavailable(int dev_index) {
	int fd;
	bool_t bresult;
	size_t bytesQueued;
	rtems_id sem_id;

	if (!ISUARTOPENED(dev_index)) {
		return 0;
	}
	if (uart_dev_arry[dev_index].byteAvailable > 0) {
		return true;
	}/*
	 else{
	 //check from kernel.
	 }
	 */
	fd = uart_dev_arry[dev_index].fd;
	sem_id = uart_dev_arry[dev_index].semaphore_id;

	if (rtems_semaphore_obtain(sem_id, RTEMS_WAIT, 0) != RTEMS_SUCCESSFUL) {
		/*an error must be returned.*/
		debug_pprz_msg("Getch: could not obtain the semaphore\r\n");
		return false;
	}

	if (ioctl(fd, FIONREAD, &bytesQueued) == -1) {
		rtems_semaphore_release(sem_id);
		debug_pprz_msg("Getch: ioctl return -1\r\n");
		return false;
	}
	if (bytesQueued) {
		bresult = true;
		uart_dev_arry[dev_index].byteAvailable = bytesQueued;
		debug_pprz_msg("Getch: has bytes queued!\r\n");
	} else {
		bresult = false;
		uart_dev_arry[dev_index].byteAvailable = 0;
//		debug_pprz_msg("Getch: has no bytes queued!\r\n");
	}
	rtems_semaphore_release(sem_id);
	return bresult;
}
#endif
#ifdef USE_UART0
void UART0Init(void) {
	uart_init(0);
}
bool_t UART0CheckFreeSpace(uint8_t len) {
	return uart_checkfreespace(0,len);
}

void UART0Transmit(uint8_t data) {
	return uart_transmit(0,data);
}
bool_t UART0ChAvailable(void) {
	return uart_chavailable(0);
}
uint8_t UART0Getch(void) {
	return uart_getch(0);
}
bool_t UART0TxRunning(void) {
	return uart_txrunning(0);
}

void UART0SetBaudrate(uint32_t baudrate) {
	return uart_setbaudrate(0,baudrate,false);
}
#endif

#ifdef USE_UART1
void uart1_init(void) {
	UART1Init();
}
void UART1Init(void) {
	uart_init(1);
}
bool_t UART1CheckFreeSpace(uint8_t len) {
	return uart_checkfreespace(1, len);
}
#define UART1_EXTRA_DEBUG
void UART1PutBuf(char *dta) {
#ifdef UART1_EXTRA_DEBUG
	while (*dta != '\0') {
		UART1Putc(*dta);
		dta++;
	}
#endif
}

void UART1Putc(uint8_t dta) {
#ifdef UART1_EXTRA_DEBUG
	return uart_transmit(1, dta);
#endif
}

void UART1Puts(const char * dta) {
#ifdef UART1_EXTRA_DEBUG
	while (*dta != '\0') {
		UART1Putc(*dta);
		dta++;
	}
#endif

}

void UART1TransmitBlock(char *data, int len) {
	return uart_transmit_block(1, (uint8_t*) data, len);
}
void UART1Transmit(uint8_t data) {
	return uart_transmit(1, data);
}
bool_t UART1ChAvailable(void) {
	return uart_chavailable(1);
}
void UART1SendMessage() {
	return;
}
uint8_t UART1Getch(void) {
	return uart_getch(1);
}
bool_t UART1TxRunning(void) {
	return uart_txrunning(1);
}

void UART1SetBaudrate(uint32_t baudrate) {
	return uart_setbaudrate(1, baudrate, false);
}
#endif
#ifdef USE_UART2
void UART2Init(void) {
	uart_init(0);
}
bool_t UART2CheckFreeSpace(uint8_t len) {
	return uart_checkfreespace(0,len);
}

void UART2Transmit(uint8_t data) {
	return uart_transmit(0,data);
}
bool_t UART2ChAvailable(void) {
	return uart_chavailable(0);
}
uint8_t UART2Getch(void) {
	return uart_getch(0);
}
bool_t UART2TxRunning(void) {
	return uart_txrunning(0);
}
void UART2SetBaudrate(uint32_t baudrate) {
	return uart_setbaudrate(0,baudrate,false);
}
#endif
#ifdef USE_UART3
void UART3Init(void) {
	uart_init(0);
}
bool_t UART3CheckFreeSpace(uint8_t len) {
	return uart_checkfreespace(0,len);
}

void UART3Transmit(uint8_t data) {
	return uart_transmit(0,data);
}
bool_t UART3ChAvailable(void) {
	return uart_chavailable(0);
}
uint8_t UART3Getch(void) {
	return uart_getch(0);
}
bool_t UART3TxRunning(void) {
	return uart_txrunning(0);
}
void UART3SetBaudrate(uint32_t baudrate) {
	return uart_setbaudrate(0,baudrate,false);
}
#endif
#ifdef USE_UART5
void UART5Init(void) {
	uart_init(0);
}
bool_t UART5CheckFreeSpace(uint8_t len) {
	return uart_checkfreespace(0,len);
}

void UART5Transmit(uint8_t data) {
	return uart_transmit(0,data);
}
bool_t UART5ChAvailable(void) {
	return uart_chavailable(0);
}
uint8_t UART5Getch(void) {
	return uart_getch(0);
}
bool_t UART5TxRunning(void) {
	return uart_txrunning(0);
}

void UART5SetBaudrate(uint32_t baudrate) {
	return uart_setbaudrate(0,baudrate,false);
}
#endif

