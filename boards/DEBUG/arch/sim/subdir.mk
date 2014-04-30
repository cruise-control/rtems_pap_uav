################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../arch/sim/ivy_transport.c \
../arch/sim/jsbsim_gps.c \
../arch/sim/led_hw.c \
../arch/sim/mcu_arch.c \
../arch/sim/sim_adc_generic.c 

OBJS += \
./arch/sim/ivy_transport.o \
./arch/sim/jsbsim_gps.o \
./arch/sim/led_hw.o \
./arch/sim/mcu_arch.o \
./arch/sim/sim_adc_generic.o 

C_DEPS += \
./arch/sim/ivy_transport.d \
./arch/sim/jsbsim_gps.d \
./arch/sim/led_hw.d \
./arch/sim/mcu_arch.d \
./arch/sim/sim_adc_generic.d 


# Each subdirectory must supply rules for building sources it contributes
arch/sim/%.o: ../arch/sim/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: RTEMS C Compiler'
	/opt/rtems-4.10/bin/sparc-rtems4.10-gcc -B/opt/rtems-4.10/sparc-rtems4.10/leon3/lib/ -specs bsp_specs -qrtems -mcpu=cypress -msoft-float -v -I"/home/manish/workspace_rtems_pap/rtems_pap_uav" -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/arch/sim" -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/firmwares/fixedwing" -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/modules" -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/includes" -DNAV -DPERIPHERALS_AUTO_INIT -DUSE_IVY -DDATALINK=PPRZ -DDOWNLINK -DDOWNLINK_TRANSPORT=PprzTransport -DIVY_TRANSPORT=IvyTransport -DPERIODIC_C_FBW -DSENSOR_SYNC_SEND=1 -DBOARD_CONFIG=\"boards/pc_sim.h\" -DSINGLE_MCU -DLOITER_TRIM -DFIRMWARE=FIXEDWING -DWIND_INFO -DTRAFFIC_INFO -DPERIODIC_FREQUENCY=60 -DTELEMETRY_FREQUENCY=60 -DUSE_SYS_TIME -DINTER_MCU -DAP -DINS_TYPE_H=\"subsystems/ins/ins_alt_float.h\" -DAHRS_TYPE_H=\"subsystems/ahrs/ahrs_infrared.h\" -DAGR_CLIMB -DDOWNLINK_DEVICE=UART1 -DCTRL_TYPE_H=\"firmwares/fixedwing/guidance/guidance_v.h\" -O0 -g3 -Wall -c -fmessage-length=0 -pipe -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


