#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  

const int sensorPin = 2;      
const int redLED = 3;
const int yellowLED = 4;
const int greenLED = 5;

unsigned long startTime = 0;
unsigned long stopTime = 0;
bool timing = false;

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("Project Chrono");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(3000);
  lcd.clear();

  pinMode(sensorPin, INPUT_PULLUP);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  digitalWrite(yellowLED, HIGH);
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);

  lcd.setCursor(0, 0);
  lcd.print("Ready...");
}

void loop() {
  int sensorState = digitalRead(sensorPin);
  Serial.println(sensorState);

  if (sensorState == LOW && !timing) {
    startTime = millis();
    timing = true;

    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Counting...");
    delay(200);  // Debounce
  }

  if (sensorState == HIGH && timing) {
    stopTime = millis();
    timing = false;

    unsigned long elapsedTime = stopTime - startTime;
    float seconds = elapsedTime / 1000.0;

    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Time:");
    lcd.setCursor(0, 1);
    lcd.print(seconds, 3);  
    lcd.print(" sec");
    delay(1000);  
  }
}
