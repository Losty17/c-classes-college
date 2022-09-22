#include <stdio.h>

typedef struct {
    int yMan, oMan, yWoman, oWoman;
} OrganizedAges;

void operations(OrganizedAges ages)
{
    printf("\nSoma das idades do homem mais velho com a mulher mais nova: %d", ages.oMan + ages.yWoman);
    printf("\nProduto das idades do homem mais novo com a mulher mais velha: %d", ages.yMan * ages.oWoman);
}

int main()
{
    int fMan, sMan, fWoman, sWoman;

    printf("Digite a idade do primeiro homem: ");
    scanf("%d", &fMan);
    printf("Digite a idade do segundo homem: ");
    scanf("%d", &sMan);
    printf("Digite a idade da primeira mulher: ");
    scanf("%d", &fWoman);
    printf("Digite a idade da segunda mulher: ");
    scanf("%d", &sWoman);

    OrganizedAges ages;

    if (fMan <= sMan)
    {
        ages.yMan = fMan;
        ages.oMan = sMan;
    }
    else
    {
        ages.yMan = sMan;
        ages.oMan = fMan;
    }
    if (fWoman <= sWoman)
    {
        ages.yWoman = fWoman;
        ages.oWoman = sWoman;
    }
    else
    {
        ages.yWoman = sWoman;
        ages.oWoman = fWoman;
    }

    operations(ages);
}