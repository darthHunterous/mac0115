#include <stdio.h>

int main() {
    int n1, n2, n3, aux;
    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);

    if (n1 > n2) {
        aux = n1;
        n1 = n2;
        n2 = aux;
    }
    if (n2 > n3) {
        aux = n2;
        n2 = n3;
        n3 = aux;
    }

    if (n3*n3 == (n1*n1)+(n2*n2))
        printf("Formam triangulo retangulo\n");
    else
        printf("Nao formam triangulo retangulo\n");
        
    return 0;
}
