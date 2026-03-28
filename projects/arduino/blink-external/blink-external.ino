// blink with external diode blink
int port = 2;

void setup() {
  pinMode(port, OUTPUT);
}

void loop() {
  digitalWrite(port, HIGH);
  delay(250);
  digitalWrite(port, LOW);
  delay(250);
}
