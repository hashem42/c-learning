#include <stdio.h>

int my_strlen(const char *text)
{
    int count = 0;

    while (text[count] != '\0')
    {
        count++;
    }

    return count;
}

int main()
{
    char text[50];

    printf("string is: ");
    scanf("%49s", text);

    int length = my_strlen(text);

    printf("Length: %d\n", length);

    return 0;
}