#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main () {
	
	int anos, trocou = FALSE, aux;
	double pop1, pop2, dif_in, cresc1, cresc2;
	
	printf ("Insira a populacao da cidade de Uaua: ");
	scanf ("%lf", &pop1);
	
	printf ("\nInsira a populacao da cidade de Nova Iorque: ");
	scanf ("%lf", &pop2);
	
	printf ("\nInsira o crescimento anual percentual da cidade de Uaua: ");
	scanf ("%lf", &cresc1);
	cresc1 = 1 + cresc1/100;
	
	printf ("\nInsira o crescimento anual percentual da cidade de Nova Iorque: ");
	scanf ("%lf", &cresc2);
	cresc2 = 1 + cresc2/100;
	
	if (pop1 > pop2) {
		aux = pop1;
		pop1 = pop2;
		pop2 = aux;
		
		aux = cresc1;
		cresc1 = cresc2;
		cresc2 = aux;
		
		trocou = TRUE;	
	}
	
	dif_in = pop2 - pop1;
	
	printf ("\nA diferenca inicial eh %lf", dif_in);
	
	for (anos = 0; pop1 <= pop2; anos++) {
		pop1 *= cresc1;
		pop2 *= cresc2;
				
		if (pop2 - pop1 >= dif_in) {
			if (trocou)
				printf ("\nA populacao da cidade de Nova Iorque nao ultrapassara a de Uaua");
			else
				printf ("\nA populacao da cidade de Uaua nao ultrapassara a de Nova Iorque");	
			return 0;
		}
	}
	
	if (trocou)
		printf ("\nA populacao da cidade de Nova Iorque ultrapassa a de Uaua em %d anos", anos);
	else
		printf ("\nA populacao da cidade de Uaua ultrapassa a de Nova Iorque em %d anos", anos);
		
	return 0;
}
