#include <p18f452.h>
#include <stdio.h>
#include "lab1_xlcd.h"
#include <delays.h>

extern void DelayFor18TCY(void){
    Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();
    Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();
    Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();Delay1TCY();
}

extern void DelayPORXLCD(void){
    Delay1KTCYx(15);
}
extern void DelayXLCD(void){
    Delay1KTCYx(5);
}
