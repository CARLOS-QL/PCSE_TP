/*
 * lcd_pcf857.c
 *
 *  Created on: Apr 23, 2026
 *      Author: Carlos Quispe
 */

#include "lcd_pcf857.h"


static void delayLcd(uint32_t time);


/************************************************************************
 * @brief Inicializa el LCD en modo 4 bits a través del PCF8574.
 * Realiza la secuencia de inicialización requerida por el controlador
 * del LCD (tipo HD44780), enviando comandos en modo 8 bits inicialmente
 * y luego cambiando a modo 4 bits. Configura:
 * - Modo de operación (4 bits, 2 líneas)
 * - Apagado/encendido de display
 * - Limpieza de pantalla
 * - Configuración del cursor
 * Utiliza el expansor PCF8574 para la comunicación I2C.
 ***********************************************************************/

void LCD_I2C_init(void){

	delayLcd(LCD_DELAY_20_MS);
	// Secuencia de inicialización (modo 8 bits)
	PCF8574_write(LCD_8BIT | LCD_ENABLE);  	// EN = 1
	PCF8574_write(LCD_8BIT | 0x00);     	// EN = 0
	delayLcd(LCD_DELAY_5_MS);

	PCF8574_write(LCD_8BIT | LCD_ENABLE);  	// EN = 1
	PCF8574_write(LCD_8BIT | 0x00);
	delayLcd(LCD_DELAY_1_MS);

	PCF8574_write(LCD_8BIT | LCD_ENABLE);	// EN = 1
	PCF8574_write(LCD_8BIT | 0x00);
	delayLcd(LCD_DELAY_1_MS);

	// Cambio a modo 4 bits
	PCF8574_write(LCD_4BIT | LCD_ENABLE);	// EN = 1
	PCF8574_write(LCD_4BIT | 0x00);
	delayLcd(LCD_DELAY_1_MS);

	// Configuración del LCD
	LCD_I2C_cmd(0b00101000);    // Funcion Set: 4bit, 2lineas, 5x7
	LCD_I2C_cmd(0b00001000);    // Display on: lcd off, cursor off, sin parpadeo
	LCD_I2C_cmd(LCD_CLEAR);     // Display clear
	LCD_I2C_cmd(0b00000110);    // Entry mod: icrementa addr, sin desplazamiento
	LCD_I2C_cmd(0b00001100);    // Display on: lcd on, cursor off, sin parpadeo

}

/*******************************************************************************
 * @brief Envía un carácter (dato) al LCD.
 * Similar a LCD_I2C_cmd, pero con RS=1 para indicar que se trata de datos.
 * Permite escribir caracteres ASCII en el display.
 * @param lcdData Carácter a enviar.
 ******************************************************************************/

void LCD_I2C_cmd(uint8_t lcdCmd)
{

	uint8_t highNibble = (lcdCmd & 0xf0);
	uint8_t lowNibble = ((lcdCmd << 4) & 0xf0);

	PCF8574_write(highNibble | 0b00001100);        //en=1, rs=0
	PCF8574_write(highNibble | 0b00001000);        //en=0, rs=0

	PCF8574_write(lowNibble | 0b00001100);        //en=1, rs=0
	PCF8574_write(lowNibble | 0b00001000);        //en=0, rs=0
	delayLcd(LCD_DELAY_2_MS);
}

/*******************************************************************************
 * @brief Envía un carácter (dato) al LCD.
 * Similar a LCD_I2C_cmd, pero con RS=1 para indicar que se trata de datos.
 * Permite escribir caracteres ASCII en el display.
 * @param lcdData Carácter a enviar.
 ******************************************************************************/

void LCD_I2C_char(uint8_t lcdData){

	uint8_t highNibble = (lcdData & 0xf0);
	uint8_t lowNibble = ((lcdData<<4) & 0xf0);

	PCF8574_write(highNibble | 0b00001101);         //en=1, rs=1
	PCF8574_write(highNibble | 0b00001001);         //en=0, rs=1

	PCF8574_write(lowNibble | 0b00001101);         //en=1, rs=1
	PCF8574_write(lowNibble | 0b00001001);         //en=0, rs=1
	delayLcd(LCD_DELAY_1_MS);                         //Tiempo 55us en real
}

/*******************************************************************************
 * @brief Envía una cadena de caracteres al LCD.
 * Recorre la cadena hasta encontrar el carácter nulo ('\0'),
 * enviando cada carácter mediante la función LCD_I2C_char.
 * @param lcdText Puntero a la cadena de texto.
 ******************************************************************************/

void LCD_I2C_write_text(uint8_t *lcdText){

	if (lcdText == NULL)
		return;
	while (*lcdText) LCD_I2C_char(*lcdText++);
}

/*******************************************************************************
 * @brief  DelayLcd demora bloqueante para el uso del LCD
 * @param  valor de la demora a realizar en ms
 * @return void
 ******************************************************************************/

static void delayLcd(uint32_t time){
	  HAL_Delay(time);
}









