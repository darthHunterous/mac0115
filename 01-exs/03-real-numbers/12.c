#include <stdio.h>

int main () {
	
	int i, sinal;
	double soma1 = 0, soma2 = 0;
	       	
	for (i = 10000, sinal = -1; i > 0; i--) {
		soma1 += (double) sinal/i;
		sinal *= -1;
	}
	
	printf ("A adicao dos termos da direita para a esquerda eh %lf", soma1);
	soma1 = 0;
	
	for (i = 1, sinal = 1; i <= 10000; i++) {
		soma1 += (double) sinal/i;
		sinal *= -1;
	}
	
	printf ("\n\nA adicao dos termos da esquerda para a direita eh %lf", soma1);
	soma1 = 0;
	
	for (i = 1; i <= 9999; i += 2)
		soma1 += (double) 1/i;
		
	for (i = 2; i <= 10000; i += 2)
		soma2 -= (double) 1/i;
		
	printf ("\n\nDa esquerda para direita, separando positivo e negativo eh %lf", soma1 + soma2);
	soma1 = soma2 = 0;
	
	for (i = 10000; i >= 1; i -= 2)
		soma1 -= (double) 1/i;
		
	for (i = 9999; i >= 1; i -= 2)
		soma2 +=(double) 1/i;
		
	printf ("\n\nDa direita para esquerda, separando positivo e negativo eh %lf", soma1 + soma2);
	soma1 = soma2 = 0;
	
	return 0;
}
