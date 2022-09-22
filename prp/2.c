#include <stdio.h>

void increase(int wage)
{
    int newWage = wage + (wage * 0.3);
    printf("O novo salario eh: %d\n", newWage);
}

int main()
{
    int wage;
    do 
    {
        printf("Digite o salario: ");
        scanf("%d", &wage);

        if (wage < 500) increase(wage);
        else printf("Nao tem direito ao aumento\n"); 
    } while (1 == 1);
}