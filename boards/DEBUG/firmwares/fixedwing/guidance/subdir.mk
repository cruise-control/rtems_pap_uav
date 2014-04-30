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
	/opt/rtems-4.10/bin/sparc-rtems4.10-gcc -B/opt/rtems-4.10/sparc-rtems4.10/leon3/lib/ -specs bsp_specs -qrtems -mcpu=cypress -msoft-float -v -I"/home/manish/workspace_rtems_pap/rtems_pap_uav" -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/arch/sim" -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/firmwares/fixedwing" -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/modules" -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/includes" -DNAV -DPERIPHERALS_AUTO_INIT -DUSE_IVY -DDATALINK=PPRZ -DDOWNLINK -DDOWNLINK_TRANSPORT=PprzTransport -DIVY_TRANSPORT=IvyTransport -DPERIODIC_C_FBW -DSENSOR_SYNC_SEND=1 -DBOARD_CONFIG=\"boards/pc_sim.h\" -DSINGLE_MCU -DLOITER_TRIM -DFIRMWARE=FIXEDWING -DWIND_INFO -DTRAFFIC_INFO -DPERIODIC_FREQUENCY=60 -DTELEMETRY_FREQUENCY=60 -DUSE_SYS_TIME -DINTER_MCU -DAP -DINS_TYPE_H=\"subsystems/ins/ins_alt_float.h\" -DAHRS_TYPE_H=\"subsystems/ahrs/ahrs_infrared.h\" -DAGR_CLIMB -DDOWNLINK_DEVICE=UART1 -DCTRL_TYPE_H=\"firmwares/fixedwing/guidance/guidance_v.h\" -O0 -g3 -Wall -c -fmessage-length=0 -pipe -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


