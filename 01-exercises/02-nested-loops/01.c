#include <stdio.h>

int main() {
    int n, i, num, soma;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("%da sequencia: \n", i);
        scanf("%d", &num);
        soma = 0;
        while (num != 0) {
            if (num % 2 == 0)
                soma += num;
            scanf("%d", &num);
        }
        printf("    Soma dos pares = %d\n\n", soma);
    }
    return 0;
}
