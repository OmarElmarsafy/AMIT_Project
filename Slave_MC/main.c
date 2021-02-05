#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "DIO_interface.h"
#include "Compiler.h"
#include "AVR_UART_REG.h"
#include "UART_interface.h"
#include "AVR_SPI_REG.h"
#include "SPI_interface.h"
#include "LED_interfce.h"

int main(){
	MCAL_SPI_SlaveInit();
	HAL_LEDInit(DIO_PORTC,DIO_PIN_2);
	HAL_LEDInit(DIO_PORTC,DIO_PIN_7);
	uint8_t recieve_char;
	uint8_t send = NULL;
	while(1){
		MCAL_SPI_Slave_DataBusyWait(send,&recieve_char);
		if(recieve_char == '0'){
			HAL_LEDSetValue(DIO_PORTC,DIO_PIN_2,DIO_LOW);
			HAL_LEDSetValue(DIO_PORTC,DIO_PIN_7,DIO_LOW);

		}
		else if (recieve_char == '1'){
			HAL_LEDSetValue(DIO_PORTC,DIO_PIN_2,DIO_HIGH);
			HAL_LEDSetValue(DIO_PORTC,DIO_PIN_7,DIO_HIGH);
		}
	}
}
