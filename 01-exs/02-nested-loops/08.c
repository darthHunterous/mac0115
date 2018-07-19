#include <stdio.h>

int main() {
    int n, num_prev, num, i, k = 1, kgeral = 0, alternante = 1, entrou = 0;
    scanf("%d %d", &n, &num_prev);
    for (i = 1; i < n; i++) {
        scanf("%d", &num);
        if (num_prev % 2 == num % 2)
            k++;
        else {
            entrou = 1;
            if (!kgeral)
                kgeral = k;
            if (kgeral != k)
                alternante = 0;
            k = 1;
        }
        num_prev = num;
    }
    if (k != kgeral && entrou)
        alternante = 0;
    if (!entrou)
        kgeral = k;
    if (alternante)
        printf("A sequencia eh %d-alternante", kgeral);
    else
        printf("A sequencia nao eh alternante");
    return 0;
}

int func(int n,int v[]){int i,j;i=0;while(i<n){
if(v[i]!=0) ++i;else{for(j=i+1;j<n;++j)
v[j-1]=v[j];--n;}}return n;}

int func (int n, int v[]) {
    int i, j;
    i = 0;
    while (i < n) {
        if (v[i] != 0)
            ++i;
        else {
            for (j = i + 1; j < n; ++j)
                v[j-1] = v[j];
            --n;
        }
    }
    return n;
}

esq= 0; dir=N-1;
i=(esq+dir)/2;     /*indice do "meio"de r[]*/
while(esq <= dir && r[i] != x){
   if(r[i]<x) esq = i+1;
   else dir = i-1;  /* novo indice do "meio"de r[] */
   i= (esq + dir)/2;
   }

esq = 0;
dir = N - 1;
i = (esq + dir)/2; /* indice do "meio" de r[] */
while (esq <= dir && r[i] != x) {
    if (r[i] < x)
        esq = i + 1;
    else
        dir = i - 1; /* novo indice do "meio" de r[] */
    i = (esq + dir)/2;
    
}
