#define ledPin 2   // LED warna Merah
#define ledPin1 3  // LED warna Kuning
#define ledPin2 4  // LED warna Hijau
#define inPin 7    // PushButton warna Kuning

int val2 = 1;

bool val = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(inPin, INPUT);

  digitalWrite(ledPin, LOW);
}

void loop() {
  while (val2 == 1) {
    val = digitalRead(inPin);
    if (val == HIGH)  {
      while (val == HIGH) {
        val = digitalRead(inPin);      
      }
      
      digitalWrite(ledPin, HIGH);
      
      
      val2 = 2;
    }
  }


  while (val2 == 2) {
    val = digitalRead(inPin);
  
    if (val == HIGH)  {
      while (val == HIGH) {
        val = digitalRead(inPin);
      }
      digitalWrite(ledPin, LOW);
      
      val2 = 1;
    }
  }
}
