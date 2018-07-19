#include <stdio.h>

int main() {
    int n1, n2, aux;
    scanf("%d", &n1);
    scanf("%d", &n2);

    aux = n1 % n2;
    while (aux != 0) {
        n1 = n2;
        n2 = aux;
        aux = n1 % n2;
    }

    printf("O mdc eh %d\n", n2);
    return 0;
}
