/*
 * Dio.c
 *
 *  Created on: Dec 22, 2016
 *      Author: Sragaai
 */
/**************************************************** INCLUSIONS *****************************************************/
#include "Std_Types.h"
#include "Macros.h"
#include "Dio.h"
/*********************************************************************************************************************/

/* Registers Definitions                                                     */
#define PORTA *((volatile u8*)0x3B)
#define DDRA  *((volatile u8*)0x3A)
#define PINA  *((volatile u8*)0x39)
#define PORTB *((volatile u8*)0x38)
#define DDRB  *((volatile u8*)0x37)
#define PINB  *((volatile u8*)0x36)
#define PORTC *((volatile u8*)0x35)
#define DDRC  *((volatile u8*)0x34)
#define PINC  *((volatile u8*)0x33)
#define PORTD *((volatile u8*)0x32)
#define DDRD  *((volatile u8*)0x31)
#define PIND  *((volatile u8*)0x30)



/* Interface to set the Output value of the pin                              */
void Dio_vidSetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8ValueCpy)
{

  switch (u8PortNumberCpy)
  {
  case 0:
    if (u8ValueCpy == 1)
    {
      SET_BIT(PORTA, u8PinNumberCpy);
    } else
    {
      CLEAR_BIT(PORTA, u8PinNumberCpy);
    }
    break;

  case 1:
    if (u8ValueCpy == 1)
    {
      SET_BIT(PORTB, u8PinNumberCpy);
    } else
    {
      CLEAR_BIT(PORTB, u8PinNumberCpy);
    }
    break;

  case 2:
    if (u8ValueCpy == 1)
    {
      SET_BIT(PORTC, u8PinNumberCpy);
    } else
    {
      CLEAR_BIT(PORTC, u8PinNumberCpy);
    }
    break;

  case 3:
    if (u8ValueCpy == 1)
    {
      SET_BIT(PORTD, u8PinNumberCpy);
    } else
    {
      CLEAR_BIT(PORTD, u8PinNumberCpy);
    }
    break;

  default:
    break;
  }

}

/* Interface to get the value of the input pin                               */
u8 Dio_u8GetPinValue(u8 u8PortNumberCpy, u8 u8PinNumberCpy)
{

  u8 Loc_u8PinValue = 0;
  switch (u8PortNumberCpy)
  {
  case 0:

    Loc_u8PinValue = GET_BIT(PINA, u8PinNumberCpy);
    break;

  case 1:

    Loc_u8PinValue = GET_BIT(PINB, u8PinNumberCpy);
    break;

  case 2:

    Loc_u8PinValue = GET_BIT(PINC, u8PinNumberCpy);
    break;

  case 3:

    Loc_u8PinValue = GET_BIT(PIND, u8PinNumberCpy);
    break;

  default:
    break;

  }
  return Loc_u8PinValue;
}

void Dio_vidSetPinDirection(u8 u8PortNumberCpy, u8 u8PinNumberCpy, u8 u8DirectionCpy)
{

  switch (u8PortNumberCpy)
  {
  case 0:
    if (u8DirectionCpy == 1)
    {
      SET_BIT(DDRA, u8PinNumberCpy);
    } else
    {
      CLEAR_BIT(DDRA, u8PinNumberCpy);
    }
    break;
  case 1:
    if (u8DirectionCpy == 1)
    {
      SET_BIT(DDRB, u8PinNumberCpy);
    } else
    {
      CLEAR_BIT(DDRB, u8PinNumberCpy);
    }
    break;

  case 2:
    if (u8DirectionCpy == 1)
    {
      SET_BIT(DDRC, u8PinNumberCpy);
    } else
    {
      CLEAR_BIT(DDRC, u8PinNumberCpy);
    }
    break;

  case 3:
    if (u8DirectionCpy == 1)
    {
      SET_BIT(DDRD, u8PinNumberCpy);
    } else
    {
      CLEAR_BIT(DDRD, u8PinNumberCpy);
    }
    break;

  default:
    break;

  }

}