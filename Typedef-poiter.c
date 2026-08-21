#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
    AVAILABLE = 1,
    SOLD_OUT = 2
} Status;

typedef struct {
     char name[50];
     float price;
     int quantity;
    Status sta;
}  Product;


void printproduct(const Product *id)
{
    printf("\n");
    printf("Name: %s\n", id->name);
    printf("Price: %.2f\n", id->price);
    printf("Quantity: %d\n", id->quantity);

    printf("Status: ");

    switch (id->sta)
    {
        case AVAILABLE:
            printf("AVAILABLE\n");
            break;

        case SOLD_OUT:
            printf("SOLD OUT\n");
            break;

        default:
            printf("UNKNOWN\n");
            break;
    }
}


int main(){
    int x;

    printf("How many products? ");
    scanf("%d", &x);

    Product *id = malloc(x * sizeof(Product));

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
        scanf("%d", &id[i].quantity);

        int statusInput;

        do
        {
            printf("Status (1 = AVAILABLE, 2 = SOLD OUT): ");
            while(scanf("%d",&statusInput) != 1)
          {
             printf("Please enter an integer: ");
             while(getchar() != '\n');
          }

            if (statusInput != 1 && statusInput != 2)
            {
                printf("Invalid status! Please enter 1 or 2.\n");
            }

        } while (statusInput != 1 && statusInput != 2);

        id[i].sta = statusInput;
    }

    printf("\n===== PRODUCTS =====\n");

     for (int i = 0; i < x; i++)
    {
        printproduct(&id[i]);
    }

     free(id);
     id = NULL;

    return 0;

}