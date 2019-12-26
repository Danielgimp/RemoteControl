#include <IRremote.h>
#include "LowPower.h"
IRsend irsend;
const int button1 = 4; //Vol+
const int button2 = 5; //Switch
const int button3 = 6; //Vol-
char input;
int timer;

void wakeUp(){
 timer = 0;
}

void setup() {
  Serial.begin(9600); 
  delay(2000);
  pinMode(button1, INPUT);
  pinMode(3, OUTPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  timer = 0;
  Serial.println("Type new number");
}

void loop() {
  /*
  if(Serial.available()){
  input = Serial.read();
  if(input=='1') 
  {
  irsend.sendNEC(0x44444, 32);
  delay(2000);
  input='0';
  }
  else if(input=='2') 
  {
  irsend.sendNEC(0x88888, 32);
  delay(2000);
  input='0';
  }
  else if(input=='3') 
  {
  irsend.sendNEC(0xbbbbbb, 32);
  delay(2000);
  input='0';
  }
  }
  */
  
  attachInterrupt(0,wakeUp, HIGH);
  while (timer < 3000){
  if (digitalRead(button1) == HIGH){
  timer = 0;  
  delay(500);
  irsend.sendNEC(0x34895725, 32);
  } //Vol+

  if (digitalRead(button2) == HIGH){
  timer = 0;
  delay(50);
  irsend.sendNEC(0x56874159, 32);} //Switch

  if (digitalRead(button3) == HIGH){
  timer = 0;
  delay(50);
  irsend.sendNEC(0x15467823, 32);} //Vol-
  
   delay(1);
   timer = timer + 1;
  
}
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);}
   
