#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define numLines 4
#define numRows 20
#define NL 10

char message[80]; // Maximum number of caracters supported by lcd display

void setup(){
  
 lcd.begin(numRows, numLines);
  
 Serial.begin(9600); 
  
}

int receiveMessage(){
  
  boolean flagEndOfMenssage; // End message flag
  int i;
  
  flagEndOfMenssage=0;
  i=0;
  
  while (!flagEndOfMenssage) {
    if (Serial.available()) {
      message[i] = Serial.read();
      if (message[i]==NL) {
        message[i+1] = 0;
        flagEndOfMenssage = 1;
      }
      i++;      
    }
  }
  
  return (i);
  
}

void printMessage(int numberOfCaracters){
  
//  char singleLineTemp
  
  lcd.clear();
  
  lcd.setCursor(0,0);
  
  lcd.print(message);
  
  lcd.setCursor(0,1);
  
  lcd.print(numberOfCaracters);
  
  lcd.print(" caracteres");
  
  return;  
  
}

void loop(){
  
  printMessage (receiveMessage ());  
  
}
