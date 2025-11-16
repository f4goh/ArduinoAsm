//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

asm (
  ".global __vector_13  \n\t"
  "__vector_13:         \n\t"

  "push r16             \n\t"
  "push r17             \n\t"
  "in   r16, __SREG__   \n\t"
  "push r16             \n\t"

  "ldi  r16, 0b00100000 \n\t"
  "in   r17, 0x05       \n\t"
  "eor  r16, r17        \n\t"
  "out  0x05, r16       \n\t"

  "pop  r16             \n\t"
  "out  __SREG__, r16   \n\t"
  "pop  r17             \n\t"
  "pop  r16             \n\t"
    
  "reti                 \n\t"
);

void setup() {
  asm (
    "ldi r16, 0b00100000     \n\t"
    "out 0x04, r16           \n\t"

    "ldi xl, 0x80            \n\t"
    "ldi xh, 0x00            \n\t"

    "st  x+, __zero_reg__    \n\t"
    "ldi r16, 2              \n\t"
    "st  x+, r16             \n\t"
    "st  x, __zero_reg__     \n\t"

    "ldi xl, 0x6f            \n\t"
    "ldi xh, 0x00            \n\t"
    "ldi r16, 1              \n\t"
    "st  x, r16              \n\t"
    : : : "r16"
  );
}

void loop() {
}
