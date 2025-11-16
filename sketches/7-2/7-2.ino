//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

void setup() {
  byte sreg_value_carry, result_carry,   sreg_value_no_carry, result_no_carry;
  
  Serial.begin(9600);
  asm volatile (

    // Addition that sets the Carry Flag
    "ldi  r16, 97       \n\t"
    "ldi  r17, 162      \n\t"
    "add  r16, r17      \n\t"
    "mov  %0, r16       \n\t"
    "in  r16, __SREG__  \n\t"
    "mov %1, r16        \n\t"

    // Addition that doesn't set the Carry Flag
    "ldi  r16, 9        \n\t"
    "ldi  r17, 16       \n\t"
    "add  r16, r17      \n\t"
    "mov  %2, r16       \n\t"
    "in  r16, __SREG__  \n\t"
    "mov %3, r16        \n\t"
        
    : "=r" (result_carry), "=r" (sreg_value_carry), "=r" (result_no_carry), "=r" (sreg_value_no_carry)
    :
    : "r16", "r17"
  );
  Serial.print("Result with Carry Flag set=");
  Serial.println(result_carry);
  Serial.print("SREG with Carry Flag set=");
  Serial.println(sreg_value_carry, HEX);
  Serial.print("Result without Carry Flag set=");
  Serial.println(result_no_carry);
  Serial.print("SREG without Carry Flag set=");
  Serial.println(sreg_value_no_carry, HEX);
}

void loop() {
}
