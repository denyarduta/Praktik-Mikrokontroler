

// include the library code:
#include <LiquidCrystal.h>
#define button 8
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int val2 = 1;

bool val = LOW;

void setup() {
  pinMode (button, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Denyar Tamvan");
}

void loop() {
  while (val2 == 1) {
    val = digitalRead(button);
    if (val == HIGH)  {
      while (val == HIGH) {
        val = digitalRead(button);  
        lcd.clear();    
      }
      lcd.setCursor(0,0);
      lcd.print("Denyar Tamvan");
      
      
      val2 = 2;
    }
  }


  while (val2 == 2) {
    val = digitalRead(button);
  
    if (val == HIGH)  {
      while (val == HIGH) {
        val = digitalRead(button);
        lcd.clear();
      }
      
      lcd.setCursor(0,1);
      lcd.print("Denyar Sigma");
      val2 = 1;
    }
  }
}

