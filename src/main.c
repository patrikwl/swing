/*
 * accel.c
 *
 * Created: 2020-11-03 12:29:04
 * Author : patrik	
 */ 
#define F_CPU 8000000UL //1MHz standard
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <util/delay.h>

#define SPI_DDR DDRB
#define CS      PINB2
#define MOSI    PINB3
#define MISO    PINB4
#define SCK     PINB5

// READ 11, WRITE 01
#define SENSOR 0x53
#define BR 0b00101100 // 0x2c =0b101100 
#define Data_Format 0b01110001 //    0x31=0b110001
#define Power_Register 0b00101101 // 0x2d =0b101101 ORIG. 0b01101101
#define X_Axis_Register_DATAX0 0b11110010 //Z NU - 010 X0 Hexadecima address for the DATAX0 internal register. 0b110010
#define X_Axis_Register_DATAX1 0b11110011 // Hexadecima address for the DATAX1 internal register. 0x33 =0b110011
#define X_Off 0b0111110 // 0x1E =0b11110

#define INT_MAP 0b01101111 //0x2f =0b101111
#define INT_ENABLE 0b01101110 //0x2E =0b101110
#define INT_SOURCE 0b10110000 //0x30 =0b110000 read only

#define BAUD_RATE 1 //12



//#include "lcd.h"

volatile uint8_t x0; //LSBy
volatile uint8_t x1; //MSBy
volatile uint8_t r_data;
volatile int16_t x_out;
volatile uint8_t i =0;
volatile uint8_t r_data;

uint8_t SPI_masterTxRx(uint8_t data)
{
	// transmit data
	SPDR = data;
	// Wait for reception complete	
	while(!(SPSR & (1 << SPIF)));
	// return Data Register
	return SPDR;
}

ISR (INT1_vect){
	PORTB |= (1<<PB0); //LED ON
	PORTB &= ~(1 << CS);
	//SPI_DDR &= ~(1 << CS);
	SPI_masterTxRx(X_Axis_Register_DATAX0);
	x0 = SPI_masterTxRx(0xFF);
	x1 = SPI_masterTxRx(0xFF);
	//x1 = SPI_masterTxRx(0xFF);
	//SPI_DDR |= (1 << CS);
	PORTB |= (1 << CS);
	/*_delay_ms(1);
	PORTB &= ~(1 << CS);
	//SPI_DDR &= ~(1 << CS);
	SPI_masterTxRx(INT_SOURCE);
	SPI_masterTxRx(0xFF);
	PORTB |= (1 << CS);
	*/
	//UCSR0A &= ~(1<<FE0)|~(1<<DOR0)|~(1<<UPE0); //?????????????????
	x_out = (x1 << 8) | x0;
				
	//char* data  = malloc( 10 + 1 );
	//snprintf( data, 11, "%d", x_out );
	char data[8];			
	//int length = snprintf( NULL, 0, "%d", x_out );
	//char* data  = malloc( length + 1 );
	snprintf( data, 8, "%d", x_out );
				
	i = 0;
	while(data[i] != 0){
		while (!( UCSR0A & (1<<UDRE0))); /* Wait for empty transmit buffer*/
		UDR0 = data[i];            /* Put data into buffer, sends the data */
		i++;                             /* increment counter           */
	}
	//free(data);
	/* Sending '\n'  '\r' Character pair helps to format the output properly on console putty Screen */
	/*************************************************************************************************/
	/* Send "\n" Character */
	while (!( UCSR0A & (1<<UDRE0)));   /* Wait for empty transmit buffer       */
		UDR0 = '\n';					    /* Put data into buffer, sends the data */
				
	/* Send "\r" Character */
	while (!( UCSR0A & (1<<UDRE0)));   /* Wait for empty transmit buffer       */
		UDR0 = '\r';
		
	PORTB &= ~(1<<PB0); //LED OFF
}








/*ISR(USART_RX_vect){
	while (!(UCSR0A & (1<<RXC0))){
	r_data = UDR0;
	}
	if(flag==true){
		flag=false;
	}
	else{
		flag=true;
	}
}*/
	
