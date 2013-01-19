################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ascii.c \
../chinese.c \
../led1602.c \
../main.c \
../nokia5110.c \
../spi.c 

OBJS += \
./ascii.o \
./chinese.o \
./led1602.o \
./main.o \
./nokia5110.o \
./spi.o 

C_DEPS += \
./ascii.d \
./chinese.d \
./led1602.d \
./main.d \
./nokia5110.d \
./spi.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g3 -gstabs -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega8 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


