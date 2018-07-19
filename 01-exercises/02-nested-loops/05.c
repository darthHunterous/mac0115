#include <stdio.h>

int main() {
    int m, n, current = 1, i;
    scanf("%d", &m);
    for (n = 1; n <= m; n++) {
        printf("%d^3 = %d", n, current);
        current += 2;
        for (i = 1; i < n; i++) {
            printf("+%d", current);
            current += 2;
        }
        printf("\n");
    }
    return 0;
}
