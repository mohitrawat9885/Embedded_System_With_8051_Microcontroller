#include<reg51.h>
#define LCD P3
sbit RS = P2^0;
sbit E  = P2^1;

void delay(unsigned char time){
	unsigned i, j;
	for(i=1;i<=time;i++)
	for(j=1;j<=1257;j++);
}
void lcd_command(unsigned char c){
	LCD = c;
	RS = 0;
	E = 1;
	delay(10);
	E = 0;
}
void lcd_data(unsigned char c){
	LCD = c;
	RS = 1;
	E = 1;
	delay(10);
	E = 0;
}
void init_lcd(){
	lcd_command(0x38); //Use 16x2 8bit LCD
	lcd_command(0x0f); //Display on cursor blink
	lcd_command(0x01); //Clear LCD
	lcd_command(0x85);
}

void main(){
	unsigned char d[4] = "LPU";
	unsigned int i = 0;
	init_lcd();
	while(d[i] != '\0'){
		lcd_data(d[i]);
		i++;
		delay(10);
	}
}