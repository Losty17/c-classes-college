#include <stdio.h>

enum Options
{
    NONE,
    INSERT,
    APPEND,
    REMOVE,
    POP,
    QUIT
};

typedef struct
{
    int value;
} Node;

typedef struct
{
    Node *array;
    int arr_start, arr_end, start, end;
} List;

int insert(List *list)
{
    if (list->arr_end == list->end)
    {
        printf("Lista cheia\n");
        return 0;
    }

    int pos;
    printf("Digite a posição: ");
    scanf("%d", &pos);

    if (pos < 0 || pos > list->arr_end)
    {
        printf("Posição inválida\n");
        return 0;
    }

    Node value;
    printf("\nDigite o valor: ");
    scanf("%d", &value.value);

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
        printf("\nLista cheia\n\n");
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

    Node array[size - 1];

    List list;
    list.array = array;
    list.end = list.start = list.arr_start = 0;
    list.end--;
    list.arr_end = sizeof(array) / sizeof(array[0]);

    int option = NONE;
    do {
        printf("Lista: \n");
        for (int i = 0; i <= list.end; i++)
            printf("%d\t", list.array[i].value);
        printf("\n\n");

        printf("Digite a opção desejada:\n");
        printf("1 - Inserir\t");
        printf("2 - Adicionar ao final\t");
        printf("3 - Remover\t");
        printf("4 - Remover último\t");
        printf("5 - Sair\n\n");

        scanf("%d", &option);

        printf("\n\n");

        switch (option)
        {
            case APPEND:
                append(&list);
                break;

            case POP:
                pop(&list);
                break;

            case INSERT:
                insert(&list);
                break;
            
            case QUIT:
                break;

            default:
                printf("Opção inválida\n\n");
                break;
        }

    } while (option != QUIT);

    return 1;
}