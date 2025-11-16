//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

void setup() {
  byte result;
  
  asm volatile (
    "ldi  r16, 11   \n\t"
    "ldi  r17, 10   \n\t"
    "cp   r16, r17  \n\t"
    "brlo 1f        \n\t"
    "ldi  %0, 17    \n\t"
    "jmp  2f        \n\t"
    "1: ldi %0, 16  \n\t"
    "2:             \n\t"
    : "=d" (result)
    :
    : "r16", "r17"
  );
  Serial.begin(9600);
  Serial.print("The register with the lower value was r");
  Serial.println(result);
}

void loop() {
}
