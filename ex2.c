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
    int start, max_size, next;
    int *array;
} List;

int delete(List *list)
{
    if (list->next <= 0)
    {
        printf("\nList is empty!\n");
        return 0;
    }

    for (int i = list->start; i < list->next - 1; i++)
    {
        list->array[i] = list->array[i + 1];
    }

    list->next--;
    return 1;
}

int insert(List *list, int value)
{
    if (list->next >= list->max_size)
    {
        printf("\nList overflow!\n");
        return 0;
    }

    list->array[list->next] = value;
    list->next++;
    return 1;
}

int main()
{
    int p_queue[3];
    int i_queue[3];

    List p_list;
    p_list.array = p_queue;
    p_list.max_size = sizeof(p_queue) / sizeof(p_queue[0]);
    p_list.start = p_list.next = 0;

    List i_list;
    i_list.array = i_queue;
    i_list.max_size = sizeof(p_queue) / sizeof(p_queue[0]);
    i_list.start = i_list.next = 0;

    int value;
    do
    {
        printf("Lista P -> ");
        for (int i = p_list.start; i < p_list.next; i++)
        {
            printf("%d ", p_list.array[i]);
        }
        
        printf("\n");

        printf("Lista I -> ");
        for (int i = i_list.start; i < i_list.next; i++)
        {
            printf("%d ", i_list.array[i]);
        }

        printf("\nDigite um valor:\n");
        scanf("%d", &value);

        if (value == 0)
        {
            delete(&p_list);
            delete(&i_list);
        }
        else if (value % 2 == 0)
        {
            insert(&p_list, value);
        }
        else
        {
            insert(&i_list, value);
        }
    } while(value >= 0);
}