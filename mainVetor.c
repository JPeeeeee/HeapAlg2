#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insereHeap(int vetor[], int tam, int elemento){
    int aux;
    int novo = tam + 1;
    vetor[novo] = elemento;
    while(novo > 0 && vetor[novo/2] < vetor[novo]){
        aux = vetor[novo];
        vetor[novo] = vetor[novo/2];
        vetor[novo/2] = aux;
        novo = novo/2;
    }
}

void heapify(int vetor[], int tam){
    int i;
    for(i = 1; i < tam - 1; i++)
        insereHeap(vetor, i, vetor[i+1]);
}

int ehHeap(int vetor[], int tam){
    int i;
    for(i = tam - 1; i > 0; i--)
        if(vetor[i] > vetor[i/2])
            return 0;
    return 1;
}

void removeHeap(int vetor[], int *tam){
    int i;
    for (i = 0; i < *tam; i++)
        vetor[i] = vetor[i+1];
    *tam -= 1;
    heapify(vetor, *tam);
}

void imprime(int vetor[], int tam){
    int i;
    for(i = 0; i < tam; i++)
        printf("%d  ", vetor[i]);
    printf("\n");
}

int main(){
    int tam;
    int vetor[20];
    
    srand(13);
    printf("Insira o tamanho do vetor:\n");
    scanf("%d", &tam);

    int i;
    for(i = 0; i < tam; i++)
        vetor[i] = rand() % 20;

    printf("Vetor original: eh Heap? tem que ser nao (0) = %d\n", ehHeap(vetor, tam));
    imprime(vetor, tam);
    heapify(vetor, tam);
    printf("Vetor heap: eh Heap? tem que ser sim (1) = %d\n", ehHeap(vetor, tam));
    imprime(vetor, tam);
    removeHeap(vetor, &tam);
    printf("Vetor -1 elemento: eh Heap? tem que ser sim (1) = %d\n", ehHeap(vetor, tam));
    imprime(vetor, tam);
    insereHeap(vetor, tam-1, 5);
    tam++;    
    insereHeap(vetor, tam-1, 12);
    tam++;
    printf("Vetor +2 elemento: eh Heap? tem que ser sim (1) = %d\n", ehHeap(vetor, tam));
    imprime(vetor, tam);

}