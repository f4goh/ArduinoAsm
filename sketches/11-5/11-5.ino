//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

void setup() {
  byte io1=1, io2=2, io3=3, io4=4, io5=5, io6=6;
  byte oo1, oo2, oo3, oo4, oo5, oo6;

  asm volatile (
    "mov  %0, %6   \n\t"
    "mov  %1, %7   \n\t"
    "mov  %2, %8   \n\t"
    "mov  %3, %9   \n\t"
    "mov  %4, %10  \n\t"
    "mov  %5, %11  \n\t"    
    : "=&r" (oo1), "=&r" (oo2), "=&r" (oo3), "=&r" (oo4), "=&r" (oo5), "=&r" (oo6)
    : "r" (io1), "r" (io2), "r" (io3), "r" (io4), "r" (io5), "r" (io6)
    :
  );
  Serial.begin(9600);
  Serial.println(oo1);
  Serial.println(oo2);
  Serial.println(oo3);
  Serial.println(oo4);
  Serial.println(oo5);
  Serial.println(oo6);
}

void loop() {
}
