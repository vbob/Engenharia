#include <main.h>
#include <stdint.h>

void main()
{
   while(TRUE)
   {
      // Should take 3000ms
      // Each 100ms it should update the Pulse Width
      output_low(PIN_C2);
      // External Loop
      // 30 times
      for (uint16_t i = 0; i < 30; i++) {
         // Internal loop
         // Should take 100ms
         for (uint16_t j = 0; j < 100; j++) {
            output_high(PIN_C2);
            delay_us(i*(1000/30));
            output_low(PIN_C2);
            delay_us(1000-(i*(1000/30)));
         }
      }
   }

}
