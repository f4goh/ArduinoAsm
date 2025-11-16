//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

void setup() {
  int16_t i1 = 20000, i2 = 5000, i3;
  
  asm volatile (
    "mov  r15, %A1   \n\t"
    "mov  r16, %B1   \n\t"
    "mov  r17, %A2   \n\t"
    "mov  r18, %B2   \n\t"
    "sub  r15, r17   \n\t" 
    "sbc  r16, r18   \n\t"
    "mov  %A0, r15   \n\t"
    "mov  %B0, r16   \n\t"
    : "=r" (i3)
    : "r" (i1), "r" (i2)
    : "r15", "r16", "r17", "r18"
  );
  Serial.begin(9600);
  Serial.print("i3=");
  Serial.println(i3);  
}

void loop() {
}
