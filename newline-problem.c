#include <stdio.h>

int main()
{
    int age;
    char name[50];

    printf("Age: ");
    scanf("%d", &age);

    int c;
    while ((c = getchar()) != '\n' && c != EOF){

    }
    printf("Name: ");
    fgets(name, sizeof(name), stdin);

    printf("\nAge: %d\n", age);
    printf("Name: %s", name);

    return 0;
}