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

/**
 * @brief Adds a Node to the end of the list
 * 
 * @param list the list to be added to
 * @return int 1 if successful, 0 if unsuccessful
 */
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

    list->array[++list->end] = value;

    return 1;
}

/**
 * @brief Removes the last element of the list and returns it
 * 
 * @param list List to be removed from
 * @return Last node of the list
 */
Node pop(List *list)
{
    Node n = {-999};
    if (list->start == list->end)
    {
        printf("Lista vazia\n");
        return n;
    }

    Node value = list->array[list->end];
    list->array[list->end] = n;
    list->end--;

    return value;
}

int main()
{
    Node array[5];

    List list;
    list.array = array;
    list.start = list.arr_start = 0;
    list.end = list.start - 1;
    list.arr_end = 5;

    for (int i = 0; i < 5; i++)
    {
        append(&list);
    }

    for (int i = 0; i <= list.end; i++)
        printf("%d\t", list.array[i].value);

    printf("\n");
    return 0;
}