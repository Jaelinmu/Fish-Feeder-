#include <LiquidCrystal.h>

const int rs = 12, es = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, es, d4, d5, d6, d7);

void setup() {
    lcd.begin(16, 2);
    lcd.print("hello fish");
}

void loop() {
    lcd.noDisplay();
    delay(5000);
    lcd.display();
    delay(5000);
}