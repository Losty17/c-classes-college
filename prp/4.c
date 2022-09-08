#include <stdio.h>

float fees(float price, int installments, int fee)
{
    float newPrice = price + (price * fee / 100);
    printf("\nValor a pagar por parcela R$ %.2f\n", newPrice / installments);
}

int main()
{
    float price;
    int installments;

    do
    {
        printf("Preco R$ ");
        scanf("%f", &price);

        printf("Quantidade de parcelas: ");
        scanf("%d", &installments);

        if (price < 0 || installments < 0)
            printf("\nValores invalidos!\n");
        else
            if (installments < 3)
                fees(price, installments, 0);
            else if (installments >= 3 && installments < 5)
                fees(price, installments, 10);
            else if (installments >= 5)
                fees(price, installments, 20);
    } while (1 == 1);
}