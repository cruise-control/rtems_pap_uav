################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mcu_periph/sys_time.c \
../mcu_periph/uart.c 

OBJS += \
./mcu_periph/sys_time.o \
./mcu_periph/uart.o 

C_DEPS += \
./mcu_periph/sys_time.d \
./mcu_periph/uart.d 


# Each subdirectory must supply rules for building sources it contributes
mcu_periph/%.o: ../mcu_periph/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: RTEMS C Compiler'
	/opt/rtems-4.10/bin/sparc-rtems4.10-gcc -B/opt/rtems-4.10/sparc-rtems4.10/leon3/lib/ -specs bsp_specs -qrtems -mcpu=cypress -msoft-float -v -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/includes" -I../ -D_DEBUG -O0 -g3 -Wall -c -fmessage-length=0 -pipe -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


