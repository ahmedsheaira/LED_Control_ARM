/*
    File    : GPIO.c
    Date    : 16/07/2022
    Author  : Ahmed Sheaira
    Version : 2
*/

#include "MCAL/GPIO/GPIO_interface.h"

volatile uint32* GPIO_Port[6] = {GPIO_A_BASE, GPIO_B_BASE, GPIO_C_BASE, GPIO_D_BASE, GPIO_E_BASE};

uint8 get_port(uint8 port)
{
    switch (port)
    {
    case PORTA:
        return 0;
        break;
    case PORTB:
        return 1;
        break;
    case PORTC:
        return 2;
        break;
    case PORTD:
        return 3;
        break;
    case PORTE:
        return 4;
        break;
    case PORTF:
        return 5;
        break;
    }
    return -1;
}

void GPIO_init(void)
{
    // Enable the clock for all ports
    SET_PORT(RCGCGPIO);
    
    // Set the Direction of all Ports as Input
    CLEAR_PORT(GPIODIR(*GPIO_Port[get_port(PORTA)]));
    CLEAR_PORT(GPIODIR(*GPIO_Port[get_port(PORTB)]));
    CLEAR_PORT(GPIODIR(*GPIO_Port[get_port(PORTC)]));
    CLEAR_PORT(GPIODIR(*GPIO_Port[get_port(PORTD)]));
    CLEAR_PORT(GPIODIR(*GPIO_Port[get_port(PORTE)]));
    CLEAR_PORT(GPIODIR(*GPIO_Port[get_port(PORTF)]));
    
    // Set all ports as GPIO without any alternate function
    CLEAR_PORT(GPIOAFSEL(*GPIO_Port[get_port(PORTA)]));
    CLEAR_PORT(GPIOAFSEL(*GPIO_Port[get_port(PORTB)]));
    CLEAR_PORT(GPIOAFSEL(*GPIO_Port[get_port(PORTC)]));
    CLEAR_PORT(GPIOAFSEL(*GPIO_Port[get_port(PORTD)]));
    CLEAR_PORT(GPIOAFSEL(*GPIO_Port[get_port(PORTE)]));
    CLEAR_PORT(GPIOAFSEL(*GPIO_Port[get_port(PORTF)]));

    // Set the port control 
    CLEAR_PORT(GPIOPCTL(*GPIO_Port[get_port(PORTA)]));
    CLEAR_PORT(GPIOPCTL(*GPIO_Port[get_port(PORTB)]));
    CLEAR_PORT(GPIOPCTL(*GPIO_Port[get_port(PORTC)]));
    CLEAR_PORT(GPIOPCTL(*GPIO_Port[get_port(PORTD)]));
    CLEAR_PORT(GPIOPCTL(*GPIO_Port[get_port(PORTE)]));
    CLEAR_PORT(GPIOPCTL(*GPIO_Port[get_port(PORTF)]));

    // Set the output current for all pins of ports
    #if ((OUTPUTPIN == R2) && (OUTPUTPORT == PORTA))
        SET_PORT(GPIODR2R(*GPIO_Port[get_port(PORTA)]));
    #elif ((OUTPUTPIN == R2) && (OUTPUTPORT == PORTB))
        SET_PORT(GPIODR2R(*GPIO_Port[get_port(PORTB)]));
    #elif ((OUTPUTPIN == R2) && (OUTPUTPORT == PORTC))
        SET_PORT(GPIODR2R(*GPIO_Port[get_port(PORTC)]));
    #elif ((OUTPUTPIN == R2) && (OUTPUTPORT == PORTD))
        SET_PORT(GPIODR2R(*GPIO_Port[get_port(PORTD)]));
    #elif ((OUTPUTPIN == R2) && (OUTPUTPORT == PORTE))
        SET_PORT(GPIODR2R(*GPIO_Port[get_port(PORTE)]));
    #elif ((OUTPUTPIN == R2) && (OUTPUTPORT == PORTF))
        SET_PORT(GPIODR2R(*GPIO_Port[get_port(PORTF)]));
    #elif ((OUTPUTPIN == R4) && (OUTPUTPORT == PORTA))
        CLEAR_PORT(GPIODR2R(*GPIO_Port[get_port(PORTA)]));
        SET_PORT(GPIODR4R(*GPIO_Port[get_port(PORTA)]));
    #elif ((OUTPUTPIN == R4) && (OUTPUTPORT == PORTB))
        CLEAR_PORT(GPIODR2R(*GPIO_Port[get_port(PORTB)]));
        SET_PORT(GPIODR4R(*GPIO_Port[get_port(PORTB)]));
    #elif ((OUTPUTPIN == R4) && (OUTPUTPORT == PORTC))
        CLEAR_PORT(GPIODR2R(*GPIO_Port[get_port(PORTC)]));
        SET_PORT(GPIODR4R(*GPIO_Port[get_port(PORTC)]));
    #elif ((OUTPUTPIN == R4) && (OUTPUTPORT == PORTD))
        CLEAR_PORT(GPIODR2R(*GPIO_Port[get_port(PORTD)]));
        SET_PORT(GPIODR4R(*GPIO_Port[get_port(PORTD)]));
    #elif ((OUTPUTPIN == R4) && (OUTPUTPORT == PORTE))
        CLEAR_PORT(GPIODR2R(*GPIO_Port[get_port(PORTE)]));
        SET_PORT(GPIODR4R(*GPIO_Port[get_port(PORTE)]));
    #elif ((OUTPUTPIN == R4) && (OUTPUTPORT == PORTF))
        CLEAR_PORT(GPIODR2R(*GPIO_Port[get_port(PORTF)]));
        SET_PORT(GPIODR4R(*GPIO_Port[get_port(PORTF)]));
    #elif ((OUTPUTPIN == R8) && (OUTPUTPORT == PORTA))
        CLEAR_PORT(GPIODR2R(*GPIO_Port[get_port(PORTA)]));
        SET_PORT(GPIODR8R(*GPIO_Port[get_port(PORTA)]));
    #elif ((OUTPUTPIN == R8) && (OUTPUTPORT == PORTB))
        CLEAR_PORT(GPIODR2R(*GPIO_Port[get_port(PORTB)]));
        SET_PORT(GPIODR8R(*GPIO_Port[get_port(PORTB)]));
    #elif ((OUTPUTPIN == R8) && (OUTPUTPORT == PORTC))
        CLEAR_PORT(GPIODR2R(*GPIO_Port[get_port(PORTC)]));
        SET_PORT(GPIODR8R(*GPIO_Port[get_port(PORTC)]));
    #elif ((OUTPUTPIN == R8) && (OUTPUTPORT == PORTD))
        CLEAR_PORT(GPIODR2R(*GPIO_Port[get_port(PORTD)]));
        SET_PORT(GPIODR8R(*GPIO_Port[get_port(PORTD)]));
    #elif ((OUTPUTPIN == R8) && (OUTPUTPORT == PORTE))
        CLEAR_PORT(GPIODR2R(*GPIO_Port[get_port(PORTE)]));
        SET_PORT(GPIODR8R(*GPIO_Port[get_port(PORTE)]));
    #elif ((OUTPUTPIN == R8) && (OUTPUTPORT == PORTF))
        CLEAR_PORT(GPIODR2R(*GPIO_Port[get_port(PORTF)]));
        SET_PORT(GPIODR8R(*GPIO_Port[get_port(PORTF)]));
    #endif

    // Set all ports as digital Input/Output
    SET_PORT(GPIODEN(GPIO_Port[get_port(PORTA)]));
    CLEAR_PORT(GPIOAMSEL(*GPIO_Port[get_port(PORTA)]));
    SET_PORT(GPIODEN(GPIO_Port[get_port(PORTB)]));
    CLEAR_PORT(GPIOAMSEL(*GPIO_Port[get_port(PORTB)]));
    SET_PORT(GPIODEN(GPIO_Port[get_port(PORTC)]));
    CLEAR_PORT(GPIOAMSEL(*GPIO_Port[get_port(PORTC)]));
    SET_PORT(GPIODEN(GPIO_Port[get_port(PORTD)]));
    CLEAR_PORT(GPIOAMSEL(*GPIO_Port[get_port(PORTD)]));
    SET_PORT(GPIODEN(GPIO_Port[get_port(PORTE)]));
    CLEAR_PORT(GPIOAMSEL(*GPIO_Port[get_port(PORTE)]));
    SET_PORT(GPIODEN(GPIO_Port[get_port(PORTF)]));
    CLEAR_PORT(GPIOAMSEL(*GPIO_Port[get_port(PORTF)]));
}

