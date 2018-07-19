#include <stdio.h>

int main() {
    int n, h, a, b, pular = 0;
    scanf("%d", &n);

    for (h = 2; h < n; h++) {
        for (a = 1; a < h; a++) {
            for (b = 1; b <= a; b++) {
                if (h * h == (a * a) + (b * b)) {
                    printf("%d eh hipotenusa de %d %d %d\n", h, h, a, b);
                    pular = 1;
                    break;
                }
            }
            if (pular) {
                pular = 0;
                break;
            }
        }
    }
    return 0;
}
