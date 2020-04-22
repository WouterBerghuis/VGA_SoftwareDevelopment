################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Library/bitmap.c 

OBJS += \
./Library/bitmap.o 

C_DEPS += \
./Library/bitmap.d 


# Each subdirectory must supply rules for building sources it contributes
Library/bitmap.o: ../Library/bitmap.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I"D:/Bestanden/ET Jaar 3/Software Ontwikkeling/Software/swont_ide/Library" -I"D:/Bestanden/ET Jaar 3/Software Ontwikkeling/Software/swont_ide/Library/bitmaps" -I../Drivers/CMSIS/Include -I"D:/Bestanden/ET Jaar 3/Software Ontwikkeling/Software/swont_ide/Core/ub_lib" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Library/bitmap.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

