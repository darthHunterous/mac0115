#include <stdio.h>

int main() {
    int n, m;
    float y;
    char x;

    int* ap1;
    float* ap2;
    char* ap3;

    n = 2;
    m = 3;
    y = 5.0;
    x = 's';

    ap1 = &n;
    ap2 = &y;
    ap3 = &x;

    *ap1 = m;
    *ap2 = -5.0;
    *ap3 = 'd';

    printf ("n = %d y = %f x = %c\n", n, y, x);
    return 0;
}
