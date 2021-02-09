#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define DigitalPin 2
#define AnalogPin A0

int threshold;
int analogValue;

void setup() {
  pinMode(DigitalPin, INPUT);
  pinMode(AnalogPin, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Digital Temperature");

  lcd.setCursor(0, 2);
  lcd.print("Threshold: ");

  lcd.setCursor(0, 3);
  lcd.print("Value: ");
}

void loop() {
  threshold = digitalRead(DigitalPin);
  analogValue = analogRead(AnalogPin);

  lcd.setCursor(11, 2);
  if (threshold == HIGH) {
    lcd.print("Above");
  } else {
    lcd.print("Below");
  }

  lcd.setCursor(7,3);
  lcd.print(analogValue);

  delay(250);
}
