#include <stdio.h>

int main() {
	float n1, n2;
	char op;
	
	printf ("\n insira n1:");
	scanf ("%f", &n1);
	printf ("\n insira n2:");
	scanf ("%f", &n2);
	printf ("n\ insira operação:");
	scanf ("%s", &op);
	
	if (op== "+")
		printf ("%f", n1+n2);
	if (op== "-")
		printf ("%f", n1-n2);
	if (op== "*")
		printf ("%f", n1*n2);
	if (op== "/")
		printf ("%f", n1/n2);	
		
	return 0;
}