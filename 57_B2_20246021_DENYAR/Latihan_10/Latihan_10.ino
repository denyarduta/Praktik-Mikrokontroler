#include <Arduino.h>
#include <TM1637Display.h> // libary external yang digunakan

TM1637Display display(2, 3);  // untuk mendefinisikan function display dengan libary yang digunakan, 'nama libary' display(pinCLK, pinDIO)

int i;
int a;
void setup() {
  display.setBrightness(7);  // mengatur tingkat kecerahan (nilai : 0-7)
}

void loop() {
  for (i = 0; i < 24; i++)  // menghitung 0-23:59
  {
    display.showNumberDecEx(i,0b11100000,true,2,0);
    for (a = 0; a < 60; a++) {
      display.showNumberDecEx(a,0b11100000,true,2,2);
      delay(10);
    }

    delay(0);
  }

  for (i = 23; i > -1; i--)  // menghitung 23:59-0
  {
    display.showNumberDecEx(i,0b11100000,true,2,0);
    for (a = 59; a > -1; a--) {
      display.showNumberDecEx(a,0b11100000,true,2,2);
      delay(10);
    }

    delay(0);
  }
}

