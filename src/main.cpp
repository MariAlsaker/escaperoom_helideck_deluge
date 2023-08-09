#include <Arduino.h>
#include <LiquidCrystal.h>

#define REED1 9
#define REED2 8
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

uint32_t timer = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(REED1, INPUT);
  pinMode(REED2, INPUT);
  //Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Manual operation");
  lcd.setCursor(0,1);
  lcd.print("required");
  timer = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis()-timer > 100){ // Only every 100 ms
    timer = millis();
    if(digitalRead(REED1)&&digitalRead(REED2)){
      lcd.clear(); // Maybe we don't need clear
      lcd.print("Deluge started");
      lcd.setCursor(0,1);
      lcd.print("code: 392");
    }
    else{
      lcd.clear(); // Maybe we don't need clear
      lcd.print("Manual operation");
      lcd.setCursor(0,1);
      lcd.print("required"); 
    }
  }
  
}