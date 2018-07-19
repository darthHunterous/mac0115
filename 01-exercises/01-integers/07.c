#include <stdio.h>

int main() {
    int n, num, soma = 0, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        if (num % 2 == 0)
            soma += num;
    }

    printf("\nA soma dos pares foi %d\n", soma);
    return 0;
}