int main(void)
{	
	
	
	//USART SETTINGS
	UCSR0B |= (1<<TXEN0)|(1<<RXEN0); //enable,, transmission & reciever
	UCSR0C |=(1<<UCSZ01) | (1<<UCSZ00); //set 8 bit transmissions
	uint8_t ubrr = BAUD_RATE;
	UBRR0H = (ubrr>>1);
    UBRR0L = (ubrr);	 
	
	//Set led pin as output
	DDRB |= (1 << PB0);
	DDRD &= ~(1 << PD3); //D3 as input
	//PORTB |= (1<<PB0); //LED ON
	PORTD &= (0 << PD3);
	_delay_ms(500);
	//enable clock to SPI module
	PRR &= ~(1 << PRSPI); 
	
	// enable SPI, set as master, and clock to fosc/128
	SPCR |= (1 << SPE) | (1 << MSTR) | (1 << CPOL) |(1<<CPHA);
	SPSR |=(1<<SPI2X);
	SPCR &= ~(1<<DORD) | ~(1<<SPR1) | ~(1 << SPR0);
	//SPCR |= (1 << SPE) |~(1<<DORD)| (1 << MSTR) | (1 << CPOL) |(1<<CPHA)|(0 << SPR1)| (0 << SPR0);
	
	// set CS, MOSI and SCK to output
	SPI_DDR |= (1 << CS) | (1 << MOSI) | (1 << SCK);
	
	//SPI_masterTransmit(Power_Register);
	_delay_ms(10);
	
	//read Data_Format
	PORTB &= ~(1 << CS);
	SPI_masterTxRx(Data_Format);
	SPI_masterTxRx(0b00000111);
	PORTB |= (1 << CS);
	_delay_ms(100);
	
	//set up int enable on accel
	PORTB &= ~(1 << CS);
	//SPI_DDR &= ~(1<<CS);
	SPI_masterTxRx(INT_ENABLE);
	SPI_masterTxRx(0b10000000);
	//SPI_DDR |= (1<<CS);
	PORTB |= (1 << CS);		
	_delay_ms(100);
		
	PORTB &= ~(1 << CS);
	//SPI_DDR &= ~(1<<CS);
	SPI_masterTxRx(INT_MAP);
	SPI_masterTxRx(0b10000000); //enable on int2 pin
	//SPI_DDR |= (1<<CS);
	PORTB |= (1 << CS);
	_delay_ms(100);
	
	PORTB &= ~(1 << CS);
	//SPI_DDR &= ~(1<<CS);
	SPI_masterTxRx(Power_Register);
	SPI_masterTxRx(0x08); 
	//SPI_DDR |= (1<<CS);
	PORTB |= (1 << CS);	
	
	_delay_ms(100);
	
	PORTB &= ~(1 << CS);
	//SPI_DDR &= ~(1<<CS);
	SPI_masterTxRx(BR);
	SPI_masterTxRx(0b00001111);
	//SPI_DDR |= (1<<CS);
	PORTB |= (1 << CS);
	
	_delay_ms(100);

	EICRA |= (1<<ISC11) | (1<<ISC10); //set rising edge int on int1
	EIMSK |= (1<<INT1); //enable interrupt on int1
	
	PORTB &= ~(1 << CS);
	//SPI_DDR &= ~(1 << CS);
	SPI_masterTxRx(INT_SOURCE);
	SPI_masterTxRx(0xFF);
	PORTB |= (1 << CS);
	
	sei();	
	PORTB &= ~(1 << CS);
	//SPI_DDR &= ~(1 << CS);
	SPI_masterTxRx(X_Axis_Register_DATAX0);
	SPI_masterTxRx(0xFF);
	SPI_masterTxRx(0xFF);
	PORTB |= (1 << CS);

	while(1){
	PORTB |= (1<<PB0); //LED ON
	_delay_ms(1000);	
	PORTB &= ~(1<<PB0); //LED OFF
	_delay_ms(1000);	
	}
	// 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
}


