# 📡 TP_MEF_UART_I2C - STM32F446RE

## 📌 Descripción

Este proyecto implementa un sistema embebido basado en el microcontrolador **STM32F446RE**, enfocado en el diseño e implementación de **protocolos de comunicación en sistemas embebidos**.

El sistema integra dos interfaces principales:

- 📡 **UART** → para comunicación con el usuario (interfaz de comandos)
- 🔌 **I2C** → para comunicación con periféricos (LCD mediante PCF8574)

Adicionalmente, se implementa la adquisición de datos mediante ADC utilizando el sensor **MCP9700A**, permitiendo validar el flujo completo de información desde la adquisición hasta la transmisión y visualización.

---

## 🎯 Objetivo del proyecto

Diseñar e implementar una arquitectura modular que permita:

- La comunicación bidireccional mediante UART usando un protocolo basado en comandos
- La comunicación con dispositivos periféricos mediante el bus I2C
- La integración de ambos canales de comunicación en un sistema embebido no bloqueante
- La validación de datos adquiridos desde sensores y su transmisión al usuario

---

## 📡 Protocolos implementados

### 🔹 UART (Interfaz de usuario)

Se implementa un protocolo de comunicación basado en comandos ASCII, gestionado mediante una **máquina de estados (MEF)**.

Características:

- Recepción no bloqueante
- Buffer de entrada
- Parsing de comandos
- Respuesta en tiempo real
- Configuración dinámica del sistema

Ejemplos de comandos:

| Comando        | Descripción                          |
|---------------|--------------------------------------|
| `GET TEMP`     | Solicita la temperatura actual       |
| `get SP`       | Solicita el setpoint                |
| `SET HYST`     | Solicita la histéresis              |
| `STATUS`       | Devuelve el estado del sistema       |
| `HELP`         | Lista de comandos disponibles        |

---

### 🔹 I2C (Interfaz con periféricos)

Se utiliza el bus **I2C** para la comunicación con un display LCD a través del expansor **PCF8574**.

Características:

- Comunicación maestro-esclavo
- Dirección de dispositivo configurable
- Abstracción mediante driver dedicado
- Envío de comandos y datos al LCD en modo 4 bits

---

## 🧠 Arquitectura del sistema

El diseño sigue una arquitectura modular basada en **capas de abstracción**:

### 🔧 Drivers (capa de bajo nivel)
- `uart_drv`
- `i2c_drv`
- `adc_drv`

### 🧩 Módulos funcionales
- `lcd_pcf857`
- `mcp9700a`

### 🔄 Lógica de aplicación (MEF)
- `uart_fsm`
- `sensor_fsm`

Esto permite desacoplar la lógica de comunicación del hardware, facilitando la escalabilidad del sistema.

---

## 🔄 Flujo de datos
