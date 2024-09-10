#include <Arduino.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// put function declarations here:
int myFunction(int, int);
const int ROWS = 4;
const int COLS = 4;
const int rowPins[ROWS] = {};
const int colPins[COLS] = {};

char keys[ROWS][COLS] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};
Keypad keypad = Keypad(makeKeymap(keys), , , ROWS, COLS);

const int ADDRESS = 0x20;
LiquidCrystal lcd = LiquidCrystal_I2C(ADDRESS, 16, 2);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  Wire.begin();
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}