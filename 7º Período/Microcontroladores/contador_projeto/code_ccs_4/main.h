#include <16F628A.h>

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)
#use FIXED_IO( B_outputs=PIN_B2,PIN_B3 )

