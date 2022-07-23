#include<reg51.h>
sbit p1_5 = P1^5;
void main(void){
	while(1){
		if(p1_5 == 1){
			P0 = 0x55;
		}
		else{
			P2 = 0xAA;
		}
	}
}