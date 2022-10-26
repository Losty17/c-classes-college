#include <stdlib.h>

typedef struct value {
    int code;
    char *name;
} value_t;

struct node
{
    struct node *left, *right;
    value_t *element;
};
typedef struct node node_t;

void insert(node_t **t, value_t *value)
{
    if (*t == NULL)
    {
        // if the node is empty, create a new node
        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        new_node->element = value;
        new_node->left = new_node->right = NULL;

        // point the given node to the new node
        *t = new_node;
    }
    else if (value->code <= (*t)->element->code)
    {
        // insert into the left subtree if the value is less than or equal to the current node
        insert(&(*t)->left, value);
    }
    else if (value->code > (*t)->element->code)
    {
        // insert into the right subtree if the value is greater than the current node
        insert(&(*t)->right, value);
    }
}

node_t *find(node_t *t, int value)
{
    if (t == NULL)
    {
        // if the node is empty, return NULL
        return NULL;
    }
    else if (value == t->element->code)
    {
        // if the value is equal to the current node, return the current node
        return t;
    }
    else if (value < t->element->code)
    {
        // search the left subtree if the value is less than the current node
        return find(t->left, value);
    }
    else if (value > t->element->code)
    {
        // search the right subtree if the value is greater than the current node
        return find(t->right, value);
    }

    return NULL;
}