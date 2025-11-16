//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

const char *s = "AVR"; 

void setup() {
  byte pl, ph;
  char ch1, ch2, ch3;

  pl = ((unsigned short) s) & 0xff;
  ph = ((unsigned short) s) >> 8;
  asm volatile (
    "mov  r26, %3   \n\t"
    "mov  xh,  %4   \n\t"
    "ld   %0,  x+   \n\t"
    "ld   %1,  x+   \n\t"
    "ld   %2,  x    \n\t"
    : "=r" (ch1), "=r" (ch2), "=r" (ch3)
    : "r" (pl), "r" (ph)
    : "r26", "r27"
  );
  Serial.begin(9600);
  Serial.println(ch1);
  Serial.println(ch2);
  Serial.println(ch3);
}

void loop() {
}
