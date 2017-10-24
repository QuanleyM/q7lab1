//Quanley Marieatte - MicroP Lab 1
//
#include <p18f452.h>
#include <stdio.h>
#include <delays.h>
#include "lab1_xlcd.h"

/*Set configuration bits for use with PICKit3*/
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 4000000
//From lab1.asm file
extern char getMapChar(void);
extern unsigned char MapName;
extern unsigned char retVal;
//unsigned char screenAddr;
unsigned char MapIndex = 0;
unsigned char MapNameArr[8];

static unsigned char a;
//int i = 0;

//extern void DelayFor18TCY(void);
//extern void DelayPORXLCD(void);
//extern void DelayXLCD(void);

void main (void){
    //MapNamePtr = &MapName;
	OpenXLCD(FOUR_BIT & LINES_5X7);
    //screenAddr = 0x40;
    for (MapIndex = 0; MapIndex < 8; MapIndex++){
        MapNameArr[MapIndex] = getMapChar();
    }
    while(BusyXLCD());
    

    
    //while (BusyXLCD());
    SetDDRamAddr(0x40);
    WriteCmdXLCD(SHIFT_DISP_LEFT);
    
    while (BusyXLCD());
    WriteCmdXLCD(BLINK_OFF);
    
    while (BusyXLCD());
    //putrsXLCD("Hello");
    putsXLCD(MapNameArr);
    while(1);
}
