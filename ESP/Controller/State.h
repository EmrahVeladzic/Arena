#ifndef STATE
#define STATE

#define W_IND 3
#define A_IND 2
#define S_IND 1
#define D_IND 0

enum Input{

W_VAL = 0x08,
A_VAL = 0x04,
S_VAL = 0x02,
D_VAL = 0x01

};

volatile uint8_t Input_Register;


void FWD(){

if((Input_Register & W_VAL)==LOW){

    Input_Register|=W_VAL;

  }

}

void LEF(){

if((Input_Register & A_VAL)==LOW){

    Input_Register|=A_VAL;

  }

}

void REV(){

if((Input_Register & S_VAL)==LOW){

    Input_Register|=S_VAL;

  }

}

void RIG(){

if((Input_Register & D_VAL)==LOW){

    Input_Register|=D_VAL;

  }

}

#endif