//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

void setup() {
  byte sum;
  
  Serial.begin(9600);
  asm volatile (
   "ldi r16, 15   \n\t"
   "ldi r17, 37   \n\t"
   "add r16, r17  \n\t"
   "mov %0, r16   \n\t"
    : "=r"(sum)
    :
    : "r16", "r17"
  );
  Serial.print("sum=");
  Serial.println(sum);
}

void loop() {
}
