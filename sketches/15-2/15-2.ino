//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

volatile __attribute__((used)) uint8_t u = 10;
volatile __attribute__((used)) int8_t i1 = -7, i2;

void setup() {
  asm volatile (
    "lds  r15, u    \n\t"
    "lds  r16, i1   \n\t"
    "add  r15, r16  \n\t" 
    "sts  i2, r15   \n\t"
    :
    :
    : "r15", "r16"
  );
  Serial.begin(9600);
  Serial.print("i2=");
  Serial.println(i2);  
}

void loop() {
}
