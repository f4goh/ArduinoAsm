//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

void __attribute__((noinline)) f(byte b1, byte b2, byte   b3, byte b4, byte b5, byte b6, byte b7, byte b8, byte   b9, byte b10, byte b11, byte b12)
{
  Serial.println(b1);
  Serial.println(b2);
  Serial.println(b3);
  Serial.println(b4);
  Serial.println(b5);
  Serial.println(b6);
  Serial.println(b7);
  Serial.println(b8);
  Serial.println(b9);
  Serial.println(b10);
  Serial.println(b11);
  Serial.println(b12);
}

void setup() {
  byte b1 = random();
  byte b2 = random();
  byte b3 = random();
  byte b4 = random();
  byte b5 = random();
  byte b6 = random();
  byte b7 = random();
  byte b8 = random();
  byte b9 = random();
  byte b10 = random();
  byte b11 = random();
  byte b12 = random();

  Serial.begin(9600);
  f(b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12);
}

void loop() {
}
