#include<reg51.h>
#define LCD P3
sbit RS = P2^0;
sbit E  = P2^1;
sbit IR = P2^2;

void delay(unsigned int time){
	unsigned i, j;
	for(i=1;i<=time;i++)
	for(j=1;j<=1275;j++);
}
void lcd_command(unsigned char c){
	LCD = c;
	RS = 0;
	E = 1; 
	delay(10);
	E = 0;
}
void lcd_data(unsigned char *d){
	unsigned int i = 0;
	while(d[i] != '\0'){
		LCD = d[i];
		RS = 1;
		E = 1;
		delay(10);
		E = 0;
		i++;
	}
}
void init_lcd(){
	lcd_command(0x38); //Use 16x2 8bit LCD
	lcd_command(0x0f); //Display on cursor blink
	lcd_command(0x01); //Clear LCD
	//lcd_command(0x85);
}

void main(){
	unsigned char on[13] = "Object found";
	unsigned char off[10] = "No Object";
	init_lcd();
	if(IR == 1){
		lcd_data(on);
	}
	else{
		lcd_data(off);
	}
}