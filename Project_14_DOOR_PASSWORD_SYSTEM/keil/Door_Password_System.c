#include<reg51.h>
#define LCD P2
sbit RS = P3^0;
sbit E = P3^1;

sbit key_r1 = P1^0;
sbit key_r2 = P1^1;
sbit key_r3 = P1^2;
sbit key_r4 = P1^3;

sbit key_c1 = P1^4;
sbit key_c2 = P1^5;
sbit key_c3 = P1^6;

sbit door_motor = P1^7;

unsigned char pin[] = {"9885"};
unsigned char epin[4];

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
void print(unsigned char d){
		LCD = d;
		RS = 1;
		E = 1;
		delay(4);
		E = 0;
}
void init_lcd(){
	lcd_command(0x38);
	lcd_command(0x01);
	lcd_command(0x06);
	lcd_command(0x0c);
	lcd_command(0x80);
}
void printl(unsigned char* str){
	unsigned int i=0;
	while(str[i] != '\0'){
		print(str[i]);
		i++;
	}
}

unsigned char GetKey(){
	while(1){
		key_r1 = 0;
		key_r2 = 1;
		key_r3 = 1;
		key_r4 = 1;
		if(key_c1 == 0){
			return '1';
		}
		if(key_c2 == 0){
			return '2';
		}
		if(key_c3 == 0){
			return '3';
		}
		key_r1 = 1;
		key_r2 = 0;
		key_r3 = 1;
		key_r4 = 1;
		if(key_c1 == 0){
			return '4';
		}
		if(key_c2 == 0){
			return '5';
		}
		if(key_c3 == 0){
			return '6';
		}
		key_r1 = 1;
		key_r2 = 1;
		key_r3 = 0;
		key_r4 = 1;
		if(key_c1 == 0){
			return '7';
		}
		if(key_c2 == 0){
			return '8';
		}
		if(key_c3 == 0){
			return '9';
		}
		key_r1 = 1;
		key_r2 = 1;
		key_r3 = 1;
		key_r4 = 0;
		if(key_c1 == 0){
			return '*';
		}
		if(key_c2 == 0){
			return '0';
		}
		if(key_c3 == 0){
			return '#';
		}
		delay(20);
	}
}

void checkPassword(){
	init_lcd();
	if(epin[0] == pin[0] && epin[1] == pin[1] && epin[2] == pin[2] && epin[3] == pin[3]){
		printl("Correct PIN");
		door_motor = 1;
		lcd_command(0xc0);
		printl("Door Opened");
	}
	else{
		printl("Incorrect PIN");
		lcd_command(0xc0);
		printl("Try Again Later");
	}
	delay(1000);
	door_motor = 0;
}

void main(){
while(1){
	unsigned int i = 0;
	door_motor = 0;
	init_lcd();
	printl("Enter Door PIN");
	lcd_command(0xc0);
	while(pin[i] != '\0'){
	  epin[i] = GetKey();
		print('*');
		delay(50);
		i++;
	}
	checkPassword();
}
}
