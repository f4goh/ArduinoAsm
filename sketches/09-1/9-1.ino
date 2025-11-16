//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

void setup() {
  byte result = 0;
  
  asm volatile (
    "ldi  r16, 10    \n\t"
    "jmp  1f         \n\t"
    "ldi  r16, 20    \n\t"
    "1: mov %0, r16  \n\t"
    : "=r" (result)
    :
    : "r16"
  );
  Serial.begin(9600);
  Serial.println(result);
}

void loop() {
}
