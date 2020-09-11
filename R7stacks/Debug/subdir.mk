################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../R7_test.c \
../data.c \
../process.c \
../stack_array.c 

OBJS += \
./R7_test.o \
./data.o \
./process.o \
./stack_array.o 

C_DEPS += \
./R7_test.d \
./data.d \
./process.d \
./stack_array.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


