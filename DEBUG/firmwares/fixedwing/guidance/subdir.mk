################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../firmwares/fixedwing/guidance/guidance_v.c 

OBJS += \
./firmwares/fixedwing/guidance/guidance_v.o 

C_DEPS += \
./firmwares/fixedwing/guidance/guidance_v.d 


# Each subdirectory must supply rules for building sources it contributes
firmwares/fixedwing/guidance/%.o: ../firmwares/fixedwing/guidance/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: RTEMS C Compiler'
	/home/rtdroid/harsha/development/rtems/4.10-sparc/bin/sparc-rtems4.10-gcc -B/home/rtdroid/harsha/development/rtems/4.10-sparc/sparc-rtems4.10/leon3/lib/ -specs bsp_specs -qrtems -mcpu=cypress -msoft-float -v -I"/home/rtdroid/sai/paparazzi/rtems_pap_uav_Ethernet/rtems_pap_uav" -I"/home/rtdroid/sai/paparazzi/rtems_pap_uav_Ethernet/rtems_pap_uav/subsystems" -I"/home/rtdroid/sai/paparazzi/rtems_pap_uav_Ethernet/rtems_pap_uav/arch/sim" -I"/home/rtdroid/sai/paparazzi/rtems_pap_uav_Ethernet/rtems_pap_uav/firmwares/fixedwing" -I"/home/rtdroid/sai/paparazzi/rtems_pap_uav_Ethernet/rtems_pap_uav/modules" -I"/home/rtdroid/sai/paparazzi/rtems_pap_uav_Ethernet/rtems_pap_uav/includes" -I"/home/rtdroid/sai/paparazzi/rtems_pap_uav_Ethernet/rtems_pap_uav/mcu_periph" -DAGR_CLIMB -DLOITER_TRIM -DBOARD_CONFIG=\"boards/pc_sim.h\" -DPERIPHERALS_AUTO_INIT -DFIRMWARE=FIXEDWING -DWIND_INFO -DTRAFFIC_INFO -DUSE_LED -DPERIODIC_FREQUENCY=60 -DTELEMETRY_FREQUENCY=60 -DUSE_SYS_TIME -DINTER_MCU -DFBW -DAP -DINS_TYPE_H=\"subsystems/ins/ins_alt_float.h\" -DSHITL -DDOWNLINK -DDOWNLINK_TRANSPORT=IvyTransport -DRADIO_CONTROL -DRADIO_CONTROL_TYPE_H=\"subsystems/radio_control/ppm.h\" -DRADIO_CONTROL_TYPE_PPM -DCTRL_TYPE_H=\"firmwares/fixedwing/guidance/guidance_v.h\" -DUSE_INFRARED -DAHRS_TYPE_H=\"subsystems/ahrs/ahrs_infrared.h\" -DUSE_AHRS -DUSE_GPS -DGPS_TYPE_H=\"subsystems/gps/gps_sim.h\" -DNAV -DUSE_INFRARED_TELEMETRY -DDC_SHUTTER_SERVO=COMMAND_SHUTTER -DDIGITAL_CAM -DSENSOR_SYNC_SEND=1 -DDATALINK=PPRZ -DPPRZ_UART=UART1 -DSINGLE_MCU -DTRAFFIC_INFO -DDOWNLINK_DEVICE=UART1 -DUSE_UART1 -DNO_ETHERNET -O0 -g3 -Wall -c -fmessage-length=0 -pipe -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


