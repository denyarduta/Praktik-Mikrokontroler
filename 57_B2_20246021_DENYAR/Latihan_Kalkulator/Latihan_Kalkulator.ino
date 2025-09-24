#include <LiquidCrystal.h>
#include <Keypad.h>

#define b1 37  // biru
#define b2 39  // putih
#define b3 41  // merah
#define b4 43  // kuning

const byte ROWS = 4;  // four rows
const byte COLS = 4;  // four columns

char keypad4x4[ROWS][COLS] = {
  { '1', '2', '3', '+' },
  { '4', '5', '6', '-' },
  { '7', '8', '9', 'x' },
  { '*', '0', '=', '/' }
};

byte rowPins[ROWS] = { 44, 42, 40, 38 }; 
byte colPins[COLS] = { 52, 50, 48, 46 }; 

Keypad customKeypad = Keypad(makeKeymap(keypad4x4), rowPins, colPins, ROWS, COLS);

const int rs = 11, en = 12, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

long input1 = 0;
long input2 = 0;
double hasil = 0;
char oper = 0;  // operator yg dipilih

long inputnomer2() {
  input2 = 0;  // reset input2 setiap kali input angka baru
  lcd.setCursor(7, 0);
  lcd.print("      "); // bersihkan bagian input kedua
  lcd.setCursor(7, 0);

  while (1) {
    char a = customKeypad.getKey();
    if (a) {
      if (a >= '0' && a <= '9') {  // digit angka
        input2 = input2 * 10 + (a - '0');
        lcd.print(a);
      } else if (a == '=') {   // tekan '=' untuk selesai input
        break;
      }
    }
  }
  return input2;
}

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Kalkulator");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
}

void loop() {
  char a = customKeypad.getKey();

  if (a) {
    if (a >= '0' && a <= '9') {
      input1 = input1 * 10 + (a - '0');
      lcd.print(a);
    } else if (a == '+' || a == '-' || a == 'x' || a == '/') {
      oper = a;
      lcd.print(a);
      input2 = inputnomer2();

      if (oper == '+') hasil = input1 + input2;
      else if (oper == '-') hasil = input1 - input2;
      else if (oper == 'x') hasil = input1 * input2;
      else if (oper == '/') {
        if (input2 != 0) hasil = (double)input1 / input2;
        else {
          lcd.clear();
          lcd.print("Error: Div 0");
          delay(2000);
          lcd.clear();
          input1 = 0; input2 = 0; hasil = 0;
          return;
        }
      }

      lcd.setCursor (0,1);
      lcd.print("= ");
      lcd.print(hasil);
      input1 = hasil;  // siap untuk operasi selanjutnya
      input2 = 0;
      oper = 0;
    } else if (a == '*') {  // tombol * untuk reset
      lcd.clear();
      input1 = 0;
      input2 = 0;
      hasil = 0;
      lcd.clear();
    }
  }
}
