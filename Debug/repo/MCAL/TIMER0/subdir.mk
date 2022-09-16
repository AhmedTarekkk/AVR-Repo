################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../repo/MCAL/TIMER0/TIMER0.c 

OBJS += \
./repo/MCAL/TIMER0/TIMER0.o 

C_DEPS += \
./repo/MCAL/TIMER0/TIMER0.d 


# Each subdirectory must supply rules for building sources it contributes
repo/MCAL/TIMER0/%.o: ../repo/MCAL/TIMER0/%.c repo/MCAL/TIMER0/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


