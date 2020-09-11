################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lab8.c \
../Lab8_test.c \
../data.c \
../process.c 

OBJS += \
./Lab8.o \
./Lab8_test.o \
./data.o \
./process.o 

C_DEPS += \
./Lab8.d \
./Lab8_test.d \
./data.d \
./process.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


