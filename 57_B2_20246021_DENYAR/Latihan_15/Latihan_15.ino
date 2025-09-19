#define led1 11
#define p1 A1
#define p2 A4

int a;
int b;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  a = analogRead(p1);
  b = map(a, 0, 1023, 20, 500);

  Serial.print("Data awal: ");
  Serial.println(a);

  Serial.print("After Map: ");
  Serial.println(b);

  delay(200);

}
