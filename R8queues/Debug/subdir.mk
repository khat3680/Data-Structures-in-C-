################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../R8_test.c \
../cqueue.c \
../data.c \
../process.c \
../queue_array.c 

OBJS += \
./R8_test.o \
./cqueue.o \
./data.o \
./process.o \
./queue_array.o 

C_DEPS += \
./R8_test.d \
./cqueue.d \
./data.d \
./process.d \
./queue_array.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


