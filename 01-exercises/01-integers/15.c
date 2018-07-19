#include <stdio.h>

int main() {
    int n, j, m, i;
    scanf("%d", &n);
    scanf("%d", &j);
    scanf("%d", &m);

    for (i = 0; n > 0; i++) {
        if (i % m == j % m) {
            printf("%d\n", i);
            n--;
        }
    }
    
    return 0;
}
