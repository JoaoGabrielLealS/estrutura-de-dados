#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Definindo o tamanho máximo da fila

// Estrutura que representa a fila
typedef struct Fila {
    int itens[MAX];
    int frente;
    int tras;
} Fila;

// Função para inicializar a fila
void inicializarFila(Fila* f) {
    f->frente = 0;  // A frente começa na posição 0
    f->tras = -1;   // A fila começa vazia, então o trás é -1
}

// Função para verificar se a fila está cheia
int filaCheia(Fila* f) {
    return f->tras == MAX - 1;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila* f) {
    return f->frente > f->tras;
}

// Função para enfileirar um item
void enfileirar(Fila* f, int valor) {
    if (filaCheia(f)) {
        printf("Erro: Fila cheia! Não é possível enfileirar o valor %d.\n", valor);
    } else {
        f->itens[++(f->tras)] = valor;
        printf("Valor %d enfileirado com sucesso.\n", valor);
    }
}

// Função para desenfileirar um item
int desenfileirar(Fila* f) {
    if (filaVazia(f)) {
        printf("Erro: Fila vazia! Não é possível desenfileirar.\n");
        return -1;  // Retorna -1 se a fila estiver vazia
    } else {
        int valor = f->itens[f->frente++];
        return valor;
    }
}

// Função para espiar o item da frente da fila
int espiar(Fila* f) {
    if (filaVazia(f)) {
        printf("Erro: Fila vazia! Não é possível espiar.\n");
        return -1;  // Retorna -1 se a fila estiver vazia
    } else {
        return f->itens[f->frente];
    }
}

// Função para exibir os itens da fila
void exibirFila(Fila* f) {
    if (filaVazia(f)) {
        printf("A fila está vazia!\n");
    } else {
        printf("Elementos da fila: ");
        for (int i = f->frente; i <= f->tras; i++) {
            printf("%d ", f->itens[i]);
        }
        printf("\n");
    }
}

// Função principal com o menu de opções
int main() {
    Fila f;
    inicializarFila(&f);  // Inicializa a fila
    int opcao, valor;

    do {
        printf("\nMENU:\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Espiar (Frente da fila)\n");
        printf("4. Exibir fila\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser enfileirado: ");
                scanf("%d", &valor);
                enfileirar(&f, valor);
                break;
            case 2:
                valor = desenfileirar(&f);
                if (valor != -1) {
                    printf("Valor %d desenfileirado com sucesso.\n", valor);
                }
                break;
            case 3:
                valor = espiar(&f);
                if (valor != -1) {
                    printf("Frente da fila: %d\n", valor);
                }
                break;
            case 4:
                exibirFila(&f);
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
