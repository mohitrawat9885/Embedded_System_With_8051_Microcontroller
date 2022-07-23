#include<reg51.h>
#define LCD P2
sbit RS = P3^0;
sbit E = P3^1;

sbit smoke_led = P3^4;
sbit alcohol_led = P3^5;
sbit cng_led = P3^6;
sbit natural_gas_led = P3^7;

sbit smoke_sen = P1^0;
sbit alcohol_sen = P1^1;
sbit cng_sen = P1^2;
sbit natural_gas_sen = P1^3;


unsigned char smoke[14] = "Smoke Detected";
unsigned char alcohol[16] = "Alcohol Detected";
unsigned char cng_gas[16] = "CNG Gas Detected";
unsigned char natural_gas[20] = "Natural Gas Detected";

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
void main(){
	init_lcd();
	while(1){
		if(smoke_sen == 1){
			init_lcd();

			smoke_led = 1;
			alcohol_led = 0;
			cng_led = 0;
			natural_gas_led = 0;
						displayString(smoke);
			
	} else if(alcohol_sen == 1){
		init_lcd();
		
		smoke_led = 0;
			alcohol_led = 1;
			cng_led = 0;
			natural_gas_led = 0;
		displayString(alcohol);
		
} else if(cng_sen == 1){
	init_lcd();
			
			smoke_led = 0;
			alcohol_led = 0;
			cng_led = 1;
			natural_gas_led = 0;
	displayString(cng_gas);
	
} else if(natural_gas_sen == 1){
		init_lcd();
			
			smoke_led = 0;
			alcohol_led = 0;
			cng_led = 0;
			natural_gas_led = 1;
	displayString(natural_gas);
	
}
else{
		init_lcd();
			smoke_led = 0;
			alcohol_led = 0;
			cng_led = 0;
			natural_gas_led = 0;
}
}
}
		