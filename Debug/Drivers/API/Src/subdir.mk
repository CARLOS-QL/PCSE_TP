################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/Src/adc_drv.c \
../Drivers/API/Src/i2c_drv.c \
../Drivers/API/Src/lcd_pcf857.c \
../Drivers/API/Src/mcp9700a.c \
../Drivers/API/Src/sensor_fsm.c \
../Drivers/API/Src/uart_drv.c \
../Drivers/API/Src/uart_fsm.c 

OBJS += \
./Drivers/API/Src/adc_drv.o \
./Drivers/API/Src/i2c_drv.o \
./Drivers/API/Src/lcd_pcf857.o \
./Drivers/API/Src/mcp9700a.o \
./Drivers/API/Src/sensor_fsm.o \
./Drivers/API/Src/uart_drv.o \
./Drivers/API/Src/uart_fsm.o 

C_DEPS += \
./Drivers/API/Src/adc_drv.d \
./Drivers/API/Src/i2c_drv.d \
./Drivers/API/Src/lcd_pcf857.d \
./Drivers/API/Src/mcp9700a.d \
./Drivers/API/Src/sensor_fsm.d \
./Drivers/API/Src/uart_drv.d \
./Drivers/API/Src/uart_fsm.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/Src/%.o Drivers/API/Src/%.su Drivers/API/Src/%.cyclo: ../Drivers/API/Src/%.c Drivers/API/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/proyectos/PdM_workspace/TP_MEF_UART_I2C/Drivers/API/Inc" -I"D:/proyectos/PdM_workspace/TP_MEF_UART_I2C/Drivers/API/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-Src

clean-Drivers-2f-API-2f-Src:
	-$(RM) ./Drivers/API/Src/adc_drv.cyclo ./Drivers/API/Src/adc_drv.d ./Drivers/API/Src/adc_drv.o ./Drivers/API/Src/adc_drv.su ./Drivers/API/Src/i2c_drv.cyclo ./Drivers/API/Src/i2c_drv.d ./Drivers/API/Src/i2c_drv.o ./Drivers/API/Src/i2c_drv.su ./Drivers/API/Src/lcd_pcf857.cyclo ./Drivers/API/Src/lcd_pcf857.d ./Drivers/API/Src/lcd_pcf857.o ./Drivers/API/Src/lcd_pcf857.su ./Drivers/API/Src/mcp9700a.cyclo ./Drivers/API/Src/mcp9700a.d ./Drivers/API/Src/mcp9700a.o ./Drivers/API/Src/mcp9700a.su ./Drivers/API/Src/sensor_fsm.cyclo ./Drivers/API/Src/sensor_fsm.d ./Drivers/API/Src/sensor_fsm.o ./Drivers/API/Src/sensor_fsm.su ./Drivers/API/Src/uart_drv.cyclo ./Drivers/API/Src/uart_drv.d ./Drivers/API/Src/uart_drv.o ./Drivers/API/Src/uart_drv.su ./Drivers/API/Src/uart_fsm.cyclo ./Drivers/API/Src/uart_fsm.d ./Drivers/API/Src/uart_fsm.o ./Drivers/API/Src/uart_fsm.su

.PHONY: clean-Drivers-2f-API-2f-Src

