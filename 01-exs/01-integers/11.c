#include <stdio.h>

int main() {
    int n, i, primo = 1;
    scanf("%d", &n);
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            primo = 0;
            break;
        }
    }

    if (primo)
        printf("O numero eh primo\n");
    else
        printf("O numero nao eh primo\n");
        
    return 0;
}
