#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
int val;
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Hello there");
  Serial.begin(9600);
  pinMode(13, OUTPUT);

}

void loop() {
  //Check the reading of the soil moisture sensor every five minutes. If it's below a certain
  //level, water the plant
  val = analogRead(A1);
  Serial.println(val);
  if (val<=365){
    digitalWrite(13, HIGH); 
    delay(5000);
    digitalWrite(13, LOW);
  }
  else{
    digitalWrite(13, LOW);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(val);
  delay(600000);
}
