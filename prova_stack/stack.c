#include <stdio.h>

enum Options
{
    NONE,
    APPEND,
    POP,
    CALC,
    QUIT
};

typedef struct
{
    int *array;
    int size, next;
} Stack;

/**
 * @brief Adds a Node to the end of the stack
 *
 * @param stack the stack to be added to
 * @return int 1 if successful, 0 if unsuccessful
 */
int append(Stack *stack, int value)
{
    if (stack->next > stack->size)
    {
        printf("\nPilha cheia\n\n");
        return 0;
    }

    stack->array[stack->next] = value;
    stack->next++;

    return 1;
}

/**
 * @brief Removes the last element of the stack and returns it
 *
 * @param stack Stack to be removed from
 * @return Last node of the stack
 */
int pop(Stack *stack)
{
    if (stack->next <= 0)
    {
        printf("Pilha vazia\n");
        return 0;
    }

    stack->next--;
    int result = stack->array[stack->next];

    return result;
}

float calc_media(Stack *stack)
{
    // old stack
    Stack original = *stack;

    // temp stack
    Stack temp;
    int arr[original.next];
    temp.array = arr;
    temp.size = original.size;
    temp.next = 0;

    int sum = 0;
    int size = original.next;
    int temp_val;

    for (int i = original.next - 1; i >= 0; i--)
    {
        temp_val = pop(&original);
        sum += temp_val;
        append(&temp, temp_val);
    }

    for (int i = temp.next; i > 0; i--)
    {
        append(&original, pop(&temp));
    }

    return (float)sum / size;
}

int calc_min(Stack *stack)
{
    Stack temp;
    int arr[stack->next];
    temp.array = arr;
    temp.size = stack->size;
    temp.next = 0;

    for (int i = stack->next; i >= 0; i--)
    {
        append(&temp, stack->array[i - 1]);
    }

    while (temp.next > 1)
    {
        int first = pop(&temp);
        int second = pop(&temp);

        if (first < second)
        {
            append(&temp, first);
        }
        else
        {
            append(&temp, second);
        }
    }

    return temp.array[0];
}

int calc_max(Stack *stack)
{
    Stack temp;
    int arr[stack->next];
    temp.array = arr;
    temp.size = stack->size;
    temp.next = 0;

    for (int i = stack->next; i > 0; i--)
    {
        append(&temp, stack->array[i - 1]);
    }

    while (temp.next > 1)
    {
        int first = pop(&temp);
        int second = pop(&temp);

        if (first > second)
        {
            append(&temp, first);
        }
        else
        {
            append(&temp, second);
        }
    }

    return temp.array[0];
}

int main()
{
    int size = 0;
    printf("Digite o tamanho da pilha: ");
    scanf("%d", &size);

    int array[size - 1];

    Stack stack;
    stack.array = array;
    stack.size = sizeof(array) / sizeof(array[0]);
    stack.next = 0;

    int option = NONE;
    do
    {
        printf("Pilha-> ");
        for (int i = 0; i < stack.next; i++)
            printf("%d\t", stack.array[i]);
        printf("\n");

        printf("Digite a opção desejada:\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Maior, menor e media\n");
        printf("4 - Sair\n");

        scanf("%d", &option);

        printf("\n");
        float media;
        int max, min, value;

        switch (option)
        {
        case APPEND:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &value);

            append(&stack, value);
            break;

        case POP:
            pop(&stack);
            break;

        case CALC:
            media = calc_media(&stack);
            max = calc_max(&stack);
            min = calc_min(&stack);

            printf("Menor valor: %d\nMaior valor: %d\nMedia: %.2f\n\n", min, max, media);
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
