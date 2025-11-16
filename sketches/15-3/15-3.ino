//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

volatile __attribute__((used)) int8_t i1=126, i2=1, i3 = 126, i4 = 2, result_no_overflow, result_overflow;
volatile __attribute__((used)) byte sreg_value_no_overflow, sreg_value_overflow;

void setup() {
  Serial.begin(9600);
  asm volatile (
    // Addition that doesn't set the Two's Complement
    // Overflow Flag  
    "lds  r16, i1                     \n\t"
    "lds  r17, i2                     \n\t"
    "add  r16, r17                    \n\t"
    "sts  result_no_overflow, r16     \n\t"
    "in  r16, __SREG__                \n\t"
    "sts sreg_value_no_overflow, r16  \n\t"

    // Addition that sets the Two's Complement Overflow
    // Flag
    "lds  r16, i3                     \n\t"
    "lds  r17, i4                     \n\t"
    "add  r16, r17                    \n\t"
    "sts  result_overflow, r16        \n\t"
    "in  r16, __SREG__                \n\t"
    "sts sreg_value_overflow, r16     \n\t"
        
    :
    :
    : "r16", "r17"
  );
  Serial.print("Result without Two's Complement Overflow Flag set=");
  Serial.println(result_no_overflow);
  Serial.print("SREG without Two's Complement Overflow Flag set=");
  Serial.println(sreg_value_no_overflow, HEX);
  Serial.print("Result with Two's Complement Overflow Flag set=");
  Serial.println(result_overflow);
  Serial.print("SREG with Two's Complement Overflow Flag set=");
  Serial.println(sreg_value_overflow, HEX);
}

void loop() {
}
