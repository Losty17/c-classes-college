/**
 * @file main.c
 * @authors Leonardo Mattos (131571), Vinícius Kappke (71254)
 * @date 2022-09-29
 */
#include <stdio.h>
#define MAX 10

struct person
{
    int age;
    char note;
};
typedef struct person person_t;

int calc_great_notes(person_t *arr)
{
    int countA = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (arr[i].age > 40 && arr[i].note == 'A')
        {
            countA++;
        }
    }

    return countA;
}

int main()
{
    person_t people[MAX];

    person_t p;

    for (int i = 0; i < MAX; i++)
    {
        printf("Digite sua idade: ");
        scanf("%d", &p.age);
        printf("Digite a nota: (A, B ou C) ");
        scanf(" %c", &p.note);

        people[i] = p;
    }

    int countA = calc_great_notes(people);
    printf("Quantidade de pessoas com mais de 40 anos que deram nota A: %d\n", countA);
}