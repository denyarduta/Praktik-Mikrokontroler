#include <Arduino.h>
#include <TM1637Display.h> // libary external yang digunakan

#define CLK 2 // pin CLK
#define DIO 3 // pin DIO

TM1637Display display(CLK, DIO);  // untuk mendefinisikan function display dengan libary yang digunakan

int i;

void setup() {
  display.setBrightness(7);  // mengatur tingkat kecerahan (nilai : 0-7)
}

void loop() {
  for (i = 0; i < 10; i++)  // menghitung 0-9
  {
    display.showNumberDec(i);
    delay(200);
  }

  for (i = 0; i < 10000; i++)  // menghitung 0-9999
  {
    display.showNumberDec(i);
    delay(0.05);
  }
  for (i = 9999; i > -1; i--)  //menghitung 9999-0
  {
    display.showNumberDec(i);
    delay(0.05);
  }
}
