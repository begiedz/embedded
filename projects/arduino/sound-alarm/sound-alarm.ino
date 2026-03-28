#include <hcsr04.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 12
#define ECHO_PIN 13

int led = 9;  
int brightness = 0;
int fadeAmount = 5;

HCSR04 hcsr04(TRIG_PIN, ECHO_PIN, 20, 4000);
LiquidCrystal_I2C lcd(0x27,20,4);

void measureDistance() {
  int distance = hcsr04.distanceInMillimeters();  
  if (distance <= 100 && distance > -1) {

    lcd.setCursor(0,0);
    lcd.print(distance);

    lcd.setCursor(0,1);
    lcd.print("TOO CLOSE");

    analogWrite(led, 128);
  } else {
    lcd.setCursor(0,0);
    lcd.print(distance);

    lcd.setCursor(0,1);
    lcd.print("OK");

    analogWrite(led, 0);
  }
  delay(250);
}

void setup(){
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();

    lcd.setCursor(0,0);
    lcd.print("Dariusz Begiedza");

    lcd.setCursor(0,1);
    lcd.print("index: 51276");

    pinMode(led, OUTPUT);

    delay(2000);
}

void loop() {
    lcd.clear();
    measureDistance();
}