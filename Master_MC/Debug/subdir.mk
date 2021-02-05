################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../Delay_program.c \
../INT_program.c \
../LED_program.c \
../SPI_program.c \
../TIMER_program.c \
../UART_program.c \
../main.c 

OBJS += \
./DIO_program.o \
./Delay_program.o \
./INT_program.o \
./LED_program.o \
./SPI_program.o \
./TIMER_program.o \
./UART_program.o \
./main.o 

C_DEPS += \
./DIO_program.d \
./Delay_program.d \
./INT_program.d \
./LED_program.d \
./SPI_program.d \
./TIMER_program.d \
./UART_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


