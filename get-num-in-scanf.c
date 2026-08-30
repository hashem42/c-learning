#include <stdio.h>

int main()
{
    int age;
    char name[50];

    printf("Age: ");
    int c;
    while (scanf("%d", &age) != 1)
    {
    printf("pls enter an intger for Age: ");

    while ((c = getchar()) != '\n' && c != EOF){
    }
    }
    


    while ((c = getchar()) != '\n' && c != EOF){

    }
    printf("Name: ");
    fgets(name, sizeof(name), stdin);
    int i=0;
    while (name[i] != '\0')
    {
        if (name[i] == '\n')
        {
            name[i] = '\0';
            break;
        }

        i++;
    }

    printf("\nAge: %d\n", age);
    printf("Name: %s", name);

    return 0;
}