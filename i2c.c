/*
 * File:   i2cc.c
 * Author: me
 *
 * Created on April 15, 2022, 1:16 PM
 */


#include <xc.h>
#include "i2c.h"

void init_i2c(void){
    //ANSELC &= ~(0b11 << 3); // RC3 & RC4 are digital
    
    SSPCON1 = 0b00101000;            //SSP Module as Master
    SSPEN = 1;
    
    SSPCON2 = 0;
    SSPADD = (_XTAL_FREQ/(4*400000))-1; //Setting Clock Speed
    SSPSTAT = 0;
    TRISC3 = 1;                   //Setting as input as given in datasheet
    TRISC4 = 1;                   //Setting as input as given in datasheet
}

void i2c_wait(void){
    while (SSPSTATbits.R_nW || SSPCON2bits.SEN || SSPCON2bits.RSEN || SSPCON2bits.RCEN || SSPCON2bits.PEN || SSPCON2bits.ACKEN); // no transmit is in progress, 
}

void i2c_start(void){
    i2c_wait();
    SEN = 1;
}

void i2c_stop(void){
    i2c_wait();
    PEN = 1;
}

void i2c_repeated_start(void){
    i2c_wait();
    RSEN = 1;
}