//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

.global __vector_13
.global prepare

__SREG__ = 0x3f
__zero_reg__ = 1

__vector_13:

  push r16
  push r17
  in   r16, __SREG__
  push r16

  ldi  r16, 0b00100000
  in   r17, 0x05
  eor  r16, r17
  out  0x05, r16

  pop  r16
  out  __SREG__, r16
  pop  r17
  pop  r16
    
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
