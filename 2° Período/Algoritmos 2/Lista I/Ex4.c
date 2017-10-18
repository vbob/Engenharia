// Os 20 primeiros termos de fibonacci

#include <stdio.h>
#define NTERMOS 20

int main() {
	int termoAnt, termoM, termoProx, i;
	termoAnt = 0;
	termoProx = 1;
	
	for (i = 0; i < NTERMOS; i++) {
        printf("%i, ", i, termoAnt);
		termoM = termoAnt; 
		termoAnt = termoProx; 
		termoProx = termoM + termoProx; 
    }
    
    return 0;
}
