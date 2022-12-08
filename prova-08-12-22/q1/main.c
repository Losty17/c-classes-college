#include <stdio.h>

void calc_discount(int qty)
{
    double crit_a = (0.25 * qty) + 7.5;
    double crit_b = (0.50 * qty) + 2.5;

    if (crit_a < crit_b)
        printf("Desconto do criterio A: %.2lf\n", crit_a);
    else 
        printf("Desconto do criterio B: %.2lf\n", crit_b);
}

int main()
{
    int qty;
    printf("Numero de livros a comprar: ");
    scanf("%d", &qty);

    printf("Desconto escolhido: \n");
    calc_discount(qty);
}