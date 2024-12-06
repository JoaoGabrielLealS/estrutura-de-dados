#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Tamanho maximo da pilha

// Pilha
typedef struct Pilha {
    int itens[MAX];
    int topo;
} Pilha;

// Iniciar pilha
void inicializarPilha(Pilha* p) {
    p->topo = -1;  // A pilha começa vazia, então o topo é -1
}

// Verificar se a pilha está cheia
int pilhaCheia(Pilha* p) {
    return p->topo == MAX - 1;
}

// Verificar se a pilha está vazia
int pilhaVazia(Pilha* p) {
    return p->topo == -1;
}

// Empilhar um item
void empilhar(Pilha* p, int valor) {
    if (pilhaCheia(p)) {
        printf("Erro: Pilha cheia! Não é possível empilhar o valor %d.\n", valor);
    } else {
        p->itens[++(p->topo)] = valor;
        printf("Valor %d empilhado com sucesso.\n", valor);
    }
}

// Desempilhar um item
int desempilhar(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia! Não é possível desempilhar.\n");
        return -1;  // Retorna -1 se a pilha estiver vazia
    } else {
        int valor = p->itens[(p->topo)--];
        return valor;
    }
}

// Espiar o topo da pilha
int espiar(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia! Não é possível espiar.\n");
        return -1;  // Retorna -1 se a pilha estiver vazia
    } else {
        return p->itens[p->topo];
    }
}

// Exibir os itens da pilha
void exibirPilha(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("A pilha está vazia!\n");
    } else {
        printf("Elementos da pilha: ");
        for (int i = 0; i <= p->topo; i++) {
            printf("%d ", p->itens[i]);
        }
        printf("\n");
    }
}

int main() {
    Pilha p;
    inicializarPilha(&p);
    int opcao, valor;

    do {
        printf("\nMENU:\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar\n");
        printf("3. Espiar (Topo da pilha)\n");
        printf("4. Exibir pilha\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser empilhado: ");
                scanf("%d", &valor);
                empilhar(&p, valor);
                break;
            case 2:
                valor = desempilhar(&p);
                if (valor != -1) {
                    printf("Valor %d desempilhado com sucesso.\n", valor);
                }
                break;
            case 3:
                valor = espiar(&p);
                if (valor != -1) {
                    printf("Topo da pilha: %d\n", valor);
                }
                break;
            case 4:
                exibirPilha(&p);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    return 0;
}
