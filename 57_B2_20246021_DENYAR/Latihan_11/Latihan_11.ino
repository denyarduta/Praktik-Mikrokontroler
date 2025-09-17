#include <Keypad.h>
#include <Arduino.h>
#include <TM1637Display.h> // libary external yang digunakan

TM1637Display display(2, 3);  // untuk mendefinisikan function display dengan libary yang digunakan, 'nama libary' display(pinCLK, pinDIO)

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char keypad4x4[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {8, 7, 6, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {12, 11, 10, 9}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(keypad4x4), rowPins, colPins, ROWS, COLS); 

// Buffer untuk menyimpan 4 karakter input
char inputBuffer[4] = {' ', ' ', ' ', ' '};
int inputIndex = 0;

void setup() {
  Serial.begin(9600);
  display.setBrightness(7);
  display.clear();
}

void loop() {
  char customKey = customKeypad.getKey();

  if (customKey) {
    Serial.println(customKey);

    if (inputIndex < 4 && ((customKey >= '0' && customKey <= '9') || (customKey >= 'A' && customKey <= 'D') || customKey == '*' || customKey == '#')) {
      inputBuffer[inputIndex] = customKey;
      inputIndex++;

      // Tampilkan buffer
      uint8_t segments[4];
      for (int i = 0; i < 4; i++) {
        segments[i] = encodeChar(inputBuffer[i]);
      }
      display.setSegments(segments);
    }

  //Tombol reset
    if (customKey == '*') {
      inputIndex = 0;
      for (int i = 0; i < 4; i++) inputBuffer[i] = ' ';
      display.clear();
    }
  }
}

// Fungsi untuk mengonversi karakter ke 7-segment
uint8_t encodeChar(char c) {
  switch (c) {
    case '0'...'9': return display.encodeDigit(c - '0');
    case 'A': return SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G;
    case 'B': return SEG_C | SEG_D | SEG_E | SEG_F | SEG_G;
    case 'C': return SEG_A | SEG_D | SEG_E | SEG_F;
    case 'D': return SEG_B | SEG_C | SEG_D | SEG_E | SEG_G; 
    case '#': return SEG_B | SEG_C | SEG_E | SEG_F | SEG_G;
    case '*': return SEG_A | SEG_C | SEG_E | SEG_G; 
    case ' ': return 0x00;
    default: return 0x00; // Kosongkan jika tidak dikenali
  }
}