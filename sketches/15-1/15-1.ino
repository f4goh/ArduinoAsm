//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

volatile __attribute__((used)) uint8_t u;
volatile __attribute__((used)) int8_t i1 = -10, i2;

void setup() {
  asm volatile (
    "lds  r15, i1    \n\t"
    "sts  u, r15     \n\t" 
    "sts  i2, r15    \n\t"
    :
    :
    : "r15"
  );
  Serial.begin(9600);
  Serial.print("u=");
  Serial.println(u);
  Serial.print("i2=");
  Serial.println(i2);  
}

void loop() {
}
