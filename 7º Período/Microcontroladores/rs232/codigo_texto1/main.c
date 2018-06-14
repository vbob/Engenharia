#include <16F628A.h>
#include <stdint.h>

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)
#use rs232(baud=2400,parity=N,xmit=PIN_B2,rcv=PIN_B1,bits=8,stream=Wireless)

#INT_RDA
void  RDA_isr(void) 
{
   putc(getc());  
}

void main()
{
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
}
