################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ascii.c \
../main.c \
../nokia5110.c \
../spi.c 

OBJS += \
./ascii.o \
./main.o \
./nokia5110.o \
./spi.o 

C_DEPS += \
./ascii.d \
./main.d \
./nokia5110.d \
./spi.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo '正在构建文件： $<'
	@echo '正在调用： AVR Compiler'
	avr-gcc -Wall -g3 -gstabs -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega8 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '


