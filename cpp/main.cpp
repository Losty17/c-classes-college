#include "linkedlist.h"
using namespace L;

int main()
{
    LinkedList list;

    for (int i = 0; i < 200; i++)
    {
        list.unshift(i + 1);
    }

    list.print();
    return 0;
}
