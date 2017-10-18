#include <stdio.h> 

void troca(int *a, int *b);

void main() {
	int a, b, c;
	printf("Leia A B C: ");
	scanf("%d %d %d", &a, &b, &c);
	if (a > b || a > c) {
		if (b > c)
			troca(&a, &c);
		else
			troca(&a, &b);
	}
	if (b > c)
		troca(&b, &c);
	printf("\n%d, %d, %d\n", a, b, c);
}

void troca (int *a, int *b) {
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}
	

