//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

uint8_t f(uint8_t n)
{
  uint8_t r;

  asm volatile (
    "mov  r24, %1         \n\t"
    "cpi  r24, 4          \n\t"
    "brsh 6f              \n\t"
    "ldi  zl, pm_lo8(1f)  \n\t"
    "ldi  zh, pm_hi8(1f)  \n\t"
    "add  zl, r24         \n\t"
    "adc  zh, r1          \n\t"
    #ifdef __AVR_HAVE_EIJMP_EICALL__
    "ldi  r25, pm_hh8(1f) \n\t"
    "adc  r25, r1         \n\t"
    "out 0x3c, r25        \n\t"
    "eijmp                \n\t"    
    #else
    "ijmp                 \n\t"    
    #endif
    "1:                   \n\t"
    "rjmp 2f              \n\t"
    "rjmp 3f              \n\t"
    "rjmp 4f              \n\t"
    "rjmp 5f              \n\t"
    "2:                   \n\t"
    "ldi  r24, 1          \n\t"
    "rjmp 7f              \n\t"
    "3:                   \n\t"
    "ldi  r24, 2          \n\t"
    "rjmp 7f              \n\t"
     "4:                  \n\t"
    "ldi  r24, 3          \n\t"
    "rjmp 7f              \n\t"
    "5:                   \n\t"
    "ldi  r24, 5          \n\t"
    "rjmp 7f              \n\t"
    "6:                   \n\t"
    "ldi  r24, 10         \n\t"
    "7:                   \n\t"
    "subi r24, 0xfb       \n\t"
    "mov  %0, r24         \n\t"
    : "=r" (r)
    : "r" (n)
    : "r24", "r25"
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
