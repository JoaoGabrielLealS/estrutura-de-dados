#include <stdio.h>
#include <stdlib.h>

// Função recursiva
void torreDeHanoi(int n, char origem, char destino, char ajudante)
{
    if (n == 1)
    {
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        return;
    }

    torreDeHanoi(n - 1, origem, ajudante, destino);
    printf("Mover disco %d de %c para %c\n", n, origem, destino);
    torreDeHanoi(n - 1, ajudante, destino, origem);
}

int main()
{
    int n;
    printf("Digite o número de discos: ");
    scanf("%d", &n);
    torreDeHanoi(n, 'A', 'C', 'B');

    return 0;
}
