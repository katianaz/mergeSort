#include <stdio.h>
#include <stdlib.h>

void insertion_sort(long int * v, long int n){
    long int i, j, aux, x;
    for(i=+1; i<=n; i++){
        x = v[i];
        j = i;
        while(x < v[j-1] && j > 0){
            v[j] = v[j-1];
            j--;
        }
        v[j] = x;
    }
}

void merge_sort(int i, int j, int a[], int aux[]) {
    if (j <= i)
        return;

    int meio = (i + j) / 2;

    if(a[meio] <= a[meio + 1])
        return;

    if ((j+i) <= 15) {
        insertion_sort(a, j);
        return;
    }

    merge_sort(i, meio, a, aux);
    merge_sort(meio + 1, j, a, aux);

    int esquerda = i;
    int direita = meio + 1;
    int k;


    for (k = i; k <= j; k++) {
        if (esquerda == meio + 1) {
            aux[k] = a[direita];
            direita++;
        } else if (direita == j + 1) {
            aux[k] = a[esquerda];
            esquerda++;
        } else if (a[esquerda] < a[direita]) {
            aux[k] = a[esquerda];
            esquerda++;
        } else {
            aux[k] = a[direita];
            direita++;
        }
    }

    for (k = i; k <= j; k++) {
        a[k] = aux[k];
    }
}

int main() {
    int *a, n, i;

    printf("Digite o numero de elementos do array:\n");
    scanf("%d", &n);

    a = (int *) malloc(sizeof(int) * n);

    printf("Digite os valores inteiros:");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    merge_sort(0, n - 1, a, a);

    printf("Vetor ordenado:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0;
}