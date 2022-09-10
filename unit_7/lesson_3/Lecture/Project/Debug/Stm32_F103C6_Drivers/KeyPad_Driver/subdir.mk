################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32_F103C6_Drivers/KeyPad_Driver/KeyPad.c 

OBJS += \
./Stm32_F103C6_Drivers/KeyPad_Driver/KeyPad.o 

C_DEPS += \
./Stm32_F103C6_Drivers/KeyPad_Driver/KeyPad.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32_F103C6_Drivers/KeyPad_Driver/KeyPad.o: ../Stm32_F103C6_Drivers/KeyPad_Driver/KeyPad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"F:/ST/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/KeyPad_Driver" -I"F:/ST/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/LCD_Driver" -I"F:/ST/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/GPIO_Driver" -I"F:/ST/STM32CubeIDE/workspace_1.4.0/Drivers/Stm32_F103C6_Drivers/MCU Device Header" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/KeyPad_Driver/KeyPad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

