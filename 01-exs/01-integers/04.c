#include <stdio.h>

int main() {
    int x, n, pot = 1;

    scanf("%d", &x);
    scanf("%d", &n);

    for (; n > 0; n--) {
        pot *= x;
    }

    printf("%d\n", pot);
    return 0;
}
