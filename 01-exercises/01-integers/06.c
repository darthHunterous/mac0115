#include <stdio.h>

int main() {
    int n, nota, nota_max = 0, nota_min = 100, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &nota);
        if (nota > nota_max)
            nota_max = nota;
        if (nota < nota_min)
            nota_min = nota;
    }

    printf("A maior nota foi %d e a menor foi %d\n", nota_max, nota_min);
    return 0;
}
