#include<reg51.h>
sbit IR_IN = P2^0;
sbit IR_OUT = P2^1;

void delay(unsigned char time){
	unsigned int i, j;
	for(i=1;i<=time;j++)
	for(j=1;j<=1257;j++);
}

void main(){
	if(IR_IN == 1){
		IR_OUT = 1;
	}
	else{
		IR_OUT = 0;
	}
}