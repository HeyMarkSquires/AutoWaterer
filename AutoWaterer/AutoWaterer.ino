#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
int val;
unsigned long currentTime;
unsigned long startTime;
unsigned long period=43200000;
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Hello there");
  startTime=millis();
  Serial.begin(9600);
  pinMode(13, OUTPUT);

}

void loop() {
  //Check the reading of the soil moisture sensor every hour. If it's below a certain level, water the plant.
  //Also, if it hasn't been watered in 12 hours, water it anyway.
  currentTime = millis();
  val = analogRead(A1);
  if (val<=430 || currentTime - startTime >= period){
    startTime = currentTime;  
    digitalWrite(13, HIGH); 
    delay(10000);
    digitalWrite(13, LOW);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(val);
  delay(3600000);
}
