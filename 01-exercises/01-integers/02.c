#include <stdio.h>

int main() {
    int n, num, soma = 0;

    scanf("%d", &n);
    while (n > 0) {
        scanf("%d", &num);
        if (num > 0) {
            soma += num;
            n--;
        }
    }

    printf("A soma eh %d\n", soma);
    return 0;
}
