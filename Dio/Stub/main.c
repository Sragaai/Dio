/*
 * main.c
 *
 *  Created on: Dec 27, 2016
 *      Author: Sragaai
 */
#include "Std_Types.h"
#include "Macros.h"
#include "Dio.h"

int main(void)
{

  Dio_vidSetPinDirection(DIO_PORTA, 0, 1);
  Dio_vidSetPinDirection(DIO_PORTA, 1, 1);
  Dio_vidSetPinDirection(DIO_PORTA, 2, 1);
  Dio_vidSetPinDirection(DIO_PORTA, 3, 1);
  Dio_vidSetPinDirection(DIO_PORTA, 4, 1);
  Dio_vidSetPinDirection(DIO_PORTA, 5, 1);
  Dio_vidSetPinDirection(DIO_PORTA, 6, 1);
  Dio_vidSetPinDirection(DIO_PORTA, 7, 1);

  Dio_vidSetPinDirection(DIO_PORTD, 0, 0);
  Dio_vidSetPinDirection(DIO_PORTD, 1, 0);
  Dio_vidSetPinDirection(DIO_PORTD, 2, 0);
  Dio_vidSetPinDirection(DIO_PORTD, 3, 0);
  Dio_vidSetPinDirection(DIO_PORTD, 4, 0);
  Dio_vidSetPinDirection(DIO_PORTD, 5, 0);
  Dio_vidSetPinDirection(DIO_PORTD, 6, 0);
  Dio_vidSetPinDirection(DIO_PORTD, 7, 0);

  Dio_vidSetPinValue(DIO_PORTD, 0, 1);
  Dio_vidSetPinValue(DIO_PORTD, 1, 1);
  Dio_vidSetPinValue(DIO_PORTD, 2, 1);
  Dio_vidSetPinValue(DIO_PORTD, 3, 1);
  Dio_vidSetPinValue(DIO_PORTD, 4, 1);
  Dio_vidSetPinValue(DIO_PORTD, 5, 1);
  Dio_vidSetPinValue(DIO_PORTD, 6, 1);
  Dio_vidSetPinValue(DIO_PORTD, 7, 1);

  while (1)
  {

    if (Dio_u8GetPinValue(DIO_PORTD, 0))
    {
      Dio_vidSetPinValue(DIO_PORTA, 0, 1);
      Dio_vidSetPinValue(DIO_PORTA, 1, 1);
      Dio_vidSetPinValue(DIO_PORTA, 2, 1);
      Dio_vidSetPinValue(DIO_PORTA, 3, 1);
      Dio_vidSetPinValue(DIO_PORTA, 4, 1);
      Dio_vidSetPinValue(DIO_PORTA, 5, 1);
      Dio_vidSetPinValue(DIO_PORTA, 6, 1);
      Dio_vidSetPinValue(DIO_PORTA, 7, 1);
    } else
    {
      Dio_vidSetPinValue(DIO_PORTA, 0, 0);
      Dio_vidSetPinValue(DIO_PORTA, 1, 0);
      Dio_vidSetPinValue(DIO_PORTA, 2, 0);
      Dio_vidSetPinValue(DIO_PORTA, 3, 0);
      Dio_vidSetPinValue(DIO_PORTA, 4, 0);
      Dio_vidSetPinValue(DIO_PORTA, 5, 0);
      Dio_vidSetPinValue(DIO_PORTA, 6, 0);
      Dio_vidSetPinValue(DIO_PORTA, 7, 0);
    }

  }
}
