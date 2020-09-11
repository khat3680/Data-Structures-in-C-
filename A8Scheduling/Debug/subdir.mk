################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../A8.c \
../A8_test.c \
../data.c \
../pqueue.c \
../process.c 

OBJS += \
./A8.o \
./A8_test.o \
./data.o \
./pqueue.o \
./process.o 

C_DEPS += \
./A8.d \
./A8_test.d \
./data.d \
./pqueue.d \
./process.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


