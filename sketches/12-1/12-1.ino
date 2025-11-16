//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

volatile __attribute__((used)) uint16_t u1 = 13209, u2;

void setup() {
  asm volatile (
    "mov  r15, %A1   \n\t"
    "mov  r16, %B1   \n\t"
    "lsl  r15        \n\t" 
    "rol  r16        \n\t"
    "mov  %A0, r15   \n\t"
    "mov  %B0, r16   \n\t"
    : "=r" (u2)
    : "r" (u1)
    : "r15", "r16"
  );
  Serial.begin(9600);
  Serial.print("u2=");
  Serial.println(u2);  
}

void loop() {
}
