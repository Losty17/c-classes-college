#include <iostream>

namespace L
{
    struct node
    {
        int value;
        node *next;
    };
    typedef struct node node_t;

    class LinkedList
    {
    public:
        node_t *unshift(int value)
        {
            node_t *new_node = this->create_node(value);
            new_node->next = this->head;
            this->head = new_node;
            return new_node;
        }

        void print()
        {
            std::cout << "\n";
            this->tmp = this->head;
            while (this->tmp != NULL)
            {
                std::cout << this->tmp->value << " ";
                this->tmp = this->tmp->next;
            }
            std::cout << "\n";
        }

    private:
        node_t *head;
        node_t *tmp;

        node_t *create_node(int value)
        {
            node_t *result = (node_t *)malloc(sizeof(node_t));
            result->value = value;
            result->next = NULL;
            return result;
        }
    };
}