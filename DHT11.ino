#include"DHT.h"
#include<LiquidCrystal.h>
const int PINDHT=7;
const int DHTTYPE=DHT11;
DHT dht(PINDHT,DHTTYPE);
LiquidCrystal lcd(12,11,5,4,3,2);

int led1=8,led2=9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  float doam=dht.readHumidity();
  float nhietdo=dht.readTemperature();
  
  if(doam<80)
  {
      digitalWrite(led1,HIGH);
      digitalWrite(led2,LOW);
  }

  else if(doam>80)
  {
      digitalWrite(led2,HIGH);
      digitalWrite(led1,LOW);
  }

  lcd.setCursor(0,0);
  lcd.print("NHIET DO: ");
  lcd.print(nhietdo);

  lcd.setCursor(0,1);
  lcd.print("DO AM: ");
  lcd.print(doam);
}
