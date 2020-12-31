################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Rarchi_game.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Rarchi_game.list \

OBJCOPY_BIN += \
Rarchi_game.bin \


# All Target
all: Rarchi_game.elf secondary-outputs

# Tool invocations
Rarchi_game.elf: $(OBJS) $(USER_OBJS) C:\Users\Tecnica2\Desktop\work\STM32\Rarchi_game\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "Rarchi_game.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\Tecnica2\Desktop\work\STM32\Rarchi_game\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Rarchi_game.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Rarchi_game.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Rarchi_game.list"
	@echo 'Finished building: $@'
	@echo ' '

Rarchi_game.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Rarchi_game.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
