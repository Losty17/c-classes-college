#include <stdio.h>

enum {
    NONE,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    QUIT
};

int sum(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

int main()
{
    int opt = NONE;

    do
    {
        printf("\n1 - Soma\n2 - Subtracao\n3 - Multiplicacao\n4 - Divisao\n5 - Sair\n");
        printf("\nDigite a opcao: ");
        scanf("%d", &opt);
        
        int n1, n2;

        if (opt > 0 && opt < 5)
        {
            printf("\nDigite o primeiro numero: ");
            scanf("%d", &n1);
            printf("Digite o segundo numero: ");
            scanf("%d", &n2);
        
            int result = -1;

            switch (opt)
            {
                case ADD:
                    result = sum(n1, n2);
                    break;

                case SUBTRACT:
                    result = subtract(n1, n2);
                    break;

                case MULTIPLY:
                    result = multiply(n1, n2);
                    break;

                case DIVIDE:
                    result = divide(n1, n2);
                    break;
            }

            printf("\nResultado: %d\n", result);
        }
    } while (opt != QUIT);
    
}