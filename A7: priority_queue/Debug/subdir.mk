################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../A7_test.c \
../cqueue.c \
../data.c \
../pqueue.c \
../process.c 

OBJS += \
./A7_test.o \
./cqueue.o \
./data.o \
./pqueue.o \
./process.o 

C_DEPS += \
./A7_test.d \
./cqueue.d \
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


