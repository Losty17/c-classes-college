#include <stdio.h>

typedef struct
{
    int value;
} Node;

typedef struct
{
    Node *array;
    int size, next;
} Stack;

/**
 * @brief Adds a Node to the end of the stack
 * 
 * @param stack the stack to be added to
 * @return int 1 if successful, 0 if unsuccessful
 */
int append(Stack *stack, Node value)
{
    if (stack->next > stack->size)
    {
        printf("\nStack overflow!\n");
        return 0;
    }

    stack->array[stack->next] = value;
    stack->next++;

    return 1;
}

int main()
{
    int size = 0;
    printf("Digite o tamanho das pilhas: ");
    scanf("%d", &size);

    Node negativeArray[size - 1];
    Node positiveArray[size - 1];

    Stack negatives;
    negatives.array = negativeArray;
    negatives.size = sizeof(negativeArray) / sizeof(negativeArray[0]);
    negatives.next = 0;

    Stack positives;
    positives.array = positiveArray;
    positives.size = sizeof(positiveArray) / sizeof(positiveArray[0]);
    positives.next = 0;

    Node value;

    do {
        printf("\nDigite um número a inserir: ");
        scanf("%d", &value.value);

        if (value.value < 0)
        {
            append(&negatives, value);
        }
        else
        {
            append(&positives, value);
        }

        printf("\nPilhas: \n");
        for (int i = 0; i < negatives.next; i++)
            printf("%d\t", negatives.array[i].value);

        printf("\n");

        for (int i = 0; i < positives.next; i++)
            printf("%d\t", positives.array[i].value);

    } while (positives.next <= positives.size || negatives.next <= negatives.size);

    printf("\nStack overflow!!\n");
    return 1;
}