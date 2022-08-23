#include <stdio.h>

enum Options
{
    NONE,
    APPEND,
    POP,
    QUIT
};

typedef struct
{
    int value;
    int code;
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
int append(Stack *stack)
{
    if (stack->next > stack->size)
    {
        printf("\nLista cheia\n\n");
        return 0;
    }

    Node value;
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &value.value);

    printf("Digite o código do valor: ");
    scanf("%d", &value.code);

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

    Node n = {-999, -999};
    stack->array[--stack->next] = n;
}

int main()
{
    int size = 0;
    printf("Digite o tamanho da lista: ");
    scanf("%d", &size);

    Node array[size - 1];

    Stack stack;
    stack.array = array;
    stack.size = sizeof(array) / sizeof(array[0]);
    stack.next = 0;

    int option = NONE;
    do {
        printf("Lista: \n");
        for (int i = 0; i < stack.next; i++)
            printf("%d/%d\t", stack.array[i].value, stack.array[i].code);
        printf("\n");

        printf("Digite a opção desejada:\n");
        printf("1 - Inserir\t");
        printf("2 - Remover\t");
        printf("3 - Sair\n");

        scanf("%d", &option);

        printf("\n");

        switch (option)
        {
            case APPEND:
                append(&stack);
                break;

            case POP:
                pop(&stack);
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
