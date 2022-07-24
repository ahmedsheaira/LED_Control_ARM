/*
    File    : GPIO_private.h
    Date    : 16/07/2022
    Author  : Ahmed Sheaira
    Version : 1
*/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

// Including Files
#include "Libraries/std_types.h"

// System Control Registers
#define SYS_CTRL_BASE   ((uint32)(0x400FE000))
#define RCGCGPIO        (*((volatile uint32*)(SYS_CTRL_BASE+0x608)))

// General-Purpose Input/Putput Port Base Registers
#define GPIO_A_BASE  ((uint32)(0x40004000))
#define GPIO_B_BASE  ((uint32)(0x40005000))
#define GPIO_C_BASE  ((uint32)(0x40006000))
#define GPIO_D_BASE  ((uint32)(0x40007000))
#define GPIO_E_BASE  ((uint32)(0x40024000))
#define GPIO_F_BASE  ((uint32)(0x40025000))

// General-Purpose Input/Putput Registers
#define GPIODATA(base)            (*((volatile uint32*)(base+0x000)))
#define GPIODIR(base)             (*((volatile uint32*)(base+0x400)))
#define GPIOIS(base)              (*((volatile uint32*)(base+0x404)))
#define GPIOIBE(base)             (*((volatile uint32*)(base+0x408)))
#define GPIOIEV(base)             (*((volatile uint32*)(base+0x40C)))
#define GPIOIM(base)              (*((volatile uint32*)(base+0x410)))
#define GPIORIS(base)             (*((volatile uint32*)(base+0x414)))
#define GPIOMIS(base)             (*((volatile uint32*)(base+0x418)))
#define GPIOICR(base)             (*((volatile uint32*)(base+0x41C)))
#define GPIOAFSEL(base)           (*((volatile uint32*)(base+0x420)))
#define GPIODR2R(base)            (*((volatile uint32*)(base+0x500)))
#define GPIODR4R(base)            (*((volatile uint32*)(base+0x504)))
#define GPIODR8R(base)            (*((volatile uint32*)(base+0x508)))
#define GPIOODR(base)             (*((volatile uint32*)(base+0x50C)))
#define GPIOPUR(base)             (*((volatile uint32*)(base+0x510)))
#define GPIOPDR(base)             (*((volatile uint32*)(base+0x514)))
#define GPIOSLR(base)             (*((volatile uint32*)(base+0x518)))
#define GPIODEN(base)             (*((volatile uint32*)(base+0x51C)))
#define GPIOLOCK(base)            (*((volatile uint32*)(base+0x520)))
#define GPIOCR(base)              (*((volatile uint32*)(base+0x524)))
#define GPIOAMSEL(base)           (*((volatile uint32*)(base+0x528)))
#define GPIOPCTL(base)            (*((volatile uint32*)(base+0x52C)))
#define GPIOADCCTL(base)          (*((volatile uint32*)(base+0x530)))
#define GPIODMACTL(base)          (*((volatile uint32*)(base+0x534)))
#define GPIOPERIPHID4(base)       (*((volatile uint32*)(base+0xFD0)))
#define GPIOPERIPHID5(base)       (*((volatile uint32*)(base+0xFD4)))
#define GPIOPERIPHID6(base)       (*((volatile uint32*)(base+0xFD8)))
#define GPIOPERIPHID7(base)       (*((volatile uint32*)(base+0xFDC)))
#define GPIOPERIPHID0(base)       (*((volatile uint32*)(base+0xFE0)))
#define GPIOPERIPHID1(base)       (*((volatile uint32*)(base+0xFE4)))
#define GPIOPERIPHID2(base)       (*((volatile uint32*)(base+0xFE8)))
#define GPIOPERIPHID3(base)       (*((volatile uint32*)(base+0xFEC)))
#define GPIOPCELLID0(base)        (*((volatile uint32*)(base+0xFF0)))
#define GPIOPCELLID1(base)        (*((volatile uint32*)(base+0xFF4)))
#define GPIOPCELLID2(base)        (*((volatile uint32*)(base+0xFF8)))
#define GPIOPCELLID3(base)        (*((volatile uint32*)(base+0xFFC)))

#endif



