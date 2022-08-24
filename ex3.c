#include <stdio.h>
#include <stdlib.h>

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
        printf("\nLista cheia\n\n");
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
        printf("Lista vazia\n");
        return 0;
    }

    stack->array[--stack->next] = 0;
    return 1;
}

int main()
{
    int size = 10;

    int array[size];

    Stack stack;
    stack.array = array;
    stack.size = sizeof(array) / sizeof(array[0]);
    stack.next = 0;

    for (int i = 0; i < size; i++)
    {
        append(&stack, i);
    }

    printf("Pilha: \n");
    for (int i = 0; i < stack.next; i++)
        printf("%d ", stack.array[i]);
    
    printf("\n");

    int temp;
    for (int i = 0; i < size / 2; i++){
        temp = stack.array[i];
        stack.array[i] = stack.array[size - i - 1];
        stack.array[size - i - 1] = temp;
    }

    printf("\nPilha invertida: \n");
    for (int i = 0; i < stack.next; i++)
        printf("%d ", stack.array[i]);

    printf("\n");
    return 1;
}
