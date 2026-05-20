#include <Wire.h>

#include <LiquidCrystal_I2C.h>

#define SDA_PIN 21

#define SCL_PIN 22

#define SENSOR_PIN 34

#define BUZZER_PIN 25

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

Serial.begin(115200);

Wire.begin(SDA_PIN, SCL_PIN);

pinMode(BUZZER_PIN, OUTPUT);

digitalWrite(BUZZER_PIN, LOW);

lcd.init();

lcd.backlight();

lcd.setCursor(0, 0);

lcd.print("System Starting");

delay(2000);

lcd.clear();

}

void loop() {

int raw = analogRead(SENSOR_PIN);

float voltage = raw * (3.3 / 4095.0);

float ec = voltage * 1000;

float salinity = ec * 0.0005;

Serial.print("Salinity: ");

Serial.println(salinity);

lcd.setCursor(0, 0);

lcd.print("Salinity:");

lcd.setCursor(0, 1);

lcd.print(salinity, 2);

lcd.print(" ppt   ");

// 🚨 WARNING CONDITION

if (salinity > 10.0) {

lcd.setCursor(0, 0);

lcd.print("!!! WARNING !!!");



digitalWrite(BUZZER_PIN, HIGH);  // Turn buzzer ON

} else {

digitalWrite(BUZZER_PIN, LOW);   // Turn buzzer OFF

}

delay(1000);

}