void GPIO_SetPinDir(uint8 port, uint8 indx, uint8 dir)
{
    #if (port == PORTE)
        #if (indx > PIN5)
            #error ("Invaled Pin Number!")
        #endif
    #elif (port == PORTF)
        #if (indx > PIN4)
            #error ("Invaled Pin Number!")
        #endif
    #else
       switch (dir)
        {
        case INPUT:
            CLEAR_BIT(GPIODIR(*GPIO_Port[get_port(port)]), indx);
            break;
        case OUTPUT:
            SET_BIT(GPIODIR(*GPIO_Port[get_port(port)]), indx);
            break;
        } 
    #endif
}

void GPIO_WritePin(uint8 port, uint8 indx, uint32 val)
{
    if ((((port != 'E') || (port != 'e')) && (indx > 5)) || (((port != 'F') || (port != 'f')) && (indx > 4)))
    {
        switch (val)
        {
        case LOW:
            CLEAR_BIT(GPIODATA(*GPIO_Port[get_port(port)]), indx);
            break;
        case HIGH:
            SET_BIT(GPIODATA(*GPIO_Port[get_port(port)]), indx);
            break;
        }
    }
    else
    {
    }
}

uint32 GPIO_ReadPin(uint8 port, uint32 indx)
{
    if ((((port != 'E') || (port != 'e')) && (indx > 5)) || (((port != 'F') || (port != 'f')) && (indx > 4)))
    {
        return (GPIODATA(*GPIO_Port[get_port(port)]) & (1<<indx));
    }
    else
    {
        return -1;
    }
}

void GPIO_SetPortDir(uint8 port, uint8 dir)
{
    switch (dir)
    {
    case INPUT:
        CLEAR_PORT(GPIODIR(*GPIO_Port[get_port(port)]));
        break;
    case OUTPUT:
        SET_PORT(GPIODIR(*GPIO_Port[get_port(port)]));
        break;
    }
}

void GPIO_WritePort(uint8 port, uint32 val)
{
    GPIODATA(*GPIO_Port[get_port(port)]) = val;
}

uint32 GPIO_ReadPort(uint8 port)
{
    return (GPIODATA(*GPIO_Port[get_port(port)]));
}

