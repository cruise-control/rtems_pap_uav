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
	/opt/rtems-4.10/bin/sparc-rtems4.10-gcc -B/opt/rtems-4.10/sparc-rtems4.10/leon3/lib/ -specs bsp_specs -qrtems -mcpu=cypress -msoft-float -v -I"/home/manish/workspace_rtems_pap/rtems_pap_uav" -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/subsystems" -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/arch/sim" -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/firmwares/fixedwing" -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/modules" -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/includes" -DNAV -DSHITL -DTRAFFIC_INFO -DRADIO_CONTROL -DPERIPHERALS_AUTO_INIT -DUSE_IVY -DDATALINK=PPRZ -DDOWNLINK -DPPRZ_UART=UART1 -DDOWNLINK_TRANSPORT=PprzTransport -DIVY_TRANSPORT=IvyTransport -DPERIODIC_C_FBW -DSENSOR_SYNC_SEND=1 -DBOARD_CONFIG=\"boards/pc_sim.h\" -DSINGLE_MCU -DLOITER_TRIM -DFIRMWARE=FIXEDWING -DWIND_INFO -DTRAFFIC_INFO -DPERIODIC_FREQUENCY=60 -DTELEMETRY_FREQUENCY=60 -DUSE_SYS_TIME -DINTER_MCU -DFBW -DAP -DINS_TYPE_H=\"subsystems/ins/ins_alt_float.h\" -DAHRS_TYPE_H=\"subsystems/ahrs/ahrs_infrared.h\" -DAGR_CLIMB -DDOWNLINK_DEVICE=UART1 -DCTRL_TYPE_H=\"firmwares/fixedwing/guidance/guidance_v.h\" -DUSE_GPS -DUSE_AHRS -DGPS_TYPE_H=\"subsystems/gps/gps_sim.h\" -DRADIO_CONTROL_TYPE_H=\"subsystems/radio_control/ppm.h\" -DRADIO_CONTROL_TYPE_PPM -DDC_SHUTTER_SERVO=COMMAND_SHUTTER -UDIGITAL_CAM -O0 -g3 -Wall -c -fmessage-length=0 -pipe -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


