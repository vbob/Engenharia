#include <16F877A.h>
#include <stdint.h>

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=16000000)
#use rs232(baud=1200, PARITY=E, UART1, stream=PC, ERRORS)
 
char character; 
long count = 0;

#int_rda 
void interrupt_from_rx(void) 
{ 
   putc(getc());
   putc(count);
} 

void main(void) 
{ 
   enable_interrupts(INT_RDA); 
   enable_interrupts(GLOBAL);

   while(true) 
   { 
       
   } 
} 


