################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../subsystems/ahrs/ahrs_infrared.c 

OBJS += \
./subsystems/ahrs/ahrs_infrared.o 

C_DEPS += \
./subsystems/ahrs/ahrs_infrared.d 


# Each subdirectory must supply rules for building sources it contributes
subsystems/ahrs/%.o: ../subsystems/ahrs/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: RTEMS C Compiler'
	/home/gassa/research/rtems/rtems-builds/rtems-4.10/bin/sparc-rtems4.10-gcc -B/home/gassa/research/rtems/rtems-builds/rtems-4.10/sparc-rtems4.10/leon3/lib/ -specs bsp_specs -qrtems -mcpu=cypress -msoft-float -v -I"/home/gassa/my_code/rtems-workspace/rtems_pap_uav" -I"/home/gassa/my_code/rtems-workspace/rtems_pap_uav/subsystems" -I"/home/gassa/my_code/rtems-workspace/rtems_pap_uav/arch/sim" -I"/home/gassa/my_code/rtems-workspace/rtems_pap_uav/firmwares/fixedwing" -I"/home/gassa/my_code/rtems-workspace/rtems_pap_uav/modules" -I"/home/gassa/my_code/rtems-workspace/rtems_pap_uav/includes" -I"/home/gassa/my_code/rtems-workspace/rtems_pap_uav/mcu_periph" -DAGR_CLIMB -DLOITER_TRIM -DBOARD_CONFIG=\"boards/pc_sim.h\" -DPERIPHERALS_AUTO_INIT -DFIRMWARE=FIXEDWING -DWIND_INFO -DTRAFFIC_INFO -DUSE_LED -DPERIODIC_FREQUENCY=60 -DTELEMETRY_FREQUENCY=60 -DUSE_SYS_TIME -DINTER_MCU -DFBW -DAP -DINS_TYPE_H=\"subsystems/ins/ins_alt_float.h\" -DSHITL -DDOWNLINK -DDOWNLINK_TRANSPORT=IvyTransport -DRADIO_CONTROL -DRADIO_CONTROL_TYPE_H=\"subsystems/radio_control/ppm.h\" -DRADIO_CONTROL_TYPE_PPM -DCTRL_TYPE_H=\"firmwares/fixedwing/guidance/guidance_v.h\" -DUSE_INFRARED -DAHRS_TYPE_H=\"subsystems/ahrs/ahrs_infrared.h\" -DUSE_AHRS -DUSE_GPS -DGPS_TYPE_H=\"subsystems/gps/gps_sim.h\" -DNAV -DUSE_INFRARED_TELEMETRY -DDC_SHUTTER_SERVO=COMMAND_SHUTTER -DDIGITAL_CAM -DSENSOR_SYNC_SEND=1 -DDATALINK=PPRZ -DPPRZ_UART=UART1 -DSINGLE_MCU -DTRAFFIC_INFO -DDOWNLINK_DEVICE=UART1 -DUSE_UART1 -O0 -g3 -Wall -c -fmessage-length=0 -pipe -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


