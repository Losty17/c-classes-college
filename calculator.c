#include <stdio.h>

enum Options
{
    NONE,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    QUIT
};

int main()
{
    int n1, n2, opt;

    do
    {
        printf("\nEnter your option: ");
        printf("\n1. Add");
        printf("\t2. Subtract");
        printf("\t3. Multiply");
        printf("\t4. Divide");
        printf("\t5. Quit\n");

        scanf("%d", &opt);

        if (opt == QUIT)
        {
            printf("\nQuitting...");
            break;
        }
        
        printf("Enter the first number: ");
        scanf("%d", &n1);

        printf("Enter the second number: ");
        scanf("%d", &n2);

        switch (opt)
        {
            case ADD:
                printf("\n%d + %d = %d", n1, n2, n1 + n2);
                break;

            case SUBTRACT:
                printf("\n%d - %d = %d", n1, n2, n1 - n2);
                break;

            case MULTIPLY:
                printf("\n%d * %d = %d", n1, n2, n1 * n2);
                break;

            case DIVIDE:
                printf("\n%d / %d = %d", n1, n2, n1 / n2);
                break;
        }
    } while (opt != QUIT);
}