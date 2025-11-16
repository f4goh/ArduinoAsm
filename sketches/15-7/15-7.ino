//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

void setup() {
  uint8_t m1 = 0x75, m2 = 0x94;
  uint8_t pul, puh, psl, psh;
  
  Serial.begin(9600);
  asm volatile (
    "mov  r16, %4    \n\t"
    "mov  r17, %5    \n\t"
    "mul  r16, r17   \n\t" 
    "mov  %0, r0     \n\t"
    "mov  %1, r1     \n\t"    
    "muls r16, r17   \n\t"
    "mov  %2, r0     \n\t"
    "mov  %3, r1     \n\t"        
    "clr  r1         \n\t"
    : "=r" (pul), "=r" (puh), "=r" (psl), "=r" (psh)
    : "r" (m1), "r" (m2)
    : "r16", "r17"
  );
  Serial.print("pul=");
  Serial.print(pul, HEX);
  Serial.print(" puh=");
  Serial.println(puh, HEX);  
  Serial.print("psl=");
  Serial.print(psl, HEX);
  Serial.print(" psh=");
  Serial.println(psh, HEX);  
}

void loop() {
}
