################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../repo/MCAL/GIE/GIE.c 

OBJS += \
./repo/MCAL/GIE/GIE.o 

C_DEPS += \
./repo/MCAL/GIE/GIE.d 


# Each subdirectory must supply rules for building sources it contributes
repo/MCAL/GIE/%.o: ../repo/MCAL/GIE/%.c repo/MCAL/GIE/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

