################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../repo/APP/ADC.c \
../repo/APP/Challenge1.c \
../repo/APP/EXTI_APP.c \
../repo/APP/LCD_App.c \
../repo/APP/LED.c \
../repo/APP/LED2.c \
../repo/APP/PushButton.c \
../repo/APP/PushButton2.c \
../repo/APP/SevenSegment.c \
../repo/APP/TimeLab.c 

OBJS += \
./repo/APP/ADC.o \
./repo/APP/Challenge1.o \
./repo/APP/EXTI_APP.o \
./repo/APP/LCD_App.o \
./repo/APP/LED.o \
./repo/APP/LED2.o \
./repo/APP/PushButton.o \
./repo/APP/PushButton2.o \
./repo/APP/SevenSegment.o \
./repo/APP/TimeLab.o 

C_DEPS += \
./repo/APP/ADC.d \
./repo/APP/Challenge1.d \
./repo/APP/EXTI_APP.d \
./repo/APP/LCD_App.d \
./repo/APP/LED.d \
./repo/APP/LED2.d \
./repo/APP/PushButton.d \
./repo/APP/PushButton2.d \
./repo/APP/SevenSegment.d \
./repo/APP/TimeLab.d 


# Each subdirectory must supply rules for building sources it contributes
repo/APP/%.o: ../repo/APP/%.c repo/APP/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


