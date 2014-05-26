/*
 * ethernet.c
 *
 *  Created on: Apr 7, 2014
 *      Author: rtdroid
 */
#include <stdio.h>
#include <bsp.h>
#include <rtems/rtems_bsdnet.h>
#include <network_interface_add.h>
#include "../../mcu_periph/uart.h"

/*Network configuration*/
static struct rtems_bsdnet_ifconfig netdriver_config = {
RTEMS_BSP_NETWORK_DRIVER_NAME, RTEMS_BSP_NETWORK_DRIVER_ATTACH, NULL,
		"10.42.0.2", /*IP address*/
		"255.255.255.0", /* IP net mask */
		NULL, 0, };

struct rtems_bsdnet_config rtems_bsdnet_config = { &netdriver_config, /* Network interface */
NULL, /* Use fixed network configuration */
0, /* Default network task priority */
0, /* Default mbuf capacity */
0, /* Default mbuf cluster capacity */
"Leon3", /* Host name */
"Leon3", /* Domain name */
"10.42.0.0", /* Gateway */
"10.42.0.3", /* Log host */
{ "127.0.0.1" }, /* Name server(s) */
{ "127.0.0.1" }, /* NTP server(s) */
};

static bool isInitialized = false;

void ethernet_init() {
	if (!isInitialized) {
		int net_state = 0;
		printf("\"Network\" initializing! HI DIEGO\n");
		net_state = rtems_bsdnet_initialize_network();
		printf("\"Network\" initialized! %d\n", net_state);
		isInitialized = true;
		rtems_bsdnet_show_inet_routes();
		rtems_bsdnet_show_mbuf_stats();
		rtems_bsdnet_show_if_stats();
		rtems_bsdnet_show_ip_stats();
		rtems_bsdnet_show_udp_stats();
	} else {
		printf("Ethernet is already initialized! \n");
	}
}
