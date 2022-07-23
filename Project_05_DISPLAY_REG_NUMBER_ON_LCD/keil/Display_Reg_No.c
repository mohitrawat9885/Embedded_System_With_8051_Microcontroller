#include<reg51.h>

	
void delay(unsigned int time){
	unsigned int i, j;
	for(i=0;i<=time;i++)
	for(j=0;j<=1275;j++);
}

void main(){
	
	unsigned char myReg[8] = {0xF9,0xF9,0x90,0xC0,0x99,0x99,0x82,0xB0};
	unsigned int i;
	P2 = 0x00;
	for(i=0;i<=7;i++){
		P2 = myReg[i];
		delay(100);
		P2 = 0xFF;
		delay(50);
	}
}