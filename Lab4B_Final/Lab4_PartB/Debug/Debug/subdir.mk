################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BSTY.cpp \
../Game.cpp \
../LL.cpp \
../NodeT.cpp \
../SNodeL.cpp \
../mainYahtzee.cpp \
../treePuzzle.cpp 

OBJS += \
./BSTY.o \
./Game.o \
./LL.o \
./NodeT.o \
./SNodeL.o \
./mainYahtzee.o \
./treePuzzle.o 

CPP_DEPS += \
./BSTY.d \
./Game.d \
./LL.d \
./NodeT.d \
./SNodeL.d \
./mainYahtzee.d \
./treePuzzle.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


