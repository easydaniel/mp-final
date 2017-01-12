################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/stm32l4xx_hal_msp.c \
../Src/stm32l4xx_it.c \
../Src/usb_host.c \
../Src/usbh_conf.c 

OBJS += \
./Src/main.o \
./Src/stm32l4xx_hal_msp.o \
./Src/stm32l4xx_it.o \
./Src/usb_host.o \
./Src/usbh_conf.o 

C_DEPS += \
./Src/main.d \
./Src/stm32l4xx_hal_msp.d \
./Src/stm32l4xx_it.d \
./Src/usb_host.d \
./Src/usbh_conf.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32L476xx -I"/Users/kevchentw/Documents/workspace/ttttt/Inc" -I"/Users/kevchentw/Documents/workspace/ttttt/Drivers/STM32L4xx_HAL_Driver/Inc" -I"/Users/kevchentw/Documents/workspace/ttttt/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"/Users/kevchentw/Documents/workspace/ttttt/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"/Users/kevchentw/Documents/workspace/ttttt/Middlewares/ST/STM32_USB_Host_Library/Class/HID/Inc" -I"/Users/kevchentw/Documents/workspace/ttttt/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"/Users/kevchentw/Documents/workspace/ttttt/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


