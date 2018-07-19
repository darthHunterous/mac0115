#include <stdio.h>

int main() {
    int n, i, j, primo;
    scanf("%d", &n);
    printf("%d = ", n);
    for (i = 2; i <= n; i += 2) {
        if (n % i == 0) {
            primo = 1;
            for (j = 2; j < i; j++)
                if (i % j == 0) {
                    primo = 0;
                    break;
                }
            while (primo && (n % i == 0)) {
                n /= i;
                printf("%d x ", i);
            }
        }
        if (i == 2)
            i--;
    }
    printf("\n");
    return 0;
}
