//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

uint8_t f(uint8_t n)
{
  uint8_t r;

  asm volatile (
    "mov  r24, %1    \n\t"
    "cpi  r24, 1     \n\t"
    "breq 2f         \n\t"
    "brcs 1f         \n\t"
    "cpi  r24, 2     \n\t"
    "breq 3f         \n\t"
    "cpi  r24, 3     \n\t"
    "brne 4f         \n\t"
    "ldi  r24, 5     \n\t"
    "rjmp 5f         \n\t"
    "1:              \n\t"
    "ldi  r24, 1     \n\t"
    "rjmp 5f         \n\t"
    "2:              \n\t"
    "ldi  r24, 2     \n\t"
    "rjmp 5f         \n\t"
    "3:              \n\t"
    "ldi  r24, 3     \n\t"
    "rjmp 5f         \n\t"
    "4:              \n\t"
    "ldi  r24, 10    \n\t"
    "5:              \n\t"
    "subi r24, 0xfb  \n\t"
    "mov  %0, r24    \n\t"
    : "=r" (r)
    : "r" (n)
    : "r24"
  );

  return r;
}

void setup() {
  uint8_t i;

  Serial.begin(9600);
  for (i=0; i<=4; i++)
  {
    Serial.println(f(i));
  }
}

void loop() {
}
