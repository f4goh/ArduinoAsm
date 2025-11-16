//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

.global main

delay_sub:
    ldi  r16, 255
    ldi  r17, 255
    ldi  r18, 20
delay_loop:
    dec  r16
    brne delay_loop
    dec  r17
    brne delay_loop
    dec  r18
    brne delay_loop
    ret

main:
  sbi   0x04, 5
blink:  
  sbi   0x05, 5
  call  delay_sub
  cbi   0x05, 5 
  call  delay_sub
  rjmp  blink
