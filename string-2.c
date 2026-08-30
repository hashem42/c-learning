#include <stdio.h>

int main()
{
    char text[] = "hello";
    char *p = text;

    int i = 0;

    while (p[i] != '\0')
    {
        printf("character %d: %c\n", i, *(p + i));
        i++;
    }

    printf("--------------------------------------\n");


    int count = 0;

    while (p[count] != '\0')
    {
        count++;
    }

    printf("length: %d\n", count);

    printf("--------------------------------------\n");

    p[0] = 'j';

    printf("new string is: %s\n", p);

    return 0;
}