#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20 ,4);

  void setup() {
    lcd.init();
    lcd.backlight();
  }

  void loop() {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("14 kawalkow");
    lcd.setCursor(0,1);
    lcd.print("chrupiacego kurczaka");
    lcd.setCursor(0,2);
    lcd.print("TYLKO 14,95 PLN!");
    lcd.setCursor(0,3);
    lcd.print("- odbierz na wynos");
    delay(2000);
    
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Odwiedz -");
    lcd.setCursor(0,3);
    lcd.print("https://begiedz.dev");
    delay(2000);
  }
