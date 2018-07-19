#include <stdio.h>

int main() {
    int n, i, soma = 0;
    scanf("%d", &n);

    for (i = 1; i < n && soma <= n; i++) {
        if (n % i == 0)
            soma += i;
    }

    if (soma == n)
        printf("%d eh perfeito", n);
    else
        printf("%d nao eh perfeito", n);
        
    return 0;
}
