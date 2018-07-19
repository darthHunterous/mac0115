#include <stdio.h>
#define MES 31

int main() {
    int quant, quant_max = 0, dia_max = 0, i;

    for (i = 1; i <= MES; i++) {
        printf("\nDiscos vendidos no dia %2d:", i);
        scanf("%d", &quant);
        if (quant > quant_max) {
            quant_max = quant;
            dia_max = i;
        }
    }

    printf("Maior venda: %d discos, no dia %d", quant_max, dia_max);

    return 0;
}
