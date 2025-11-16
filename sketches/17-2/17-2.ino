//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

uint8_t u;
uint8_t *p;
  
void setup() {
  uint8_t i;

  Serial.begin(9600);
  u = 0x88;
  p = &u;
  for (i=0; i<100; i++)
  {
    u += i;
  }
  asm volatile (
    "ldi  r16, 0x99 \n\t"
    "st   %a0, r16  \n\t"
    :
    : "e" (p)
    : "r16", "memory"
  );
  for (i=0; i<100; i++)
  {
    u += i;
  }
  Serial.println(u);
}

void loop() {
}
