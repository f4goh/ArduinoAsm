//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

uint8_t f(uint8_t input)
{
  uint8_t result;
  
  asm volatile (
    "mov  r24, %1    \n\t"
    "ldi  r25, 5     \n\t"
    "cp   r24, r25   \n\t" 
    "brcs 1f         \n\t"
    "add  r24, r25   \n\t"    
    "1:              \n\t"
    "mov  %0, r24    \n\t"
    : "=r" (result)
    : "r" (input)
    : "r24", "r25"
  );
  return result;
}

void setup() {
  Serial.begin(9600);
  Serial.println(f(1));
  Serial.println(f(9));
}

void loop() {
}
