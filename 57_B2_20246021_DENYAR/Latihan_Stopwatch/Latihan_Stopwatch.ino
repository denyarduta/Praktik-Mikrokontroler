#include <LiquidCrystal.h>
#define b1 37  // biru
#define b2 39  // putih
#define b3 41  // merah

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 11, en = 12, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int a;
int i;
int b;
bool hitung = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.clear();
}

void loop() {
  but1 = digitalRead(b1);
  but2 = digitalRead(b2);
  but3 = digitalRead(b3);
  if (but1 == HIGH) {
    hitung = true;
  }
  if (but2 == HIGH) {
    hitung = false;
  }
  if (!hitung && but3 == HIGH) {
    hitung = false;
    lcd.clear();
    b = 0;
    a = 0;
    i = 0;
    lcd.setCursor(0, 0);
    lcd.print(b);
    lcd.print(":");
    lcd.print(i);
    lcd.print(":");
    lcd.print(a);
  }


  if (hitung == true) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(b);
    lcd.print(":");
    lcd.print(i);
    lcd.print(":");
    lcd.print(a);
    delay(10);
    a++;
    if (a > 59) {
      a = 0;
      i++;
      if (i > 59) {
        i = 0;
        b++;
        if (b > 59) {
          b = 0;
        }
      }
    }
  }
}
