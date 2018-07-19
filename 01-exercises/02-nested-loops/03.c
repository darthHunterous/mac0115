#include <stdio.h>

int main() {
    int m, n, x, y, f, f_max = 0, x_max = 0, y_max = 0;
    scanf("%d %d", &m, &n);
    for (x = 0; x <= m; x++) {
        for (y = 0; y <= n; y++) {
            f = (x*y) - (x*x) + y;
            if (f > f_max) {
                f_max = f;
                x_max = x;
                y_max = y;
            }
        }
    }
    printf("O valor maximo %d ocorre com (%d, %d)\n", f_max, x_max, y_max);
    return 0;
}
