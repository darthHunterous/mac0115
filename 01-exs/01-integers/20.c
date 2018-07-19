#include <stdio.h>

int main() {
    int i, num1, num2;

    for (i = 1000; i < 10000; i++) {
        num1 = i % 100;
        num2 = i / 100;
        if ((num1+num2)*(num1+num2) == i)
            printf("%d\n", i);
    }

    return 0;
}
