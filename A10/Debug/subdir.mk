################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../A10_test.c \
../data.c \
../heap.c \
../queue_array.c \
../stack_array.c 

OBJS += \
./A10_test.o \
./data.o \
./heap.o \
./queue_array.o \
./stack_array.o 

C_DEPS += \
./A10_test.d \
./data.d \
./heap.d \
./queue_array.d \
./stack_array.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


