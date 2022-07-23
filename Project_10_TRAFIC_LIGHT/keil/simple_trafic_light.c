#include<reg51.h>
sbit R1 = P2^0;
sbit O1 = P2^1;
sbit G1 = P2^2;

sbit R2 = P2^3;
sbit O2 = P2^4;
sbit G2 = P2^5;

void delay(unsigned int time){
	unsigned int i, j;
	for(i=1;i<=time;i++)
		for(j=1;j<=1275;j++);
	
}

void main(){
	while(1){
		R1 = 0;
		O1 = 0;
		G1 = 1;
		R2 = 1;
		O2 = 0;
		G2 = 0;
		delay(500);
		R1 = 0;
		O1 = 1;
		G1 = 0;
		R2 = 0;
		O2 = 1;
		G2 = 0;
		delay(500);
		R1 = 1;
		O1 = 0;
		G1 = 0;
		R2 = 0;
		O2 = 0;
		G2 = 1;
		delay(500);
		R1 = 0;
		O1 = 1;
		G1 = 0;
		R2 = 0;
		O2 = 1;
		G2 = 0;
		delay(500);
	}
}