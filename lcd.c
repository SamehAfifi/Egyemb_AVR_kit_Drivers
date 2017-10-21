/*
CMD :
1  // clr screen
2  // return to 0,0 line

4  // DEC  cursor shift cursor left
6  // INC  cursor shift cursor right

5  // shift display left
7  // shift display right

8  // display and cursor off
A  // display off cursor on
C  // display on cursor off
E  // display on cursor on

10 // shift cursor pos to left
14 // shift cursor pos to right

18 // shift display left
1C // shift display right

80 //force cursor to beginning of 1st line
C0 //force cursor to beginning of 2nd line

*/

#include "lcd.h"
uint8_t txt[5];

void lcd_init(){
	INIT_PORT;
// To clear Data on the LCD at Startup 
	D7(0);D6(0);D5(1);D4(1);
	lcd_send_pulse_for_update_data_or_cmd();
	D7(0);D6(0);D5(1);D4(0);
	lcd_send_pulse_for_update_data_or_cmd();
	_delay_ms(5);
////// Start send Commands
	lcd_write_cmd(0x2);
	lcd_write_cmd(0x28);  // 4data line
	lcd_write_cmd(0x01);
	lcd_write_cmd(0x0c);  // display on cursor off
	lcd_write_cmd(0x06);  // increment cursor right
	lcd_write_cmd(clear);  // set courser at the beginning of the first line
	_delay_ms(20);
}

void lcd_write(uint8_t cmd){
	// read first 4 bit
	D7(READBIT(cmd,7)); 
	D6(READBIT(cmd,6));
	D5(READBIT(cmd,5));
	D4(READBIT(cmd,4));

	lcd_send_pulse_for_update_data_or_cmd();

	// read second 4 bit
	D7(READBIT(cmd,3));
	D6(READBIT(cmd,2));
	D5(READBIT(cmd,1));
	D4(READBIT(cmd,0));

	lcd_send_pulse_for_update_data_or_cmd();
}


void lcd_write_cmd(uint8_t cmd){
	RS(0); // Rs = 0
	lcd_write(cmd);
}

void lcd_write_char(uint8_t cmd){
	RS(1); // Rs = 1
	lcd_write(cmd);
}



void lcd_write_txt(uint8_t *x){
	for(int i = 0; x[i] != '\0'; i++)
		lcd_write_char(x[i]);
}



void lcd_write_number(uint16_t data){
	IntToString(data,txt);
	lcd_write_txt(txt);
}

void IntToString(uint16_t number, uint8_t *txt){
	
	if(number < 10){
		txt[0] = number % 10 + 48;
		txt[1] = '\0';
	}
	else if(number < 100){
		txt[0] = number / 10 + 48;
		txt[1] = number % 10 + 48;
		txt[2] = '\0';
	}
	else if(number < 1000){
		txt[0] = number / 100 + 48;
		number = number % 100 ;
		txt[1] = number / 10 + 48;
		txt[2] = number % 10 + 48;
		txt[3] = '\0';
	}
	else  if(number < 10000){
		txt[0] = number / 1000 + 48;
		number = number % 1000 ;
		txt[1] = number / 100 + 48;
		number = number % 100 ;
		txt[2] = number / 10 + 48;
		txt[3] = number % 10 + 48;
		txt[4] = '\0';
	}
	else  if(number < 100000){
		txt[0] = number / 10000 + 48;
		number = number % 10000 ;
		txt[1] = number / 1000 + 48;
		number = number % 1000 ;
		txt[2] = number / 100 + 48;
		number = number % 100 ;
		txt[3] = number / 10 + 48;
		txt[4] = number % 10 + 48;
		txt[5] = '\0';
	}
}

void lcd_send_pulse_for_update_data_or_cmd(){
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
}
