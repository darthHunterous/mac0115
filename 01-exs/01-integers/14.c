#include <stdio.h>

int main() {
    int n_minus_one = 1, n_minus_two = 1, n_current = 1, n, i;
    scanf("%d", &n);

    for (i = 3; i <= n; i++) {
        n_current = n_minus_one + n_minus_two;
        n_minus_two = n_minus_one;
        n_minus_one = n_current;
    }

    printf("Fn eh %d\n", n_current);
    return 0;
}
