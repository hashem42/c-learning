#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num;

    printf("pls enter a number? ");
    scanf("%d", &num);

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }

    char *string = malloc((num + 1) * sizeof(char));

    if (string == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("pls enter ur string: ");
    fgets(string, num + 1, stdin);

    printf("string is: %s", string);

    free(string);

    return 0;
}