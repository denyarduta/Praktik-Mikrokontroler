#define buzzer  3

int val;
int i = 0;

void setup() {
  pinMode (buzzer, OUTPUT);
}

void loop() {
  while (i<2) {
    
    digitalWrite (buzzer, HIGH);
    delay (300);
    digitalWrite (buzzer, LOW);
    delay(300);
    i++;
  }

}
