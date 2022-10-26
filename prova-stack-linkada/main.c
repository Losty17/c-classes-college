/**
 * @file main.c
 * @author Vinícius Kappke (m71254) Leonardo Mattos (m131571)
 * @brief Diferenciação de pilhas por pares e ímpares
 *
 * @version 0.1
 * @date 2022-10-18
 *
 * @copyright Copyright (c) 2022
 *
 */
// #include "linkedlist.h" removed because brrrrrrrrrrrrrrrrrrrrr
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    int pos;
    struct node *next;
};
typedef struct node node_t;

void printstack(node_t *head)
{
    node_t *temp = head;

    printf("\n");
    while (temp != NULL)
    {
        printf("%d", temp->value);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

/**
 * @brief Helper function that creates a node to be inserted into the stack
 *
 * @param value
 * @return node_t*
 */
node_t *create_node(int value)
{
    node_t *result = (node_t *)malloc(sizeof(node_t));
    result->value = value;
    result->pos = 0;
    result->next = NULL;
    return result;
}

/**
 * @brief Adds a node at the top of the stack
 *
 * @param head the target list to add the element
 * @param value the value to be added
 * @return node_t*
 */
node_t *add(node_t *head, int value)
{
    node_t *new_node = create_node(value);
    node_t *tmp = head;

    if (head == NULL)
    {
        head = new_node;
        return head;
    }

    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = new_node;
    return new_node;
}

int main()
{
    node_t *evens = NULL;
    node_t *odds = NULL;
    node_t *tmp = NULL;
    int value;

    do {
        printf("Digite um valor a inserir (0 para sair) -> ");
        scanf("%d", &value);

        if (value % 2 == 0) {
            tmp = add(evens, value);
            if (evens == NULL) evens = tmp;
        }
        else {
            tmp = add(odds, value);
            if (odds == NULL) odds = tmp;
        }

        printf("Pares -> ");
        printstack(evens);
        printf("Impares -> ");
        printstack(odds);
    } while (value != 0);
}