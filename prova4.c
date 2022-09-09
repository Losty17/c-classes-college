#include <stdio.h>
#define SIZE 10

typedef struct {
    int *arr;
    int start, end, min, max;
} List;

int insert(List *list, int pos, int value) {
    if ((list->min == list->start && list->max == list->end) ||
        (pos > list->end - list->start + 2) || (pos <= 0) ||
        (list->start == -1 && pos != 1) || (pos > list->max - 1)
    ) {
        printf("Impossível realizar a inserção!\n");
        return 0;
    } else if (list->start == -1) {
        list->start = list->end = list->min;
    } else if (list->end != list->max) {
        for (int i = list->end; i >= list->start + pos - 1; i--)
            list->arr[i + 1] = list->arr[i];
        list->end++;
    } else {
        for (int i = list->start; i <= list->start + pos - 2; i++)
            list->arr[i - 1] = list->arr[i];
        list->start--;
    }

    list->arr[list->start + pos - 1] = value;
    return 1;
}

int delete(List *list, int pos) {
    // ao remover, verificar quantos nodos existem para frente ou para trás
    // e mover os itens baseado em onde há menos nodos, consequentemente mudando
    // o list->start ou o list->end
    // após, mostrar quantos nodos foram movidos e para qual direcao
    
    printf("%d %d", pos, list->start);
    return 0;
}

void populate(List *list) {
    for (int i = list->min + 1; i < list->max; i++)
        insert(list, i, i);
}

void display(List *list) {
    for (int i = list->start; i < list->end; i++)
        printf("%d\t", list->arr[i]);

    printf("\n");    
}

int main() {
    int arr[SIZE];

    List list;
    list.arr = arr;
    list.max = sizeof(arr) / sizeof(arr[0]);
    list.min = 0;
    list.start = list.end = list.min = 0;

    populate(&list);
    display(&list);
}