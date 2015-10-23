#include "stm32f10x.h"

// permet de configurer une broche d'un port en output push-pull
char Port_IO_Init_Output(GPIO_TypeDef * Port, u8 Broche);

// permet de configurer une broche d'un port en input floating
char Port_IO_Init_Input(GPIO_TypeDef * Port, u8  Broche);

// permet de mettre � 1 une broche d'un port
void Port_IO_Set(GPIO_TypeDef * Port, u8 Broche);

// permet de mettre � 0 une broche d'un port
void Port_IO_Reset(GPIO_TypeDef * Port, u8 Broche);

// inverse l'�tat d'une broche
void Port_IO_Blink(GPIO_TypeDef * Port, u8 Broche);

// permet de lire l'�tat d'une broche d'un port
unsigned int Port_IO_Read(GPIO_TypeDef * Port, u8 Broche);
