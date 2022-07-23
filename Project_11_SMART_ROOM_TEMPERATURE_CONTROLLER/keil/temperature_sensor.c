#include<reg51.h>
#define LCD P2
sbit RS = P3^0;
sbit E = P3^1;
sbit rd = P3^5;
sbit wr = P3^6;
sbit intr = P3^7;

sbit ir = P0^0;

sbit Ac = P3^2;
sbit Cooler = P3^3;
sbit Fan = P3^4;

unsigned char ac_str[17] = "AC is ON        ";
unsigned char cooler_str[17] = "Cooler is ON    ";
unsigned char fan_str[17] = "Fan is ON       ";
unsigned char winter_str[17] = "Winters are near!";
unsigned char empty_str[17] = "Room is Empty!  ";

void delay(unsigned int time){
	unsigned int i, j;
	for(i=1;i<time;i++)
	for(j=1;j<1275;j++);
}

void lcd_command(unsigned char c){
	LCD = c;
	RS = 0;
	E = 1; 
	delay(4);
	E = 0;
}
void lcd_print(unsigned char d){
		LCD = d;
		RS = 1;
		E = 1;
		delay(4);
		E = 0;
}
void init_lcd(){
	lcd_command(0x38); //Use 16x2 8bit LCD
	lcd_command(0x01);
	lcd_command(0x06); //Clear LCD
	lcd_command(0x0c);
	lcd_command(0x81);
}
void displayString(unsigned char* str){
	unsigned int i=0;
	while(str[i] != '\0'){
		lcd_print(str[i]);
		i++;
	}
}
void SetAcFanCooler(unsigned int v){
	lcd_command(0x80);
	
	if(v >=50 && ir == 1){
			Ac = 1;
			Cooler = 0;
			Fan = 0;
		displayString(ac_str);
}
	else if(v >= 40 && v < 50 && ir == 1){
			Cooler = 1;
			Ac = 0;
			Fan = 0;
		displayString(cooler_str);
		}
		else if(v <40 && v >= 30&& ir == 1){
			Fan  = 1;
			Ac = 0;
			Cooler = 0;
			displayString(fan_str);
		}
		else if(ir == 1){
			Ac = 0;
			Cooler = 0;
			Fan = 0;
		displayString(winter_str);
		}
		else{
			Ac = 0;
			Cooler = 0;
			Fan = 0;
			displayString(empty_str);
		}
}

void main(){
	unsigned char tp[16] = "Temperature is: ";
	unsigned int i=0;
	unsigned char v, d3, d2, d1;
	init_lcd();
	while(1){
		wr = 0;
		wr = 1;
		while(intr);
		rd = 0;
		v = P1;
		SetAcFanCooler(v);
		lcd_command(0xc6);
		d3 = v%10;
		v = v/10;
		d2 = v%10;
		v = v/10;
		d1 = v%10;
		lcd_print(d1+0x30);
		lcd_print(d2+0x30);
		lcd_print(d3+0x30);
		lcd_print(0xDF);
		lcd_print('C');
		rd =1;
	}
}
		