#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "DIO_interface.h"
#include "Compiler.h"
#include "AVR_UART_REG.h"
#include "UART_interface.h"
#include "AVR_SPI_REG.h"
#include "SPI_interface.h"

int main(){
		str_UartConfg_t obj = {9600,UART_8_BIT_MODE,UART_POLLING};
		MCAL_SPI_MasterInit(SPI_MASTER_FREQUENCY_64);
		MCAL_UART_init(&obj);
		MCAL_DIO_u8SetPinDir(DIO_PORTC,DIO_PIN_2,DIO_OUTPUT);
		MCAL_DIO_u8SetPinDir(DIO_PORTC,DIO_PIN_7,DIO_OUTPUT);
		uint8_t arr[] = "Please Enter a Button:";
		uint8_t i = 0;
		while (arr[i] != '\0'){
			MCAL_UART_sendByteBusyWait(arr[i]);
			i++;
		}
		uint8_t chr;
		uint8_t recieve;
		while(1)
		{
			MCAL_UART_recieveByteBusyWait(&chr);
			if (chr == '0')
			{
				MCAL_DIO_u8SetPinValue(DIO_PORTC,DIO_PIN_2,DIO_LOW);//to check that the program went through this condition
				MCAL_DIO_u8SetPinValue(DIO_PORTC,DIO_PIN_7,DIO_LOW);
				MCAL_SPI_Master_DataBusyWait(chr,&recieve);
			}
			else if (chr =='1')
			{
				MCAL_DIO_u8SetPinValue(DIO_PORTC,DIO_PIN_2,DIO_HIGH);//to check that the program went through this condition
				MCAL_DIO_u8SetPinValue(DIO_PORTC,DIO_PIN_7,DIO_HIGH);
				MCAL_SPI_Master_DataBusyWait(chr,&recieve);
			}
		}
}
