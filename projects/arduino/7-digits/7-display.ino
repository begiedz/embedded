// całość zadania
/*
  3 -> B = góra prawo
  4 -> D = dół
  5 -> G = środek
  6 -> A = góra
  7 -> E = dół lewo
  8 -> F = góra lewo
  9 -> C = dół prawo
*/

void showDigit(int digit) {
  switch (digit) {
    case 0:
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      break;
    case 1:
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      break;
    case 2:
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      break;
    case 3:
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      break;
    case 4:
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      break;
    case 5:
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      break;
    case 6:
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      break;
    case 7:
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      break;
    case 8:
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      break;
    case 9:
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      break;
    case 10:
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      break;
  }
}

void showFirstDigit(int digit) {
  digitalWrite(10, LOW);   // aktywacja pierwszej cyfry
  digitalWrite(11, HIGH);  // deaktywacja drugiej cyfry

  showDigit(digit);
}

void showSecondDigit(int digit) {
  digitalWrite(10, HIGH);  // deaktywacja pierwszej cyfry
  digitalWrite(11, LOW);   // aktywacja drugiej cyfry

  showDigit(digit);
}

void showDualDigit(int first, int second) {
  showFirstDigit(first);
  delay(10);

  showSecondDigit(second);
  delay(10);
}

// #######################################

void setup() {
  Serial.begin(9600);

// przypisanie pinów od 3 do 11
  for (int i = 3; i <= 11; i++) {
    pinMode(i, OUTPUT);
  }

// pętla iterująca po kazdej z cyfr od 0 do "10" - pustej
  for (int i = 1; i <= 10; i += 2) {
    // unsigned long - duza dodanie liczba całkowita
    // zapamiętuje aktualny czas jako punkt początkowy
    unsigned long start = millis();

// powtarza to co jest w pętli przez 500ms
    while (millis() - start < 500) {
      showDualDigit(i, i + 1);
    }
  }

  delay(1000);

// pokazanie numeru indeksu
  {
    unsigned long start = millis();
    while (millis() - start < 500) {
      showDualDigit(5, 1);
    }
  }

  {
    unsigned long start = millis();
    while (millis() - start < 500) {
      showDualDigit(2, 7);
    }
  }

  {
    unsigned long start = millis();
    while (millis() - start < 500) {
      showFirstDigit(6);
    }
  }

  delay(1000);
}
// aktywacja zczytywania z potencjometru
void loop() {
  int sensorValue = analogRead(A0);
  // mapowanie zakresu wartości z 0-1023 do 0-50
  int voltage = map(sensorValue, 0, 1023, 0, 50);

  Serial.println(voltage);

  int decimal = voltage / 10;
  int unit = voltage % 10;

  if (voltage < 20) {
    // static by zmienna nie resetowała się po kolejnej iretacji loop()
    static unsigned long lastToggleTime = 0;
    static bool isOn = false;

    if (millis() - lastToggleTime >= 250) {
      lastToggleTime = millis();
      isOn = !isOn;
    }
// jeśli wyświetlacz jest włączony to pokaz liczby i na odwrót
    if (isOn) {
      showDualDigit(decimal, unit);
    } else {
      showDualDigit(10, 10);
    }
  } else {
    showDualDigit(decimal, unit);
  }
}
