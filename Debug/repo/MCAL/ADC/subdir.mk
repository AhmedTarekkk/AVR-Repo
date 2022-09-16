################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../repo/MCAL/ADC/ADC.c 

OBJS += \
./repo/MCAL/ADC/ADC.o 

C_DEPS += \
./repo/MCAL/ADC/ADC.d 


# Each subdirectory must supply rules for building sources it contributes
repo/MCAL/ADC/%.o: ../repo/MCAL/ADC/%.c repo/MCAL/ADC/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


