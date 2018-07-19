#include <stdio.h>

int main() {
    int n, i, prod, triangular = 0;
    scanf("%d", &n);

    prod = 6;
    for (i = 3; prod <= n; i++) {
        if (prod == n)
            triangular = 1;
        prod = (i-1)*i*(i+1);
    }

    if (triangular)
        printf("O numero eh triangular");
    else
        printf("O numero nao eh triangular");

    return 0;
}
