#include <stdio.h>

int main()
{
    char text[100];

    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);

    int i = 0;

    while (text[i] != '\0')
    {
        if (text[i] == '\n')
        {
            text[i] = '\0';
            break;
        }

        i++;
    }

    printf("String with fgets is: %s\n", text);

    return 0;
}