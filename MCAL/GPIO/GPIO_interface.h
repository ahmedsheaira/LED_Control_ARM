/*
    File    : GPIO_interface.h
    Date    : 16/07/2022
    Author  : Ahmed Sheaira
    Version : 1
*/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

// Includes Files
#include "Libraries/bit_math.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

// Global Macros
#define LOW      0
#define HIGH     1
#define INPUT    0
#define OUTPUT   1

// General-Purpose Input/Output Ports
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5

// General-Purpose Input/Output Run Mode Clock Gating Control Register
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5

// General-Purpose Input/Output Pins
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

// GPIO Functions
uint8 get_port(uint8 port);
void GPIO_init(void);
void GPIO_SetPinDir(uint8 port, uint8 indx, uint8 dir);
void GPIO_WritePin(uint8 port, uint8 indx, uint32 val);
uint32 GPIO_ReadPin(uint8 port, uint32 indx);
void GPIO_SetPortDir(uint8 port, uint8 dir);
void GPIO_WritePort(uint8 port, uint32 val);
uint32 GPIO_ReadPort(uint8 port);







#endif