#include <stdio.h>
#define n_size 4

typedef struct {
    int *array;
    int size;
} Notes;

int calc_media(Notes *notes)
{
    int total = 0;
    for (int i = 0; i < n_size; i++)
    {
        total += notes->array[i];
    }
    
    return total / n_size;
}

int main()
{
    Notes notes;
    int array[n_size];

    notes.array = array;
    notes.size = n_size;

    for (int i = 0; i < n_size; i++)
    {
        printf("Digite uma nota: ");
        scanf("%d", &notes.array[i]);
    }

    printf("A media eh: %d\n", calc_media(&notes));

}
