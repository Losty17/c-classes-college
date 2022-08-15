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

int insert(int pos, Node value, List *list)
{
    if (pos < 0 || pos > list->arr_end)
    {
        printf("Posição inválida\n");
        return 0;
    }
    else if (list->arr_end == list->end)
    {
        printf("Lista cheia\n");
        return 0;
    }

    return 1;
}

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
    printf("Digite o valor a ser inserido na posição %d: ", list->end + 2);
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
    int size = 0;
    printf("Digite o tamanho da lista: ");
    scanf("%d", &size);

    Node array[size];

    List list;
    list.array = array;
    list.end = list.start = list.arr_start = 0;
    list.end--;
    list.arr_end = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < list.arr_end; i++) append(&list);

    for (int i = 0; i <= list.end; i++)
        printf("%d\t", list.array[i].value);
    printf("\n");

    return 1;
}