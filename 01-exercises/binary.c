int buscaBinariaRec(int v[], int inicio, int fim, int x) {
    if (fim >= inicio) {
        int meio = inicio + (fim - inicio)/2;
        if (v[meio] == x)
            return meio;
        if (v[meio] > x)
            return buscaBinariaRec(v, inicio, meio-1, x);
        return buscaBinariaRec(v, meio+1, fim, x);
    }
    return -1;
}

void insertionSort(int v[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = v[i];
        for (j = i-1; j >= 0 && v[j] > key; j--)
            v[j+1] = v[j];
        v[j+1] = key;
    }
}

void insertionSortRec(int v[], int n) {
    int j, last;
    if (n <= 1)
        return;
    insertionSortRec(v, n-1);
    last = v[n-1];
    for (j = n-2; j >= 0 && v[j] > last; j--)
        v[j+1] = v[j];
    v[j+1] = last;
}

void selectionSort(int v[], int n) {
    int i, j, index_min;
    for (i = 0; i < n-1; i++) {
        index_min = i;
        for (j = i+1; j < n; j++)
            if (v[j] < v[index_min])
                index_min = j;
        swap(&v[index_min], &v[i]);
    }
}

ESTABILIDADE -> struct nome e salário. Um sort stable ordena por nome e depois
por salário e mantém ambos ordenados.
    Insertion e Selection sort são stable

MERGESORT -> n*logn e estável
void mergeSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim-inicio)/2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio+1, fim);
        merge(v, inicio, meio, fim);
    }
}

//subarrays de inicio a meio e de meio+1 a fim
void merge(int v[], int inicio, int meio, int final) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *esquerda; // arrays temporários
    int *direita; // arrays temporários
    esquerda = malloc(n1*sizeof(int));
    direita = malloc(n2*sizeof(int));

    // copiar para os temp arrays
    for (i = 0; i < n1; i++)
        esquerda[i] = v[inicio+i];
    for (j = 0; j < n2; j++)
        direita[j] = v[meio+esquerda+j];

    // faz o merge ordenado
    i = 0;
    j = 0;
    k = esquerda;
    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            v[k] = esquerda[i];
            i++;
        }
        else {
            v[k] = direita[j];
            j++;
        }
        k++;
    }
    //copia de eventuais elementos restantes
    while (i < n1) {
        v[k] = esquerda[i];
        i++;
        k++;
    }
    while (j < n2) {
        v[k] = direita[j];
        j++;
        k++;
    }
}

void bubble(int n, int v[]) {
    int i, k;
    for (i = 0; i < n-1; i++)
        for (k = 0; k < n-1; k++)
            if (vetor[k] > vetor[k+1])
                troca(&vetor[k], &vetor[k+1]);
}

MALLOC ->
char *ptr;
ptr = malloc (sizeof(char));
Desnecessário o cast:
ptr = (char*)malloc(1);

FREE ->
free(ptr);
ptr = NULL;

ALOCAÇÃO DINÂMICA MATRIZ ->
int **M;
M = malloc (linhas * sizeof (int *));
for (int i = 0; i < m; i++)
    M[i] = malloc (n * sizeof (int));

REALOCAR DINAMICAMENTE _>
v = realloc (v, 2000 * sizeof (int));

LISTA LIGADA ->
struct node {
    int data;
    struct node *prox;
}
typedef struct node Node;

STRUCTS/PONTEIROS ->
    data *p;
    data x;
    p = &x;
    (*p).dia = 31; // equivalente a x.dia = 31;
    p->dia = 31;

LISTA LIGADA ->
    void imprime (celular *le) {
        if (le != NULL) {
            printf("%d\n", le->conteudo);
            imprime(le->prox);
        }
    }

FILA EM VETOR ->
      0       p                       u          N-1
    |   |   |111|222|333|444|555|666|   |   |   |   |
PILHA EM VETOR ->
      0                               t          N-1
    | A | B | C | D | E | F | G | H |   |   |   |   |
