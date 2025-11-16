//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

void setup() {
  byte ret_low, ret_high;
  unsigned short funaddr;
  
  Serial.begin(9600);
  asm volatile (
    "call 1f      \n\t"
    "jmp  2f      \n\t"
    "1:           \n\t"
    "pop  r2      \n\t"
    "mov  %0, r2  \n\t"
    "pop  r3      \n\t"
    "mov  %1, r3  \n\t"
    "push r3      \n\t"
    "push r2      \n\t"
    "ret          \n\t"
    "2:           \n\t"
    : "=r" (ret_high), "=r" (ret_low)
    :
    : "r2", "r3"
  );
  Serial.print("Return address: ");
  Serial.print(ret_high, HEX);
  Serial.println(ret_low, HEX);

  funaddr = (unsigned short) setup;
  Serial.print("Function address: ");
  Serial.println(funaddr, HEX);
}

void loop() {
}
