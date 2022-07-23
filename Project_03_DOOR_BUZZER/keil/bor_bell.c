#include<reg51.h>
sbit a = P1^1;
sbit b = P1^2; 
sbit c = P1^3;
sbit d = P1^4;


void main(){
	P2 = 0xFF;
	P3 = 0x00;
	a = 1;
	b = 0;
	c = 0;
	d = 1;
	while(1){
	}
}