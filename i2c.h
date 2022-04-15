/* 
 * File:   i2c.h
 * Author: me
 *
 * Created on April 15, 2022, 1:16 PM
 */

//#include <xc.h>

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 8000000
#endif 

#ifndef I2C_H
#define	I2C_H

void init_i2c(void);
void i2c_wait(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_repeated_start(void);

#endif

