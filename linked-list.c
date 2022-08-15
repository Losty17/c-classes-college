#include <stdio.h>

typedef struct
{
    int value;
} Node;

typedef struct
{
    Node *array;
    int arr_start, arr_end, start, end;
} List;

int insert(int pos, List *list)
{
    if (pos < list->start || pos > list->end)
    {
        printf("Posicao invalida\n");
        return 0;
    }
    else if (list->end == list->arr_end)
    {
        printf("Lista cheia\n");
        return 0;
    }

    Node value;
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &value.value);

    return 0;
}

int append(List *list)
{
    if (list->end == list->arr_end)
    {
        printf("Lista cheia\n");
        return 0;
    }

    Node value;
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &value.value);

    list->array[list->end] = value;
    list->end++;

    return 0;
}

int main()
{
    Node array[10];

    List list;
    list.array = array;
    list.start = list.end = list.arr_start = 0;
    list.arr_end = 10;

    for (int i = 0; i < 10; i++)
    {
        append(&list);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", list.array[i].value);
    }

    return 0;
}