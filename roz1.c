#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product
{
    char name[50];
    float price;
    int Quantity;
};

void printid(const struct product *id)
{
    printf("\n");
    printf("Name: %s\n", id->name);
    printf("Price: %.2f\n", id->price);
    printf("Quantity: %d\n", id->Quantity);
}

int main()
{
    int x;

    printf("How many products? ");
    scanf("%d", &x);

    struct product *id = malloc(x * sizeof(struct product));

    if (id == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < x; i++)
    {
        printf("\nProduct %d\n", i + 1);

        printf("What is name? ");
        scanf("%49s", id[i].name);

        printf("What is price? ");
        scanf("%f", &id[i].price);

        printf("How many? ");
        scanf("%d", &id[i].Quantity);
    }

    printf("\n===== PRODUCTS =====\n");

    for (int i = 0; i < x; i++)
    {
        printid(&id[i]);
    }

    free(id);
    id = NULL;

    return 0;
}