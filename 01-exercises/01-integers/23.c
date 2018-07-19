#include <stdio.h>

int main() {
    int num, aux, reverso = 0;
    scanf("%d", &num);
    aux = num;

    while (aux != 0) {
        reverso = reverso * 10 + aux % 10;
        aux /= 10;
    }

    if (reverso == num)
        printf("Eh palindromo\n");
    else
        printf("Nao eh palindromo\n");

    return 0;
}
