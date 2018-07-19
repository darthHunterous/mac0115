#include <stdio.h>

int main() {
    int n, mdc, num, resto, i;
    scanf("%d %d", &n, &mdc);
    for (i = 1; i < n; i++) {
        scanf("%d", &num);
        resto = mdc % num;
        while (resto != 0) {
            mdc = num;
            num = resto;
            resto = mdc % num;
        }
        mdc = num;
    }
    printf("O mdc eh %d\n", mdc);
    return 0;
}
