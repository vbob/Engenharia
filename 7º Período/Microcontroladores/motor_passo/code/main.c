#include <main.h>

byte steps[] = {
   0b00000001,
   0b00000010,
   0b00000100,
   0b00001000
};

int direita = 0;

#INT_EXT
void  EXT_isr(void) 
{
   direita = !direita;
}

void main()
{
   port_B_pullups(0xFF);
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);
   ext_int_edge(L_TO_H);
   
   int i = 0;
      
   while(TRUE)
   {
      output_d(steps[i%4]);
      
      if (direita) {
         i--;
      } else {
         i++;
      }
      
      delay_ms(10);
   }
}
