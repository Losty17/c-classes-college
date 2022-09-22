#include <stdio.h>

void soma(int n1, float n2)
{
    printf("%f\n", n1 + n2);
}

int main()
{
    int n1;
    float n2;
    printf("digite um inteiro: ");
    scanf("%d", &n1);
    printf("digite um float: ");
    scanf("%f", &n2);

    soma(n1, n2);
}