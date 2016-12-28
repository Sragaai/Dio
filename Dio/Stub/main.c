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

/*********************************************************************************************************************/
/* Password definition used in DIP Switch Password Application                                                       */
#define STUB_PASSWORD             0x00

/* LED Pattern to show if the password is OK                                                                         */
#define STUB_LED_OK_PATTERN       0xA5

/* LED Pattern to show if the password is Not OK                                                                     */
#define STUB_LED_NOK_PATTERN      0x81

/* Application Choice                                                                                                */
#define STUB_APP_CHOICE           7

/* 7-Segment numbers from 0 to 9                                                                                     */
u8 Stub_u8Segment[10] =
{
    0x3F, /* 0 */
    0x06, /* 1 */
    0x5B, /* 2 */
    0x4F, /* 3 */
    0x66, /* 4 */
    0x6D, /* 5 */
    0x7D, /* 6 */
    0x07, /* 7 */
    0x7F, /* 8 */
    0x6F /* 9 */
};
/*********************************************************************************************************************/

int main(void)
{

  /* Local Loop Index                                                                                                */
  u8 LOC_u8Index;

  /* Inner Local Loop Index                                                                                          */
  u8 LOC_u8InnerIndex;

  /* Variable to choose the working application                                                                      */
  u8 LOC_u8Choice;

  /* Application Choice                                                                                              */
  LOC_u8Choice = STUB_APP_CHOICE;

  /* PORT Initialization                                                                                             */
  for (LOC_u8Index = 0; LOC_u8Index < 8; LOC_u8Index++)
  {
    /* Setting PORTA as OUTPUT                                                                                       */
    Dio_vidSetPinDirection(DIO_PORTA, LOC_u8Index, 1);

    /* Setting PORTD as INPUT                                                                                        */
    Dio_vidSetPinDirection(DIO_PORTD, LOC_u8Index, 0);

    /* Setting PORTC as Output                                                                                       */
    Dio_vidSetPinDirection(DIO_PORTC, LOC_u8Index, 1);

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
          Dio_vidSetPinValue(DIO_PORTA, LOC_u8Index, STD_LOW);
        }
        else
        {
          /* The button is pressed then turn ON the LED                                                              */
          Dio_vidSetPinValue(DIO_PORTA, LOC_u8Index, STD_HIGH);
        }
      }
    }
    /*****************************************************************************************************************/

    /********************************* Moving LED String 1 ***********************************************************/
    /* LED string is moving from one side to another and repeat                                                       */

    if (LOC_u8Choice == 1)
    {

      for (LOC_u8Index = 0; LOC_u8Index < 8; LOC_u8Index++)
      {
        /* Turn ON the LED on turn                                                                                   */
        Dio_vidSetPinValue(DIO_PORTA, LOC_u8Index, STD_HIGH);

        /* Delay to see the change                                                                                   */
        _delay_ms(500);

        /* Turn OFF the LED                                                                                          */
        Dio_vidSetPinValue(DIO_PORTA, LOC_u8Index, STD_LOW);

      }
    }
    /*****************************************************************************************************************/

    /********************************* Moving LED String 2 ***********************************************************/
    /* LED string is moving from one side to another and go back again                                               */
    if (LOC_u8Choice == 2)
    {

      for (LOC_u8Index = 0; LOC_u8Index < 8; LOC_u8Index++)
      {
        /* Turn ON the LED on turn                                                                                   */
        Dio_vidSetPinValue(DIO_PORTA, LOC_u8Index, 1);

        /* Delay to see the change                                                                                   */
        _delay_ms(500);

        /* Turn OFF the LED                                                                                          */
        Dio_vidSetPinValue(DIO_PORTA, LOC_u8Index, STD_LOW);

      }

      for (LOC_u8Index = 0; LOC_u8Index < 8; LOC_u8Index++)
      {
        /* Turn ON the LED on turn                                                                                   */
        Dio_vidSetPinValue(DIO_PORTA, 7 - LOC_u8Index, STD_HIGH);

        /* Delay to see the change                                                                                   */
        _delay_ms(500);

        /* Turn OFF the LED                                                                                          */
        Dio_vidSetPinValue(DIO_PORTA, 7 - LOC_u8Index, STD_LOW);

      }
    }
    /*****************************************************************************************************************/

    /********************************* Moving LED String 3 ***********************************************************/
    /* LED sting is moving to the middle from the two sides and go back again                                        */
    if (LOC_u8Choice == 3)
    {

      for (LOC_u8Index = 0; LOC_u8Index < 8; LOC_u8Index++)
      {
        /* Turn ON the LED on turn                                                                                   */
        Dio_vidSetPinValue(DIO_PORTA, LOC_u8Index, STD_HIGH);
        Dio_vidSetPinValue(DIO_PORTA, 7 - LOC_u8Index, STD_HIGH);

        /* Delay to see the change                                                                                   */
        _delay_ms(500);

        /* Turn OFF the LED                                                                                          */
        Dio_vidSetPinValue(DIO_PORTA, LOC_u8Index, STD_LOW);
        Dio_vidSetPinValue(DIO_PORTA, 7 - LOC_u8Index, STD_LOW);

      }

    }
    /*****************************************************************************************************************/

    /*************************************** 7-Segment 0-9 ***********************************************************/
    /* Counting numbers from 0 to 9 on 7-Segment                                                                     */

    if (LOC_u8Choice == 4)
    {

      /* Loop on numbers from 0 t0 9                                                                                 */
      for (LOC_u8Index = 0; LOC_u8Index < 10; LOC_u8Index++)
      {
        /* Load the new number to show                                                                               */

        Dio_vidSetPortValue(DIO_PORTA, Stub_u8Segment[LOC_u8Index]);

        /* Turn ON the Dot                                                                                           */
        Dio_vidSetPinValue(DIO_PORTA, 7, STD_HIGH);

        /* Delay to see the change                                                                                   */
        _delay_ms(500);

        /* Turn OFF the Dot                                                                                          */
        Dio_vidSetPinValue(DIO_PORTA, 7, STD_LOW);

        /* Delay to see the change                                                                                   */
        _delay_ms(500);

      }

    }
    /*****************************************************************************************************************/

    /***************************************** DIO Test **************************************************************/
    /* Testing DIO pins                                                                                              */

    if (LOC_u8Choice == 5)
    {

      for (LOC_u8Index = 0; LOC_u8Index < 8; LOC_u8Index++)
      {
        /* All the port is set to ON                                                                                 */
        Dio_vidSetPinValue(DIO_PORTC, LOC_u8Index, STD_HIGH);

        _delay_ms(500);

        /* All the port is set to OFF                                                                                */
        Dio_vidSetPinValue(DIO_PORTC, LOC_u8Index, STD_LOW);
      }
    }
    /*****************************************************************************************************************/

    /********************************* Password Application **********************************************************/
    /* If the value on the DIP Switch matches the password then turn on the LED string in pattern                    */
    if (LOC_u8Choice == 6)
    {

      if (Dio_u8GetPortValue(DIO_PORTD) == STUB_PASSWORD)
      {
        Dio_vidSetPortValue(DIO_PORTA, STUB_LED_OK_PATTERN);
      }
      else
      {
        Dio_vidSetPortValue(DIO_PORTA, STUB_LED_NOK_PATTERN);
      }

    }
    /*****************************************************************************************************************/

    /********************************* Turning Light Application *****************************************************/
    /* Two 7-Segments counts from 59 to 0                                                                            */
    if (LOC_u8Choice == 7)
    {
      for (LOC_u8Index = 0; LOC_u8Index < 6; LOC_u8Index++)
      {
        /* Counting from 5 to 0                                                                                      */
        Dio_vidSetPortValue(DIO_PORTA, Stub_u8Segment[5 - LOC_u8Index]);

        for (LOC_u8InnerIndex = 0; LOC_u8InnerIndex < 10; LOC_u8InnerIndex++)
        {
          /* Counting from 9 to 0                                                                                    */
          Dio_vidSetPortValue(DIO_PORTC, Stub_u8Segment[9 - LOC_u8InnerIndex]);

          _delay_ms(500);
        }
      }

    }
    /*****************************************************************************************************************/

  }/* while 1*/

}

