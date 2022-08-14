#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

enum Options {
    INSERT,
    DELETE,
    QUIT
};

typedef struct {
    char name[20];
    int code;
    int value;
} Node;

int length(Node array[]) {
    return sizeof(array) / sizeof(array[0]);
}

int insert(Node list[], int array_start, int array_end, int list_start, int list_end, Node node) {

}

void main() {
    setlocale(LC_ALL, "");
    int option = 0;

    Node list[10];

    int array_start, array_end, list_start, list_end;

    array_start = 0;
    array_end = length(list);
    list_start = list_end = array_start - 1;

    do {
        printf("Escolha uma opcao: \n1 - Inserir\n2 - Remover\n3 - Sair\n");
        scanf("%d", &option);
        option--;

        switch (option) {
            case INSERT:
                int pos;
                printf("Digite a posicao para inserir o valor: ");
                scanf("%d", &pos);

                if (pos < list_start || pos > list_end) {
                    printf("Posicao invalida\n");
                    break;
                } else if (list_end == array_end) {
                    printf("Lista cheia\n");
                    break;
                }

                Node value;
                printf("Digite o nome do valor a ser inserido: (20 chars)");
                scanf("%s", &value.name);
                printf("Digite o código do valor a ser inserido: ");
                scanf("%d", &value.code);
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &value.value);

                break;

            case DELETE:
                delete();
                break;
        }
    } while (option != QUIT);
}
