/**
 * @file prova_ex_4.c
 * @author Vinícius Kappke (m71254)
 * @brief Remoção de elementos de uma lista de forma otimizada
 * @date 2022-09-10
 */
#include <stdio.h>

enum Options
{
    NONE,
    INSERT,
    REMOVE,
    QUIT
};

typedef struct
{
    int *arr;
    int start, end, min, max;
} List;

void insert(List *list, int pos, int value)
{
    if ((list->min == list->start && list->max == list->end) ||
        (pos > list->end - list->start + 2) || (pos <= 0) ||
        (list->start == -1 && pos != 1) || (pos > list->max - 1))
    {
        printf("Impossivel realizar a insercao!\n");
    }
    else
    {
        if (list->start == -1)
        {
            list->start = list->end = list->min;
        }
        else if (list->end != list->max)
        {
            for (int i = list->end; i >= list->start + pos - 1; i--)
                list->arr[i + 1] = list->arr[i];
            list->end++;
        }
        else
        {
            for (int i = list->start; i <= list->start + pos - 2; i++)
                list->arr[i - 1] = list->arr[i];
            list->start--;
        }

        list->arr[list->start + pos - 1] = value;
    }
}

void delete (List *list, int pos)
{
    if ((pos <= 0) || (pos > list->end - list->start + 1))
    {
        printf("\nImpossivel remover este valor");
    }
    else
    {
        int moved_nodes = 0;
        char dir;

        if (pos >= list->end / 2)
        {
            dir = -1;
            for (int i = list->start + pos - 1; i <= list->end - 1; i++)
            {
                list->arr[i] = list->arr[i + 1];
                moved_nodes++;
            }
            list->end--;
        }
        else
        {
            dir = 1;
            for (int i = list->start + pos - 1; i > list->start; i--)
            {
                list->arr[i] = list->arr[i - 1];
                moved_nodes++;
            }
            list->start++;
        }
        if (list->end == list->start - 1)
            list->start = list->end = -1;

        printf("Valor removido com sucesso! %d nodos foram movidos para ", moved_nodes);
        if (dir == 1)
            printf("cima.");
        else
            printf("baixo.");
    }
}

void populate(List *list)
{
    for (int i = list->min + 1; i <= list->max; i++)
        insert(list, 1, i);
}

void display(List *list)
{
    printf("\n");
    for (int i = list->start; i < list->end; i++)
        printf("%d\t", list->arr[i]);
    printf("\n");
}

int main()
{
    int size;
    printf("Digite o tamanho da lista: ");
    scanf("%d", &size);

    int arr[size];
    List list;

    list.arr = arr;
    list.max = sizeof(arr) / sizeof(arr[0]);
    list.start = list.end = list.min = 0;

    char confirm;
    printf("Deseja popular a lista automaticamente? (s/n) ");
    scanf(" %c", &confirm);

    if (confirm == 's')
        populate(&list);

    int opt = NONE;
    int pos, value;
    do
    {
        display(&list);
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opt);

        switch (opt)
        {
            case INSERT:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &value);
                printf("Digite a posicao:\n");
                scanf("%d", &pos);
                insert(&list, pos, value);
                break;

            case REMOVE:
                printf("Digite a posicao do valor a ser removido: ");
                scanf("%d", &pos);
                delete (&list, pos);
                break;

            case QUIT:
                printf("Saindo...\n");
                break;
        }
    } while (opt != QUIT);
}