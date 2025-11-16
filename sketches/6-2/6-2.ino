//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

unsigned long on_delay = 100;
unsigned long off_delay = 1000;

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
    "sbi %0, %2       \n\t"
    "sbi %1, %3       \n\t"

    // Wait 100 ms
    "mov r22, %A4     \n\t"
    "mov r23, %B4     \n\t"
    "mov r24, %C4     \n\t"
    "mov r25, %D4     \n\t"
    "call asm_delay   \n\t"  

    // Turn debug LED off
    "cbi %1, %3       \n\t"

    // Wait 1000 ms
    "mov r22, %A5     \n\t"
    "mov r23, %B5     \n\t"
    "mov r24, %C5     \n\t"
    "mov r25, %D5     \n\t"
    "call asm_delay   \n\t"    
    :
    : "I" (_SFR_IO_ADDR(DDRB)), "I" (_SFR_IO_ADDR(PORTB)), "I" (DDB5), "I" (PB5), "r" (on_delay), "r" (off_delay)
    : "r22", "r23", "r24", "r25"
  );
}
