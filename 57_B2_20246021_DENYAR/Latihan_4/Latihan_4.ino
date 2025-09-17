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
    if (val == HIGH) // saat tombol ditekan
     {
      digitalWrite(ledPin, HIGH); // lampu menyala 
      while (val == HIGH) //posisi tombol masih ditekan (ketika tombol dilepas, nilai menjadi LOW sehingga persyaratan while tidak berlaku)
      {   
        val = digitalRead(inPin); //selama tombol masih ditekan, kompiler masih membaca input tombol    
      }
      
      val2 = 2;
    }
  }


  while (val2 == 2) {
    val = digitalRead(inPin);
    if (val == HIGH)  {
      
      
      digitalWrite(ledPin, LOW);
      while (val == HIGH) {
        val = digitalRead(inPin);
      }
      val2 = 1;
    }
  }
}