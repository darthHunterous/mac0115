#include <stdio.h>

int main () {
	
	int i, n, naux;
	double soma = 0;
	
	printf ("Insira um inteiro positivo: ");
	scanf ("%d", &n);
		
	for (i = 1, naux = n; i <= n; i++, naux--)
		soma += (double) i/naux; 
		
	printf ("\nO valor da soma eh %lf", soma);
	
	return 0;
}
