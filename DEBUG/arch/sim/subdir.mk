################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../arch/sim/jsbsim_thread.o 

C_SRCS += \
../arch/sim/ivy_transport.c \
../arch/sim/jsbsim_ahrs.c \
../arch/sim/jsbsim_gps.c \
../arch/sim/jsbsim_hw.c \
../arch/sim/jsbsim_ir.c \
../arch/sim/jsbsim_transport.c \
../arch/sim/led_hw.c \
../arch/sim/mcu_arch.c \
../arch/sim/sim_adc_generic.c 

OBJS += \
./arch/sim/ivy_transport.o \
./arch/sim/jsbsim_ahrs.o \
./arch/sim/jsbsim_gps.o \
./arch/sim/jsbsim_hw.o \
./arch/sim/jsbsim_ir.o \
./arch/sim/jsbsim_transport.o \
./arch/sim/led_hw.o \
./arch/sim/mcu_arch.o \
./arch/sim/sim_adc_generic.o 

C_DEPS += \
./arch/sim/ivy_transport.d \
./arch/sim/jsbsim_ahrs.d \
./arch/sim/jsbsim_gps.d \
./arch/sim/jsbsim_hw.d \
./arch/sim/jsbsim_ir.d \
./arch/sim/jsbsim_transport.d \
./arch/sim/led_hw.d \
./arch/sim/mcu_arch.d \
./arch/sim/sim_adc_generic.d 


# Each subdirectory must supply rules for building sources it contributes
arch/sim/%.o: ../arch/sim/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: RTEMS C Compiler'
	/home/gassa/research/rtems/rtems-builds/rtems-4.10/bin/sparc-rtems4.10-gcc -B/home/gassa/research/rtems/rtems-builds/rtems-4.10/sparc-rtems4.10/leon3/lib/ -specs bsp_specs -qrtems -mcpu=cypress -msoft-float -v -I"/home/gassa/my_code/rtems-workspace/rtems_pap_uav" -I"/home/gassa/my_code/rtems-workspace/rtems_pap_uav/subsystems" -I"/home/gassa/my_code/rtems-workspace/rtems_pap_uav/arch/sim" -I"/home/gassa/my_code/rtems-workspace/rtems_pap_uav/firmwares/fixedwing" -I"/home/gassa/my_code/rtems-workspace/rtems_pap_uav/modules" -I"/home/gassa/my_code/rtems-workspace/rtems_pap_uav/includes" -I"/home/gassa/my_code/rtems-workspace/rtems_pap_uav/mcu_periph" -DAGR_CLIMB -DLOITER_TRIM -DBOARD_CONFIG=\"boards/pc_sim.h\" -DPERIPHERALS_AUTO_INIT -DFIRMWARE=FIXEDWING -DWIND_INFO -DTRAFFIC_INFO -DUSE_LED -DPERIODIC_FREQUENCY=60 -DTELEMETRY_FREQUENCY=60 -DUSE_SYS_TIME -DINTER_MCU -DFBW -DAP -DINS_TYPE_H=\"subsystems/ins/ins_alt_float.h\" -DSHITL -DDOWNLINK -DDOWNLINK_TRANSPORT=IvyTransport -DRADIO_CONTROL -DRADIO_CONTROL_TYPE_H=\"subsystems/radio_control/ppm.h\" -DRADIO_CONTROL_TYPE_PPM -DCTRL_TYPE_H=\"firmwares/fixedwing/guidance/guidance_v.h\" -DUSE_INFRARED -DAHRS_TYPE_H=\"subsystems/ahrs/ahrs_infrared.h\" -DUSE_AHRS -DUSE_GPS -DGPS_TYPE_H=\"subsystems/gps/gps_sim.h\" -DNAV -DUSE_INFRARED_TELEMETRY -DDC_SHUTTER_SERVO=COMMAND_SHUTTER -DDIGITAL_CAM -DSENSOR_SYNC_SEND=1 -DDATALINK=PPRZ -DPPRZ_UART=UART1 -DSINGLE_MCU -DTRAFFIC_INFO -DDOWNLINK_DEVICE=UART1 -DUSE_UART1 -O0 -g3 -Wall -c -fmessage-length=0 -pipe -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


