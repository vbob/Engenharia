#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)
#use FIXED_IO(D_outputs=PIN_D0,PIN_D1,PIN_D2,PIN_D3,PIN_D4,PIN_D5,PIN_D6,PIN_D7)
#use FIXED_IO(E_outputs=PIN_E2)
#use FIXED_IO(B_outputs=PIN_B3, PIN_B4, PIN_B5)

#include <stdint.h>
byte steps[] = {
   0b00000001,
   0b00000010,
   0b00000100,
   0b00001000
};

#define COLUN1 PIN_B2
#define COLUN2 PIN_B1
#define COLUN3 PIN_B0
#define LINHA1 PIN_B5
#define LINHA2 PIN_B4
#define LINHA3 PIN_B3

int passo_direita = 0;
int vel_passo = 5;
int vel_cc = 5;

int pos = 0;

void girarMotores();

void scanPorts() {
   uint8_t ports[] = {0, PIN_B5, PIN_B4, PIN_B3 };

   for (int linha = 1; linha <= 3; linha++) {
      output_high(ports[1]);
      output_high(ports[2]);
      output_high(ports[3]);
      output_low(ports[linha]);
      
      if (linha == 2 && !input(COLUN2)) {
         passo_direita = !passo_direita;
         while (!input(COLUN2)) {
            girarMotores();
         }
      }
      
      if (linha == 3 && !input(COLUN3) && vel_passo > 1) {
         vel_passo--;
         while (!input(COLUN3)) {
            girarMotores();
         }
      }
      
      if (linha == 3 && !input(COLUN1) && vel_passo < 6) {
         vel_passo++;
         while (!input(COLUN1)) {
            girarMotores();
         }
      }
      
      if (linha == 1 && !input(COLUN3) && vel_cc > 1) {
         vel_cc--;
         while (!input(COLUN3)) {
            girarMotores();
         }
      }
      
      if (linha == 1 && !input(COLUN1) && vel_cc < 6) {
         vel_cc++;
         while (!input(COLUN1)) {
            girarMotores();
         }
      }
   }
}

void girarMotores() {
      if (vel_passo <= 5)
         output_d(steps[pos%4]);
      else
         output_d(0b0000000);
      
      if (passo_direita) {
         pos--;
      } else {
         pos++;
      }
   
      // ESSE DELAY DEVE SER PREENCHIDO PELO PWM
      uint16_t delay_us_passo = 1000 + (vel_passo*1000);
      
      // LARGURA_PULSO = 100us
      uint16_t delay_off_cc = 20*vel_cc;
      uint16_t delay_on_cc =  100-delay_off_cc;

      if (vel_cc == 6) {
         delay_off_cc = 100;
         delay_on_cc =  0;   
      }  

      uint16_t qtd_pulsos = delay_us_passo/100;

      for (uint16_t i = 0; i < qtd_pulsos; i++) {
         output_low(PIN_E2);
         delay_us(delay_off_cc);
         if (vel_cc < 6) 
            output_high(PIN_E2);
         delay_us(delay_on_cc);
      }

     // delay_us(1000 + (vel_passo*1000));
}
  
void main()
{
   port_B_pullups(0b11000111);  

      
   while(TRUE)
   {
      scanPorts();
      girarMotores();
   }
}


