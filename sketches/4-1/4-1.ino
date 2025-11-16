//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

void setup() {
  byte a=1, b=0;
  
  Serial.begin(9600);
  Serial.print("a=");
  Serial.print(a);
  Serial.print(" b=");
  Serial.println(b);
  asm volatile (
   "mov r2, %1 \n\t"
   "mov %0, r2 \n\t"
    : "=r"(b)
    : "r"(a)
    : "r2"
  );
  Serial.print("a=");
  Serial.print(a);
  Serial.print(" b=");
  Serial.println(b);
}

void loop() {
}
