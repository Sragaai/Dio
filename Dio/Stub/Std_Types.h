
#ifndef _STD_TYPES_H

#define _STD_TYPES_H


typedef unsigned       char   u8;

typedef unsigned short int    u16;

typedef unsigned long  int    u32;

typedef signed         char   s8;

typedef signed   short int    s16;

typedef signed   long  int    s32;

typedef                float  f32;

typedef                double f64;

typedef          long  double f80;

/* Type definition for byte and bit access                                                                           */
typedef union
{
  struct
  {
    u8 u8b0 :1; /* LSB (least significant bit)*/
    u8 u8b1 :1; /* BIT 1                      */
    u8 u8b2 :1; /* BIT 2                      */
    u8 u8b3 :1; /* BIT 3                      */
    u8 u8b4 :1; /* BIT 4                      */
    u8 u8b5 :1; /* BIT 5                      */
    u8 u8b6 :1; /* BIT 6                      */
    u8 u8b7 :1; /* MSB (most significant bit) */
  } strBit;     /*for bit  access             */
  u8 u8Byte;    /* for byte access            */
} STD_tenuPort;
/*********************************************************************************************************************/

#endif
