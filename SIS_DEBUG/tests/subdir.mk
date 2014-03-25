################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tests/uart_test.c 

OBJS += \
./tests/uart_test.o 

C_DEPS += \
./tests/uart_test.d 


# Each subdirectory must supply rules for building sources it contributes
tests/%.o: ../tests/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: RTEMS C Compiler'
	/opt/rtems-4.10/bin/sparc-rtems4.10-gcc -B/opt/rtems-4.10/sparc-rtems4.10/sis/lib/ -specs bsp_specs -qrtems -mcpu=cypress -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/includes" -O0 -g3 -Wall -c -fmessage-length=0 -pipe -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


