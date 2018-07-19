#include <stdio.h>

int main() {
    int n, i, bin = 0;
    scanf("%d", &n);

    for (i = 1; n != 0; i *= 10) {
        bin += (n % 2) * i;
        n /= 2;
    }

    printf("%d\n", bin);

    return 0;
}
