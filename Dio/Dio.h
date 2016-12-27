/*
 * Dio.h
 *
 *  Created on: Dec 27, 2016
 *      Author: Sragaai
 */

#ifndef DIO_H_
#define DIO_H_

/*************************** External Definitions ****************************/
/* Output Ports                                                              */
#define DIO_PORTA        0
#define DIO_PORTB        1
#define DIO_PORTC        2
#define DIO_PORTD        3

/*****************************************************************************/

/*****************************************************************************/
/****************************** Dio Interfaces *******************************/

/* Interface to set the Output value of the pin                              */
void Dio_vidSetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8ValueCpy);

/* Interface to get the value of the input pin                               */
u8 Dio_u8GetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy);

void Dio_vidSetPinDirection(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8DirectionCpy);

/*****************************************************************************/
#endif /* DIO_H_ */
