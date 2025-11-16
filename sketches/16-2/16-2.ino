//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

void setup() {
  uint8_t result;

  Serial.begin(9600);
  asm volatile (
    "ldi  r24, 0     \n\t"
    "ldi  r25, 0     \n\t"        
    "1:              \n\t"
    "cpi  r24, 10    \n\t"
    "brcc 2f         \n\t"
    "add  r25, r24   \n\t"
    "inc  r24        \n\t"
    "rjmp 1b         \n\t"
    "2:              \n\t"
    "subi r25, 5     \n\t"   
    "mov  %0, r25    \n\t"
    : "=r" (result)
    :
    : "r24", "r25"
  );
  Serial.print("result=");
  Serial.println(result);
}

void loop() {
}
