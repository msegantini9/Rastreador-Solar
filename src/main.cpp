#include <Arduino.h>

#define pinLdr1 A0
#define pinLdr2 A1

int value1, value2;

void setup() {
  Serial.begin(9600);

  pinMode(pinLdr1, INPUT);
  pinMode(pinLdr1, INPUT);
}

void loop() {
  value1 = analogRead(pinLdr1);
  value2 = analogRead(pinLdr2);

  if(value1 > value2){
    Serial.println("Mover aleta para cima!");
  }else if (value1 < value2){
    Serial.println("Mover aleta para baixo!");
  }

  delay(1000);
}