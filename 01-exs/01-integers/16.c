#include <stdio.h>

int main() {
    int n, i, dec = 0;
    scanf("%d", &n);

    for (i = 1; n != 0; i *= 2) {
        dec += (n % 10) * i;
        n /= 10;
    }

    printf("%d\n", dec);

    return 0;
}
