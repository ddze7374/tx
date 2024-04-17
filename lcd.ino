#include <LiquidCrystal_I2C.h>
int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void setup(){
  lcd.init();                    
  lcd.backlight();
}

void loop(){
  lcd.setCursor(0, 0);
  lcd.print("Maarif School");
  lcd.setCursor(0,1);
  lcd.print("NPI - 2024");
  delay(1000);
  lcd.clear(); 
}
