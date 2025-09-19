// include the library code:
#include <LiquidCrystal.h>
#include <Keypad.h>
#define p1 A4

const byte ROWS = 4;  //four rows
const byte COLS = 4;  //four columns
//define the cymbols on the buttons of the keypads
char keypad4x4[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
byte rowPins[ROWS] = { 42, 44, 46, 48 };  //connect to the row pinouts of the keypad
byte colPins[COLS] = { 34, 36, 38, 40 };  //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(keypad4x4), rowPins, colPins, ROWS, COLS);

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int b;
int c;
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.clear();
}

void loop() {

  char a = customKeypad.getKey();

  if (a) {
    if (b > 16) {

      lcd.setCursor(c, 1);
      lcd.print(a);
      c++;
    }
    if (b < 17) {
      Serial.println(a);
      lcd.print(a);
    }

    if (a == '*') {
      lcd.clear();
      b = 0;
      c = 0;
    }
    b++;
  }
}
