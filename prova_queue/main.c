#include <stdio.h>

enum Options
{
    NONE,
    INSERT,
    REMOVE,
    ODDS,
    QUIT
};

typedef struct
{
    int start, max_size, next;
    int *array;
} List;

int delete(List *list)
{
    if (list->next <= 0)
    {
        printf("\nFila vazia!\n");
        return 0;
    }

    int val = list->array[list->start];

    for (int i = list->start; i < list->next - 1; i++)
    {
        list->array[i] = list->array[i + 1];
    }

    list->next--;
    return val;
}

int insert(List *list, int value)
{
    if (list->next >= list->max_size)
    {
        printf("\nFila cheia!\n");
        return 0;
    }

    list->array[list->next] = value;
    list->next++;
    return 1;
}

int odds(List *list) {
    int count = 0;
    List temp = *list;

    while (temp.next >= temp.start) {
        if (temp.array[temp.next] % 2 != 0) {
            count++;
        }

        temp.next--;
    }

    return count;
}

int main()
{
    int size;
    printf("Digite a quantidade de elementos da fila: ");
    scanf("%d", &size);

    int queue[size];

    List list;
    list.array = queue;
    list.max_size = sizeof(queue) / sizeof(queue[0]);
    list.start = list.next = 0;

    int value;
    do
    {
        printf("Fila -> ");
        for (int i = list.start; i < list.next; i++)
        {
            printf("%d ", list.array[i]);
        }
        
        printf("\n");

        int opt = NONE;
        printf("\nDigite uma opcao:\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Quantidade de impares\n");
        printf("4 - Sair\n");
        scanf("%d", &opt);

        switch (opt)
        {
            case INSERT:
                printf("Digite um valor: ");
                scanf("%d", &value);
                insert(&list, value);
                break;

            case REMOVE:
                delete(&list);
                break;

            case ODDS:
                printf("\nA fila tem %d elementos impares.\n\n", odds(&list));
                break;

            case QUIT:
                printf("Saindo...\n");
                break;
        }
    } while(value >= 0);
}