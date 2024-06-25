#include "State.h"


#define L1 33
#define L2 32

#define R1 22
#define R2 21

volatile extern uint8_t Input_Register;


void setup() {
  
  pinMode(L1,INPUT_PULLUP);
  pinMode(L2,INPUT_PULLUP);

  pinMode(R1,INPUT_PULLUP);
  pinMode(R2,INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(L1),FWD,RISING);
  attachInterrupt(digitalPinToInterrupt(L2),REV,RISING);
  attachInterrupt(digitalPinToInterrupt(R1),LEF,RISING);
  attachInterrupt(digitalPinToInterrupt(R2),RIG,RISING);

  Serial.begin(300);

}

void loop() {

if(((Input_Register>>W_IND)&0x01)==HIGH){
  Serial.print("W");
}
if(((Input_Register>>S_IND)&0x01)==HIGH){
  Serial.print("S");
}
if(((Input_Register>>A_IND)&0x01)==HIGH){
  Serial.print("A");
}
if(((Input_Register>>D_IND)&0x01)==HIGH){
  Serial.print("D");
}

Input_Register=0;

delay(50);
}
