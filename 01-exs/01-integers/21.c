#include <stdio.h>

int main() {
    int n, num_prev, num, seg = 1, i;
    scanf("%d %d", &n, &num_prev);

    for (i = 1; i < n; i++) {
        scanf("%d", &num);
        if (num != num_prev)
            seg++;
        num_prev = num;
    }

    printf("%d\n", seg);
    return 0;
}
