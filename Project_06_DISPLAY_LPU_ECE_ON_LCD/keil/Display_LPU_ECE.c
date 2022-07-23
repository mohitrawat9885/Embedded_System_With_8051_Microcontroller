#include<reg51.h>
sbit key = P1^0;
	
void delay(unsigned int time){
	unsigned int i, j;
	for(i=0;i<=time;i++)
	for(j=0;j<=1275;j++);
}

void main(){
	unsigned char myReg[6] = {0x71,0x18,0x41,0x30,0x31,0x30};
	unsigned int i;
	key = 1;
	P2 = 0x00;
	while(1){
		if(key == 1){
			for(i=0;i<=2;i++){
				P2 = myReg[i];
				delay(100);
				P2 = 0xFF;
				delay(50);
	}
}
		else{
			for(i=3;i<=5;i++){
				P2 = myReg[i];
				delay(100);
				P2 = 0xFF;
				delay(50);
		}
	}
}
}