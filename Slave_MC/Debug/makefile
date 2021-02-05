################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Slave_MC.lss \

FLASH_IMAGE += \
Slave_MC.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Slave_MC.elf secondary-outputs

# Tool invocations
Slave_MC.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Slave_MC.map -mmcu=atmega328 -o "Slave_MC.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Slave_MC.lss: Slave_MC.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Slave_MC.elf  >"Slave_MC.lss"
	@echo 'Finished building: $@'
	@echo ' '

Slave_MC.hex: Slave_MC.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Slave_MC.elf  "Slave_MC.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Slave_MC.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t Slave_MC.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Slave_MC.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
