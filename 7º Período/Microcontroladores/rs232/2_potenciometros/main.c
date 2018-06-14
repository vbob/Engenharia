#include <16F877A.h>
#device ADC=10

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=16000000)
#use rs232(baud=2400,parity=E,xmit=PIN_C6,rcv=PIN_C7,bits=8,stream=PORT1)


void main()
{
   setup_adc_ports(AN0_AN1_AN3);
   setup_adc(ADC_CLOCK_DIV_32);
   
   long value;
   int bit1 = 0;
   int bit2 = 0;
   
   while(TRUE)
   {
      set_adc_channel(0);
      delay_ms(1);
      value=read_adc();
      bit1 = value&11110000;
      bit2 = value<<6;
      putc(value);
      delay_ms(1000);
   }
}
