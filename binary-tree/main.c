#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "print.h"

int main()
{    
    srand(time(NULL));
    node_t *root = NULL;

    // insert random values based on the first one
    for (int i = 0; i < 40; i++)
    {
        value_t *value = (value_t *)malloc(sizeof(value_t));
        value->code = rand() % 100;
        value->name = "name";

        insert(&root, value);
    }

    print_ascii_tree(root);

    int code = 0;
    printf("\nNumber to find: ");
    scanf("%d", &code);

    node_t *tmp = find(root, code);

    if (tmp != NULL)
    {
        printf("Found: %d - %s \n", tmp->element->code, tmp->element->name);
    }
}