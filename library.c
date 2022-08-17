/**
 * @file library.c
 * @authors Leonardo Mattos, Rodrigo Mello, Vinícius Kappke
 * @brief Esse programa utiliza uma lista linear para gerenciar uma biblioteca com 10 livros
 * @date 2022-08-16
 */
#include <stdio.h>

enum Options
{
    NONE,
    INSERT,
    REMOVE,
    QUIT
};

typedef struct
{
    int code, year;
    char name[50];
} Book;

typedef struct
{
    int start, end, array_start, array_end;
    Book *array;
} List;

int delete(List *list)
{
    int pos;
    printf("\nQual posição você deseja remover? \n");
    scanf("%d", &pos);

    if ((pos <= 0) || (pos > list->end - list->start + 1)) printf("\nImpossível remover este valor");
    else
    {
        for (int i = list->start + pos - 1; i <= list->end - 1; i++)
        {
            list->array[i] = list->array[i + 1];
        }
        list->end--;

        if (list->end == list->start - 1) list->start = list->end = -1;
        printf("\nValor removido com sucesso!");
    }
}

int insert(List *list)
{
    int pos;
    printf("Digite a posição na qual deseja inserir a informação:\n");
    scanf("%d", &pos);

    if ((list->array_start == list->start && list->array_end == list->end) || (pos > list->end - list->start + 2) || (pos <= 0) || (list->start == -1 && pos != 1))
    {
        printf("Impossível realizar a inserção!\n");
        return 0;
    }
    else if (list->start == -1)
    {
        list->start = list->end = list->array_start;
    }
    else if (list->end != list->array_end)
    {
        for (int i = list->end; i >= list->start + pos - 1; i--)
            list->array[i + 1] = list->array[i];
        list->end++;
    }
    else
    {
        for (int i = list->start; i <= list->start + pos - 2; i++)
            list->array[i - 1] = list->array[i];
        list->start--;
    }

    Book book;
    printf("Digite o código do livro:\n");
    scanf("%d", &book.code);
    printf("Digite o nome do livro:\n");
    scanf("%s", &book.name);
    printf("Digite o ano do livro:\n");
    scanf("%d", &book.year);

    list->array[list->start + pos - 1] = book;
    printf("Informação inserida com sucesso!\n");
}

int main()
{
    int option = 0;

    Book library[10];

    List list;
    list.array = library;
    list.array_end = sizeof(library) / sizeof(library[0]);
    list.start = list.end = list.array_start - 1;

    do
    {
        printf("\nLista:\n");
        for (int i = list.start; i <= list.end; i++)
            printf("%s\t", list.array[i].name);
        printf("\nDigite a opção desejada:\n");
        printf("\n1 - Inserir\n2 - Remover\n3 - Sair\n");
        scanf("%d", &option);

        switch (option)
        {
            case INSERT:
                insert(&list);
                break;

            case REMOVE:
                delete(&list);
                break;

            case QUIT:
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
                break;
        }
    } while (option != QUIT);
}