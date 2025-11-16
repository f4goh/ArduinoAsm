//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

.global __vector_13
.global prepare

// Constants
#define __zero_reg__  1
#define __SREG__      0x3f
#define DEBUG_LED     0b00100000
#define PORTB_IO      0x05

// Registers
#define mask          r16
#define value         r17
#define temp          r18

__vector_13:

  push mask
  push value
  in   temp, __SREG__
  push temp

  ldi  mask, DEBUG_LED
  in   value, PORTB_IO
  eor  value, mask
  out  PORTB_IO, value

  pop  temp
  out  __SREG__, temp
  pop  value
  pop  mask
    
  reti

prepare:

  ldi r18, 0b00100000
  out 0x04, r18

  ldi xl, 0x80
  ldi xh, 0x00

  st  x+, __zero_reg__
  ldi r18, 2
  st  x+, r18
  st  x, __zero_reg__

  ldi xl, 0x6f
  ldi xh, 0x00
  ldi r18, 1
  st  x, r18

  ret
