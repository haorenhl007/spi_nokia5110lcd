################################################################################
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
spi_nokia5110lcd.lss \

FLASH_IMAGE += \
spi_nokia5110lcd.hex \

EEPROM_IMAGE += \
spi_nokia5110lcd.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# 所有目标
all: spi_nokia5110lcd.elf secondary-outputs

# 工具调用
spi_nokia5110lcd.elf: $(OBJS) $(USER_OBJS)
	@echo '正在构建目标： $@'
	@echo '正在调用： AVR C Linker'
	avr-gcc -Wl,-Map,spi_nokia5110lcd.map -mmcu=atmega8 -o "spi_nokia5110lcd.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo '已结束构建目标： $@'
	@echo ' '

spi_nokia5110lcd.lss: spi_nokia5110lcd.elf
	@echo '正在调用： AVR Create Extended Listing'
	-avr-objdump -h -S spi_nokia5110lcd.elf  >"spi_nokia5110lcd.lss"
	@echo '已结束构建： $@'
	@echo ' '

spi_nokia5110lcd.hex: spi_nokia5110lcd.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex spi_nokia5110lcd.elf  "spi_nokia5110lcd.hex"
	@echo '已结束构建： $@'
	@echo ' '

spi_nokia5110lcd.eep: spi_nokia5110lcd.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex spi_nokia5110lcd.elf  "spi_nokia5110lcd.eep"
	@echo '已结束构建： $@'
	@echo ' '

sizedummy: spi_nokia5110lcd.elf
	@echo '正在调用： Print Size'
	-avr-size --format=avr --mcu=atmega8 spi_nokia5110lcd.elf
	@echo '已结束构建： $@'
	@echo ' '

avrdudedummy: spi_nokia5110lcd.elf
	@echo '正在调用： AVRDude'
	/usr/bin/avrdude -pm8 -cusbasp -B500 -i500 -Uflash:w:spi_nokia5110lcd.hex:a
	@echo '已结束构建： $@'
	@echo ' '

# 其他目标
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) spi_nokia5110lcd.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
