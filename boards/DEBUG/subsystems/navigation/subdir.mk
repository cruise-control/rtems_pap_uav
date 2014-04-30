################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../subsystems/navigation/bomb.c \
../subsystems/navigation/border_line.c \
../subsystems/navigation/common_flight_plan.c \
../subsystems/navigation/common_nav.c \
../subsystems/navigation/discsurvey.c \
../subsystems/navigation/flightzone.c \
../subsystems/navigation/gls.c \
../subsystems/navigation/nav_cube.c \
../subsystems/navigation/nav_line.c \
../subsystems/navigation/nav_survey_rectangle.c \
../subsystems/navigation/poly_survey_adv.c \
../subsystems/navigation/snav.c \
../subsystems/navigation/spiral.c \
../subsystems/navigation/traffic_info.c 

OBJS += \
./subsystems/navigation/bomb.o \
./subsystems/navigation/border_line.o \
./subsystems/navigation/common_flight_plan.o \
./subsystems/navigation/common_nav.o \
./subsystems/navigation/discsurvey.o \
./subsystems/navigation/flightzone.o \
./subsystems/navigation/gls.o \
./subsystems/navigation/nav_cube.o \
./subsystems/navigation/nav_line.o \
./subsystems/navigation/nav_survey_rectangle.o \
./subsystems/navigation/poly_survey_adv.o \
./subsystems/navigation/snav.o \
./subsystems/navigation/spiral.o \
./subsystems/navigation/traffic_info.o 

C_DEPS += \
./subsystems/navigation/bomb.d \
./subsystems/navigation/border_line.d \
./subsystems/navigation/common_flight_plan.d \
./subsystems/navigation/common_nav.d \
./subsystems/navigation/discsurvey.d \
./subsystems/navigation/flightzone.d \
./subsystems/navigation/gls.d \
./subsystems/navigation/nav_cube.d \
./subsystems/navigation/nav_line.d \
./subsystems/navigation/nav_survey_rectangle.d \
./subsystems/navigation/poly_survey_adv.d \
./subsystems/navigation/snav.d \
./subsystems/navigation/spiral.d \
./subsystems/navigation/traffic_info.d 


# Each subdirectory must supply rules for building sources it contributes
subsystems/navigation/%.o: ../subsystems/navigation/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: RTEMS C Compiler'
	/opt/rtems-4.10/bin/sparc-rtems4.10-gcc -B/opt/rtems-4.10/sparc-rtems4.10/leon3/lib/ -specs bsp_specs -qrtems -mcpu=cypress -msoft-float -v -I"/home/manish/workspace_rtems_pap/rtems_pap_uav" -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/arch/sim" -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/firmwares/fixedwing" -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/modules" -I"/home/manish/workspace_rtems_pap/rtems_pap_uav/includes" -DNAV -DPERIPHERALS_AUTO_INIT -DUSE_IVY -DDATALINK=PPRZ -DDOWNLINK -DDOWNLINK_TRANSPORT=PprzTransport -DIVY_TRANSPORT=IvyTransport -DPERIODIC_C_FBW -DSENSOR_SYNC_SEND=1 -DBOARD_CONFIG=\"boards/pc_sim.h\" -DSINGLE_MCU -DLOITER_TRIM -DFIRMWARE=FIXEDWING -DWIND_INFO -DTRAFFIC_INFO -DPERIODIC_FREQUENCY=60 -DTELEMETRY_FREQUENCY=60 -DUSE_SYS_TIME -DINTER_MCU -DAP -DINS_TYPE_H=\"subsystems/ins/ins_alt_float.h\" -DAHRS_TYPE_H=\"subsystems/ahrs/ahrs_infrared.h\" -DAGR_CLIMB -DDOWNLINK_DEVICE=UART1 -DCTRL_TYPE_H=\"firmwares/fixedwing/guidance/guidance_v.h\" -O0 -g3 -Wall -c -fmessage-length=0 -pipe -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


