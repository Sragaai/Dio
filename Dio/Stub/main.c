/*
 * main.c
 *
 *  Created on: Dec 27, 2016
 *      Author: Sragaai
 */
#include "Std_Types.h"
#include "Macros.h"
#include "util/delay.h"
#include "Dio.h"

int main(void)
{

  /* Local Loop index                                                                                                */
  u8 LOC_u8Index;

  /* Variable to choose the working application                                                                      */
  u8 LOC_u8Choice;

  /* Application Choice                                                                                              */
  LOC_u8Choice = 3;

  /* PORT Initialization                                                                                             */
  for (LOC_u8Index = 0; LOC_u8Index < 8; LOC_u8Index++)
  {
    /* Setting PORTA as OUTPUT                                                                                       */
    Dio_vidSetPinDirection(DIO_PORTA, LOC_u8Index, 1);

    /* Setting PORTD as INPUT                                                                                        */
    Dio_vidSetPinDirection(DIO_PORTD, LOC_u8Index, 0);

    /* Activate Pull UP Resistance for PORTD                                                                         */
    Dio_vidSetPinValue(DIO_PORTD, LOC_u8Index, 1);
  }

  while (1)
  {

    /********************************** Dip Switch Application *******************************************************/
    if (LOC_u8Choice == 0)
    {
      /* Loop on all pins                                                                                            */
      for (LOC_u8Index = 0; LOC_u8Index < 8; LOC_u8Index++)
      {

        if (Dio_u8GetPinValue(DIO_PORTD, LOC_u8Index))
        {
          /* The button is not pressed then turn OFF the LED                                                         */
          Dio_vidSetPinValue(DIO_PORTA, LOC_u8Index, 0);
        }
        else
        {
          /* The button is pressed then turn ON the LED                                                              */
          Dio_vidSetPinValue(DIO_PORTA, LOC_u8Index, 1);
        }
      }
    }
    /*****************************************************************************************************************/

    /********************************* Moving LED String 1 ***********************************************************/
    if (LOC_u8Choice == 1)
    {

      for (LOC_u8Index = 0; LOC_u8Index < 8; LOC_u8Index++)
      {
        /* Turn ON the LED on turn                                                                                   */
        Dio_vidSetPinValue(DIO_PORTA, LOC_u8Index, 1);

        /* Delay to see the change                                                                                   */
        _delay_ms(500);

        /* Turn OFF the LED                                                                                          */
        Dio_vidSetPinValue(DIO_PORTA, LOC_u8Index, 0);

      }
    }
    /*****************************************************************************************************************/

    /********************************* Moving LED String 2 ***********************************************************/
    if (LOC_u8Choice == 2)
    {

      for (LOC_u8Index = 0; LOC_u8Index < 8; LOC_u8Index++)
      {
        /* Turn ON the LED on turn                                                                                   */
        Dio_vidSetPinValue(DIO_PORTA, LOC_u8Index, 1);

        /* Delay to see the change                                                                                   */
        _delay_ms(500);

        /* Turn OFF the LED                                                                                          */
        Dio_vidSetPinValue(DIO_PORTA, LOC_u8Index, 0);

      }

      for (LOC_u8Index = 0; LOC_u8Index < 8; LOC_u8Index++)
      {
        /* Turn ON the LED on turn                                                                                   */
        Dio_vidSetPinValue(DIO_PORTA, 7 - LOC_u8Index, 1);

        /* Delay to see the change                                                                                   */
        _delay_ms(500);

        /* Turn OFF the LED                                                                                          */
        Dio_vidSetPinValue(DIO_PORTA, 7 - LOC_u8Index, 0);

      }
    }
    /*****************************************************************************************************************/

    /********************************* Moving LED String 3 ***********************************************************/
    if (LOC_u8Choice == 3)
    {

      for (LOC_u8Index = 0; LOC_u8Index < 8; LOC_u8Index++)
      {
        /* Turn ON the LED on turn                                                                                   */
        Dio_vidSetPinValue(DIO_PORTA, LOC_u8Index, 1);
        Dio_vidSetPinValue(DIO_PORTA, 7 - LOC_u8Index, 1);

        /* Delay to see the change                                                                                   */
        _delay_ms(500);

        /* Turn OFF the LED                                                                                          */
        Dio_vidSetPinValue(DIO_PORTA, LOC_u8Index, 0);
        Dio_vidSetPinValue(DIO_PORTA, 7 - LOC_u8Index, 0);

      }

    }
    /*****************************************************************************************************************/
  }

}

