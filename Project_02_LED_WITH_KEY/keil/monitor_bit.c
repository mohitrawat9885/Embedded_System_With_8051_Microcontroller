#include<reg51.h>
sbit p1_5 = P1^5;
void main(void){
	p1_5 = 1;
	while(1){
		if(p1_5 == 1){
			P0 = 0x55;
			P2 = 0x00;
		}
		else{
			P0 = 0x00;
			P2 = 0xAA;
		}
	}
}