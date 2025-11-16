//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

void setup() {
  int8_t i1, i2;
  
  Serial.begin(9600);
  i1 = -128;
  for ( ; ; )
  {
    asm volatile (
      "mov  r15, %1    \n\t"
      "asr  r15        \n\t" 
      "mov  %0, r15    \n\t"
     : "=r" (i2)
     : "r" (i1)
     : "r15"
    );
    Serial.print("asr ");
    Serial.print(i1);
    Serial.print(" = ");
    Serial.print(i2);
    Serial.print(" ... ");
    Serial.print(i1);
    Serial.print(" / 2 = ");
    Serial.println(i1/2);
    if (i1 == 127)
    {
      break;
    }
    i1++;
  }
}

void loop() {
}
