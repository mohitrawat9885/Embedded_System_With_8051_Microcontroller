#include<reg51.h>

void main(){
	P1 = 0xFF;
	P3 = 0x00;
	P2 = 0x00;
	while(1){
		if(P1 < 0x64){
			P3 = P1;
			P2 = 0;
		}
		else{
			P2 = P1;
			P3 = 0;
		}
	}
}