#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct paciente{
    int prioridade;
    int senha;
    char nome[20];
}; 
typedef struct paciente pacientes;

char nomes[20][20] = {
    "Luiza",
    "Julia",
    "Janaina",
    "Maria",
    "Marcos",
    "Elias",
    "Joao",
    "Paulo",
    "Pedro",
    "Laura",
    "Murilo",
    "Mirtes",
    "Carina",
    "Mariana",
    "Catia",
    "Dercio",
    "Vitor",
    "Mariana",
    "Camila",
    "Luan"
};

void insereHeap(pacientes vetor[], int tam, pacientes elemento){
    pacientes aux;
    int novo = tam + 1;
    vetor[novo] = elemento;
    while(novo > 0 && vetor[novo/2].prioridade < vetor[novo].prioridade){
        aux = vetor[novo];
        vetor[novo] = vetor[novo/2];
        vetor[novo/2] = aux;
        novo = novo/2;
    }
}

void heapify(pacientes *vetor, int tam){
    int i;
    for(i = 0; i < tam - 1; i++)
        insereHeap(vetor, i, vetor[i+1]);
}

int ehHeap(pacientes vetor[], int tam){
    int i;
    for(i = tam - 1; i > 0; i--)
        if(vetor[i].prioridade > vetor[i/2].prioridade)
            return 0;
    return 1;
}

void removeHeap(pacientes vetor[], int *tam){
    int i;
    for (i = 0; i < *tam; i++){
        vetor[i] = vetor[i+1];
        vetor[i].senha = i+1;
    }
    *tam -= 1;
    heapify(vetor, *tam);
}

void imprime(pacientes vetor[], int tam){
    int i;
    for(i = 0; i < tam; i++)
        printf("Paciente: %s\nPrioridade: %d\nSenha: %d\n===========================\n", vetor[i].nome, vetor[i].prioridade, vetor[i].senha);
}

void cadastrarPaciente(pacientes vetor[], int *tam){
    pacientes novo;

    char novoNome[20];
    printf("Digite o nome do paciente:\n");
    scanf("%s", novoNome);
    strcpy(novo.nome, novoNome);

    int novaPrioridade;
    printf("Qual eh a prioridade do paciente?\n");
    scanf("%d", &novaPrioridade);
    novo.prioridade = novaPrioridade;
    novo.senha = *tam+1;

    insereHeap(vetor, *tam-1, novo);
    *tam += 1;
}

void alteraHeap(pacientes vetor[], int tam){
    int chave, i, prioridade; 
    printf("Insira a senha do paciente:");
    scanf("%d", &chave);

    for (i = 0; i < tam; i++){
        if (chave == vetor[i].senha){
            printf("Qual eh a nova prioridade do paciente?\n");
            scanf("%d", &prioridade);
            vetor[i].prioridade = prioridade;
            printf("========================================================\n");
            printf("   Prioridade do paciente %s modificada!\n", vetor[i].nome);
            printf("========================================================\n");
            break;
        }
    }
    heapify(vetor, tam);
}

void troca(pacientes *a, pacientes *b){
    pacientes aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void heapSort(pacientes vetor[], int tam) {
    for (int i = tam - 1; i > 0; i--) {
      troca(&vetor[0], &vetor[i]);
      heapify(vetor, i);
    }
}

int main(){
    int tam = 0;
    pacientes paciente[20];
    srand(13);
    printf("========================================================\n");
    printf("             Bem vinda, Madame Estraela!\n");
    printf("========================================================\n");
    int escolha;
    int res = 1;
    while(res){
        printf("O que voce deseja fazer?\n\n1. Cadastrar paciente\n2. Chamar proximo paciente\n3. Mostrar sala de espera\n4. Ordenar prioridades\n5. Transformar fila em Heap\n6. Alterar prioridades\n7. Encher fila\n8. Sair\n");
        scanf("%d", &escolha);

        switch(escolha){
            case (1): 
                if (tam == 20){
                    printf("========================================================\n");
                    printf("                   A UPA est?? lotada!\n");
                    printf("========================================================\n");
                    break;
                }
                cadastrarPaciente(paciente, &tam);
                printf("===========================\n");
                imprime(paciente, tam);
                printf("   Paciente cadastrado!\n");
                printf("===========================\n");
                res = 1;
                break;
            case (2):
                if (tam == 0){
                    printf("===========================\n");
                    printf("   Sem pacientes na fila!\n");
                    printf("===========================\n");
                    break;
                }
                removeHeap(paciente, &tam);
                printf("===========================\n");
                printf("Paciente atendido!\n");
                printf("Fila atual:\n");
                printf("===========================\n");
                imprime(paciente, tam);
                res = 1;
                break;
            case (3):
                printf("========================================================\n");
                if (tam == 0)
                    printf("                  Sala de espera vazia!\n");
                else
                    printf("                      Sala de espera\n");
                printf("========================================================\n");
                imprime(paciente, tam);
                if (tam == 0)
                    printf("      Sala de espera vazia!\n");
                else
                    printf("      Sala de espera\n");
                printf("===========================\n");
                res = 1;
                break;
            case (4):
                heapSort(paciente, tam);
                printf("===========================\n");
                printf("    Pacientes ordenados!\n");
                printf("===========================\n");
                imprime(paciente, tam);
                printf("    Pacientes ordenados!\n");
                printf("===========================\n");
                res = 1;
                break;
            case (5):
                heapify(paciente, tam);
                printf("===========================\n");
                if (ehHeap(paciente, tam))
                    printf("Fila de pacientes transformada em heap!\n");
                else    
                    printf("Erro!\n");
                printf("===========================\n");
                imprime(paciente, tam);
                if (ehHeap(paciente, tam))
                    printf("Fila de pacientes transformada em heap!\n");
                else    
                    printf("Erro!\n");
                printf("===========================\n");
                break;
            case (6):
                printf("===========================\n");
                printf("  Alterando prioridades:\n");
                printf("===========================\n");
                alteraHeap(paciente, tam);
                res = 1;
                break;
            case (7):
                printf("===========================\n");
                printf("Chamando pessoas para encher a fila...\n");
                printf("===========================\n");
                int i;
                for (i = tam; i < 20; i++){
                    strcpy(paciente[i].nome, nomes[rand() % 20]);
                    paciente[i].prioridade = rand() % 20;
                    paciente[i].senha = i + 1;
                    tam++;
                }
                printf("Fila Cheia!\n");
                printf("===========================\n");
                imprime(paciente, tam);
                printf("Lembre-se de transformar a fila em Heap\n para garantir a ordem de prioridade!\n");
                printf("===========================\n");
                res = 1;
                break;
            case (8):
                res = 0;
                break;
            default:
                printf("Insira um numero valido!");
                res = 1;
                break;
        }
    }
}