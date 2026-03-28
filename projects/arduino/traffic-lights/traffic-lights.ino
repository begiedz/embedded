// 2: red, 3: blue, 4: green
const int pins[] = {2, 3, 4};
const int time = 1000;

void setup() {
  for (int pin : pins) {
    pinMode(pin, OUTPUT);
  }
}

void start(){
  digitalWrite(2, HIGH);
  delay(time);
  digitalWrite(3, HIGH);
  delay(time);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(time*2);
}

void end(){
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  delay(time);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  delay(time);
}

void loop() {
 start();
 end();
}
