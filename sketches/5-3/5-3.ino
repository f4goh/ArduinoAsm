//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

extern "C" {
  __attribute__((used)) void asm_delay(unsigned long d)
  {
    delay(d);
  }
}

void setup() {
}

void loop() {
  asm volatile (
    // Turn debug LED on
    "sbi 0x04, 5      \n\t"
    "sbi 0x05, 5      \n\t"

    // Wait 100 ms
    "ldi r22, 0x64    \n\t"
    "ldi r23, 0x00    \n\t"
    "ldi r24, 0x00    \n\t"
    "ldi r25, 0x00    \n\t"
    "call asm_delay   \n\t"  

    // Turn debug LED off
    "cbi 0x05, 5      \n\t"

    // Wait 1000 ms
    "ldi r22, 0xe8    \n\t"
    "ldi r23, 0x03    \n\t"
    "ldi r24, 0x00    \n\t"
    "ldi r25, 0x00    \n\t"
    "call asm_delay   \n\t"
    :
    :
    : "r22", "r23", "r24", "r25"
  );
}
