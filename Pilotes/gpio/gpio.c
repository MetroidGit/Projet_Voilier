#include "gpio.h"

char Port_IO_Init_Output(GPIO_TypeDef * Port, u8 Broche) {
	char erreur = 0;
	if (Broche < 7) 
		Port->CRL = (Port->CRL & ~(0x0F << Broche*4)) | (0x01 << Broche*4);
	else if (Broche < 16)
		Port->CRH = (Port->CRH & ~(0x0F << (Broche-8)*4)) | (0x01 << (Broche-8)*4);
	else
		erreur = 1;
	return erreur;
}

char Port_IO_Init_Input(GPIO_TypeDef * Port, u8  Broche) {
	char erreur = 0;
	if (Broche < 7) 
		Port->CRL &= ~(0x0F << Broche*4) | (0x04 << Broche*4);
	else if (Broche < 16)
		Port->CRH &= ~(0x0F << (Broche-8)*4) | (0x04 << (Broche-8)*4);
	else
		erreur = 1;
	return erreur;
}

void Port_IO_Set(GPIO_TypeDef * Port, u8 Broche) {
	Port->BSRR = (0x01 << Broche);
}

void Port_IO_Reset(GPIO_TypeDef * Port, u8 Broche) {
	Port->BRR = (0x01 << Broche);
}

void Port_IO_Blink(GPIO_TypeDef * Port, u8 Broche) {
	Port->ODR ^= (0x01 << Broche);
}

unsigned int Port_IO_Read(GPIO_TypeDef * Port, u8 Broche) {
	return (Port->IDR & (0x01 << Broche));
}
