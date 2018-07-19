#include <stdio.h>

int main() {
    int n, num_prev, num, cresc = 1, cresc_max = 1, i;
    scanf("%d %d", &n, &num_prev);

    for (i = 1; i < n; i++) {
        scanf("%d", &num);
        if (num > num_prev)
            cresc++;
        else {
            if (cresc > cresc_max)
                cresc_max = cresc;
            cresc = 1;
        }
        num_prev = num;
    }

    printf("%d\n", cresc_max);
    return 0;
}
