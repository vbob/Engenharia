#include <16F628A.h>
#include <stdint.h>

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)
#use rs232(baud=9600,parity=N,xmit=PIN_B2,rcv=PIN_B1,bits=8,stream=PORT1)


void main()
{
   int i = 20;
   char buf[16];
   sprintf(buf, "%d\n", i);
   while(TRUE)
   {
      puts(buf);
   }

}
