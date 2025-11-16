//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

volatile __attribute__((used)) uint8_t u = 9;

void setup() {
  Serial.begin(9600);
  Serial.println(u);  
  asm volatile (
    "lds  r2, u   \n\t"
    "inc  r2      \n\t"
    "sts  u, r2   \n\t" 
    :
    :
    : "r2"
  );
  Serial.println(u);
}

void loop() {
}
