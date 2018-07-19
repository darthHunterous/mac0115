#include <stdio.h>

int main() {
    int n, i, j, cont;
    scanf("%d", &n);
    scanf("%d", &i);
    scanf("%d", &j);

    for (cont = 0; n > 0; cont++)
        if (cont % i == 0 || cont % j == 0) {
            printf("%d\n", cont);
            n--;
        }

    return 0;
}
