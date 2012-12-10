#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

void setup(){
  
 lcd.begin(20, 4);
  
 Serial.begin(9600); 
  
}

void loop(){
  
  lcd.clear();
  
  lcd.setCursor(0, 0);
  
  lcd.print(F("Teste ArWSGDFHFGHVFDduitter"));
  
  while(1);
  
}
