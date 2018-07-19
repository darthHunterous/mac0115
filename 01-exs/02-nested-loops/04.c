#include <stdio.h>

int main() {
    int n, i, primo, j, num;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        primo = 1;
        if (num == 1)
            primo = 0;
        for (j = 2; j < num; j++)
            if (num % j == 0) {
                primo = 0;
                break;
            }
        if (primo)
            printf("%d eh primo\n", num);
        else
            printf("%d nao eh primo\n", num);
    }
    return 0;
}
