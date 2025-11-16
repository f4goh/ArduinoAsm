//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

byte __attribute__((naked)) pure_asm_inc(byte b1)
{
  asm (
    "inc  r24       \n\t"
    "clr  r25       \n\t"
    "ret            \n\t"
  );
}

void setup() {
  byte number = 3;

  Serial.begin(9600);  
  Serial.print("Before increment: ");
  Serial.println(number);  
  number = pure_asm_inc(3);
  Serial.print("After increment: ");
  Serial.println(number);  
}

void loop() {
}
