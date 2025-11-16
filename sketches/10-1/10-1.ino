//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

void setup() {
  byte spl, sph;
  
  asm volatile (
    "in   %0, 0x3d  \n\t"
    "in   %1, 0x3e  \n\t"
    : "=r" (spl), "=r" (sph)
    :
    :
  );
  Serial.begin(9600);
  Serial.print("SP: ");
  Serial.print(sph, HEX);
  Serial.println(spl, HEX);
  Serial.print("RAMEND: ");
  Serial.println(RAMEND, HEX);
}

void loop() {
}
