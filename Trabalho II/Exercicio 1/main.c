#include <stdio.h>
#include <math.h>




// Função para somar dois números
void soma() {
    double a, b;
    printf("Digite dois números para somar: ");
    scanf("%lf %lf", &a, &b);
    printf("Resultado: %.2lf\n", a + b);
}




// Função para subtrair dois números
void subtracao() {
    double a, b;
    printf("Digite dois números para subtrair: ");
    scanf("%lf %lf", &a, &b);
    printf("Resultado: %.2lf\n", a - b);
}

// Função para multiplicar dois números
void multiplicacao() {
    double a, b;
    printf("Digite dois números para multiplicar: ");
    scanf("%lf %lf", &a, &b);
    printf("Resultado: %.2lf\n", a * b);
}

// Função para dividir dois números
void divisao() {
    double a, b;
    printf("Digite dois números para dividir: ");
    scanf("%lf %lf", &a, &b);
    
    if (b != 0) {
        printf("Resultado: %.2lf\n", a / b);
    } else {
        printf("Erro: Divisão por zero não é permitida.\n");
    }
}

// Função para calcular a exponenciação (potência)
void exponenciacao() {
    double base, expoente;
    printf("Digite a base e o expoente: ");
    scanf("%lf %lf", &base, &expoente);
    printf("Resultado: %.2lf\n", pow(base, expoente));
}

// Função para calcular a raiz quadrada
void raizQuadrada() {
    double a;
    printf("Digite um número para calcular a raiz quadrada: ");
    scanf("%lf", &a);
    
    if (a >= 0) {
        printf("Resultado: %.2lf\n", sqrt(a));
    } else {
        printf("Erro: Raiz quadrada de número negativo não é permitida.\n");
    }
}

// Função para calcular o módulo
void modulo() {
    int a, b;
    printf("Digite dois números para calcular o módulo (resto da divisão): ");
    scanf("%d %d", &a, &b);
    
    if (b != 0) {
        printf("Resultado: %d\n", a % b);
    } else {
        printf("Erro: Divisão por zero não é permitida.\n");
    }
}

// Função para resolver a fórmula de Bhaskara
void bhaskara() {
    double a, b, c, delta, x1, x2;
    
    printf("Digite os coeficientes a, b e c da equação quadrática (ax^2 + bx + c = 0): ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    delta = b * b - 4 * a * c;
    
    if (delta < 0) {
        printf("Não existem raízes reais.\n");
    } else if (delta == 0) {
        x1 = -b / (2 * a);
        printf("Raiz única: x = %.2lf\n", x1);
    } else {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("As raízes são: x1 = %.2lf e x2 = %.2lf\n", x1, x2);
    }
}










int main()
{
    int escolha;

    do
    {
        printf("\nMENU DE CALCULADORA\n");
        printf("1- Soma\n");
        printf("2- Subtração\n");
        printf("3- Multiplicação\n");
        printf("4- Divisão\n");
        printf("5- Exponenciação\n");
        printf("6- Raiz Quadrada\n");
        printf("7_ Módulo\n");
        printf("8- Bhaskara\n");
        printf("9- Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                soma();
                break;
            case 2:
                subtracao();
                break;
            case 3:
                multiplicacao();
                break;
            case 4:
                divisao();
                break;
            case 5:
                exponenciacao();
                break;
            case 6:
                raizQuadrada();
                break;
            case 7:
                modulo();
                break;
            case 8:
                bhaskara();
                break;
            case 9:
                printf("Saindo da calculadora...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }
    while (escolha != 9);

    return 0;
}
