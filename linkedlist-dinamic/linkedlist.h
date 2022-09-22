/**
 * @file linkedlist.h
 * @author Vinícius Kappke (m71254)
 * @brief Funções úteis para listas encadeadas (em progresso)
 * @version 0.1
 * @date 2022-09-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};
typedef struct node node_t;

void printlist(node_t *head) {
    node_t *temp = head;

    printf("\n");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * @brief Helper function that creates a node to be inserted into the list
 * 
 * @param value 
 * @return node_t* 
 */
node_t *create_node(int value) {
    node_t *result = (node_t *)malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

/**
 * @brief inserts a node at the start of the linked list
 * 
 * @param head the start element of the list
 * @param value the value to be inserted
 * @return node_t* 
 */
node_t *unshift(node_t **head, int value) {
    node_t *new_node = create_node(value);
    new_node->next = *head;
    *head = new_node;
    return new_node;
}

/**
 * @brief inserts a node after the specified element on the linked list
 * 
 * @param position the element before the position to be inserted
 * @param value the value to be inserted
 * @return node_t* 
 */
node_t *insert(node_t *position, int value) {
    node_t *new_node = create_node(value);

    new_node->next = position->next;
    position->next = new_node;

    return new_node;
}

/**
 * @brief Adds a node at the tail of the linked list
 * 
 * @param head the target list to add the element
 * @param value the value to be added
 * @return node_t* 
 */
node_t *add(node_t *head, int value) {
    node_t *new_node = create_node(value);
    node_t *tmp = head;

    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = new_node;
    return new_node;
}

node_t *find(node_t *head, int value) {
    node_t *temp = head;

    while (temp != NULL) {
        if (temp->value == value) return temp;
        temp = temp->next;
    }

    return NULL;
}
