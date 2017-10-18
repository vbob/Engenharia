#include <stdio.h>

void fazerMedia(double *a[5], double *media);

void main() {
	double a[5];
	double media;
	int i;
	for (i = 0; i < 5; i++) {
		printf("\nDigite o valor a[%d]", i);
		scanf("%d", &a[i]);
	}
	for (i = 0; i < 5; i++)
		printf("%d ", a[i]);
}
