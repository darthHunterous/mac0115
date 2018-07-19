#include <stdio.h>

int main() {
    int p, q, pot, aux, sub = 0;
    scanf("%d %d", &p, &q);
    aux = p;
    for (pot = 1; aux != 0; pot *= 10) {
        aux /= 10;
    }
    aux = q;
    while (q % pot >= pot/10) {
        if (q % pot == p)
            sub = 1;
        q /= 10;
    }

    if (sub)
        printf("%d eh subnumero de %d\n", p, aux);
    else
        printf("Nao eh subnumero");

    return 0;
}
