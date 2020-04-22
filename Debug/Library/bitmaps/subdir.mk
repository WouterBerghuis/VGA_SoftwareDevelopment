################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Library/bitmaps/smiley_angry.c \
../Library/bitmaps/smiley_happy.c 

OBJS += \
./Library/bitmaps/smiley_angry.o \
./Library/bitmaps/smiley_happy.o 

C_DEPS += \
./Library/bitmaps/smiley_angry.d \
./Library/bitmaps/smiley_happy.d 


# Each subdirectory must supply rules for building sources it contributes
Library/bitmaps/smiley_angry.o: ../Library/bitmaps/smiley_angry.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I"D:/Bestanden/ET Jaar 3/Software Ontwikkeling/Software/swont_ide/Library" -I"D:/Bestanden/ET Jaar 3/Software Ontwikkeling/Software/swont_ide/Library/bitmaps" -I../Drivers/CMSIS/Include -I"D:/Bestanden/ET Jaar 3/Software Ontwikkeling/Software/swont_ide/Core/ub_lib" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Library/bitmaps/smiley_angry.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Library/bitmaps/smiley_happy.o: ../Library/bitmaps/smiley_happy.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I"D:/Bestanden/ET Jaar 3/Software Ontwikkeling/Software/swont_ide/Library" -I"D:/Bestanden/ET Jaar 3/Software Ontwikkeling/Software/swont_ide/Library/bitmaps" -I../Drivers/CMSIS/Include -I"D:/Bestanden/ET Jaar 3/Software Ontwikkeling/Software/swont_ide/Core/ub_lib" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Library/bitmaps/smiley_happy.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

