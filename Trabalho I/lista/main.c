#include <stdio.h>
#include <stdlib.h>

// Item
typedef struct Item
{
    int valor;
    struct Item *proximo;
} Item;

// Criar um novo item
Item *criarItem(int valor)
{
    Item *novoItem = (Item *)malloc(sizeof(Item));
    if (novoItem == NULL)
    {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    novoItem->valor = valor;
    novoItem->proximo = NULL;
    return novoItem;
}

// INserir no início
void inserirInicio(Item **inicio, int valor)
{
    Item *novoItem = criarItem(valor);
    novoItem->proximo = *inicio;
    *inicio = novoItem;
}

// Remover o primeiro item
void removerInicio(Item **inicio)
{
    if (*inicio == NULL)
    {
        printf("A lista está vazia!\n");
        return;
    }
    Item *temp = *inicio;
    *inicio = (*inicio)->proximo;
    free(temp);
}

// Buscar um item na lista
int buscar(Item *inicio, int valor)
{
    Item *atual = inicio;
    while (atual != NULL)
    {
        if (atual->valor == valor)
        {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

// Mostra os itens da lista
void mostrar(Item *inicio)
{
    if (inicio == NULL)
    {
        printf("A lista está vazia!\n");
        return;
    }

    Item *atual = inicio;

    while (atual != NULL)
    {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Liberar toda a lista
void limparLista(Item *inicio)
{
    Item *atual = inicio;
    while (atual != NULL)
    {
        Item *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

int main()
{
    Item *inicio = NULL;
    int opcao, valor;

    do
    {
        printf("\nMENU:\n");
        printf("1. Inserir no início\n");
        printf("2. Remover do início\n");
        printf("3. Buscar item\n");
        printf("4. mostrar lista\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            inserirInicio(&inicio, valor);
            break;
        case 2:
            removerInicio(&inicio);
            break;

        case 3:
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valor);
            if (buscar(inicio, valor))
            {
                printf("Item %d encontrado na lista.\n", valor);
            }
            else
            {
                printf("Item %d não encontrado na lista.\n", valor);
            }
            break;
        case 4:
            mostrar(inicio);
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    limparLista(inicio);
    return 0;
}