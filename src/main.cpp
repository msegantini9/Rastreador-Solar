#include <Arduino.h>
#include <Servo.h>

void moveServo(int pos);
void readLdr();

#define pinLdr1 A0
#define pinLdr2 A1
#define pinServo 4

Servo servo;
int accuracy = 5;
int value1, value2, pos;

void setup() {
  Serial.begin(9600);

  pinMode(pinLdr1, INPUT);
  pinMode(pinLdr1, INPUT);

  servo.attach(pinServo, 0, 180);
}

void loop() {
  readLdr();
  delay(1000);
}

void moveServo(int pos){
  if(pos >= -180 || pos <= 180){
    servo.write(pos);
  }
}

void readLdr(){
  value1 = analogRead(pinLdr1);
  value2 = analogRead(pinLdr2);
  pos = servo.read();
  long lastTime = millis();

  while(abs(value1 - value2 ) > accuracy){
    if(value1 > value2){
      pos < 0 ? pos = 0 : pos--;
    }else if (value1 < value2){
      pos > 180 ? pos = 180 : pos++;
    }

    if(millis() - lastTime > 1000){
      Serial.print("pos: ");
      Serial.println(servo.read());
      Serial.print("ldr1: ");
      Serial.println(analogRead(pinLdr1));
      Serial.print("ldr2: ");
      Serial.println(analogRead(pinLdr2));
      Serial.println();

      lastTime = millis();
    }

    moveServo(pos);

    value1 = analogRead(pinLdr1);
    value2 = analogRead(pinLdr2);
    pos = servo.read();

    delay(50);
  }
}