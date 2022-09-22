/**
 * @file main.c
 * @author Vinícius Kappke (m71254)
 * @brief Exercícios 1 e 2 sobre lista encadeada. 
 * Depende do arquivo `linkedlist.h`, anexado junto a este arquivo
 * 
 * @version 0.1
 * @date 2022-09-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "linkedlist.h"
#include <stdlib.h>
#include <time.h>

enum Options {
    NONE,
    UNSHIFT,
    REMOVE,
    SIZE,
    LAST_ELEMENT,
    QUIT
};

int main() {
    srand(time(NULL));
    node_t *head = NULL;
    node_t *tmp = NULL;

    int opt = NONE;
    int value;

    int fill = 0;

    printf("Digite a quantidade de elementos a serem inseridos na lista (0 para ignorar): ");
    scanf("%d", &fill);

    for (int i = 0; i < fill; i++) unshift(&head, i + 1);

    do {
        printlist(head);

        printf("1- Inserir\n2- Remover\n3- Tamanho da Lista\n4- Ultimo elemento\n5- Sair\n");
        printf("Digite uma opção: ");
        scanf("%d", &opt);

        switch (opt) {
            case UNSHIFT:
                printf("Digite o valor a inserir no começo da lista\n");
                scanf("%d", &value);
                unshift(&head, value);
                break;

            case REMOVE:
                printf("Não implementado\n");
                break;

            case SIZE: {
                // Determinate the number of nodes on the list
                tmp = head;
                int count = 0;
                while (tmp != NULL) {
                    count++;
                    tmp = tmp->next;
                }

                printf("A lista tem %d elementos\n", count);
                break;
            }

            case LAST_ELEMENT:
                // find the last element (tail) of the list
                tmp = head;
                while (tmp->next != NULL) {
                    tmp = tmp->next;
                }

                printf("O último nodo da lista é %d\n", tmp->value);
                break;
        }
    } while(opt != QUIT);
}
