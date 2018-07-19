#include <stdio.h>

int main() {
    int n, impar = 1;

    for (scanf("%d", &n); n > 0; n--) {
        printf("%d\n", impar);
        impar += 2;
    }

    return 0;
}
