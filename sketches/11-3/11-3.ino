//
// https://vidstromlabs.com/books/arduinoassembly/
//
// Copyright (c) 2019, Arne Vidstrom
//

void __attribute__((noinline)) level2() {
  byte q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20;
  
  q1 = random();
  q2 = random();
  q3 = random();
  q4 = random();
  q5 = random();  
  q6 = random();
  q7 = random();
  q8 = random();
  q9 = random();
  q10 = random();
  q11 = random();
  q12 = random();
  q13 = random();
  q14 = random();
  q15 = random();
  q16 = random();
  q17 = random();
  q18 = random();
  q19 = random();
  q20 = random();

  Serial.print(q1);
  Serial.print(q2);
  Serial.print(q3);
  Serial.print(q4);
  Serial.print(q5);
  Serial.print(q6);
  Serial.print(q7);
  Serial.print(q8);
  Serial.print(q9);
  Serial.print(q10);
  Serial.print(q11);
  Serial.print(q12);
  Serial.print(q13);
  Serial.print(q14);
  Serial.print(q15);
  Serial.print(q16);
  Serial.print(q17);
  Serial.print(q18);
  Serial.print(q19);
  Serial.print(q20);
}

void setup() {
  byte q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, q19, q20;
  
  Serial.begin(9600);
  randomSeed(analogRead(0));
  q1 = random();
  q2 = random();
  q3 = random();
  q4 = random();
  q5 = random();  
  q6 = random();
  q7 = random();
  q8 = random();
  q9 = random();
  q10 = random();
  q11 = random();
  q12 = random();
  q13 = random();
  q14 = random();
  q15 = random();
  q16 = random();
  q17 = random();
  q18 = random();
  q19 = random();
  q20 = random();

  level2();

  Serial.print(q1);
  Serial.print(q2);
  Serial.print(q3);
  Serial.print(q4);
  Serial.print(q5);
  Serial.print(q6);
  Serial.print(q7);
  Serial.print(q8);
  Serial.print(q9);
  Serial.print(q10);
  Serial.print(q11);
  Serial.print(q12);
  Serial.print(q13);
  Serial.print(q14);
  Serial.print(q15);
  Serial.print(q16);
  Serial.print(q17);
  Serial.print(q18);
  Serial.print(q19);
  Serial.print(q20);
}

void loop() {
}
