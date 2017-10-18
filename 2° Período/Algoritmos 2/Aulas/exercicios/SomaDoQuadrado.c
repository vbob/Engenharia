#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void verific(int i);

int main() {
	int i = 0;
	for (i = 1000; i <= 9999; i++)
		verific(i);
	return 0;
	}

void verific(int i) {
	int a, b;
	b = i%100;
	a = i/100;
	if(pow(a+b, 2)==i)
		printf("%d\n", i);
	}

