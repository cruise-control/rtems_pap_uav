################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include tests/subdir.mk
-include subsystems/subdir.mk
-include subsystems/sensors/subdir.mk
-include subsystems/radio_control/subdir.mk
-include subsystems/navigation/subdir.mk
-include subsystems/ins/subdir.mk
-include subsystems/gps/subdir.mk
-include subsystems/datalink/subdir.mk
-include subsystems/ahrs/subdir.mk
-include modules/openlog/subdir.mk
-include modules/digital_cam/subdir.mk
-include mcu_periph/subdir.mk
-include math/subdir.mk
-include firmwares/fixedwing/stabilization/subdir.mk
-include firmwares/fixedwing/guidance/subdir.mk
-include firmwares/fixedwing/subdir.mk
-include arch/sim/subsystems/subdir.mk
-include arch/sim/subsystems/radio_control/subdir.mk
-include arch/sim/subsystems/actuators/subdir.mk
-include arch/sim/subdir.mk
-include arch/sim/peripherals/subdir.mk
-include arch/sim/mcu_periph/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: rtems_pap_uav.exe

# Tool invocations
rtems_pap_uav.exe: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: RTEMS Linker'
	/opt/rtems-4.10/bin/sparc-rtems4.10-gcc -B/opt/rtems-4.10/sparc-rtems4.10/leon3/lib/ -specs bsp_specs -qrtems -mcpu=cypress -msoft-float -o"rtems_pap_uav.exe" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(ASM_DEPS)$(C_DEPS)$(EXECUTABLES)$(S_UPPER_DEPS) rtems_pap_uav.exe
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
