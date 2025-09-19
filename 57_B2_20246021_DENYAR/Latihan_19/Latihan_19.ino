

// include the library code:
#include <LiquidCrystal.h>
#define button 8
#define p1 A4
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int val2 = 1;

int b;
int a;

bool val = LOW;

void setup() {
  pinMode(button, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  a = analogRead(p1);
  b = map(a, 0, 1023, 20, 1000);

  Serial.println(b);

  if (b < 500 && b > 20) {
    lcd.setCursor(0, 0);
    lcd.print("Saya Sigma");
  }

  else if (b > 500 && b < 800) {
    lcd.setCursor(0, 1);
    lcd.print("sangat Sigma");
  }

  else if (b > 800 && b < 1000) {
    lcd.clear();
  }

  delay(1000);
  lcd.clear();
}
