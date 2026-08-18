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
    printf("Name: %s\n", id->name);
    printf("price: %.2f\n", id->price);
    printf("Quantity:%d \n", id->Quantity );
}
int main() {

    int x;
    scanf("how many product? %d\n",&x);
    struct product *id = malloc(x*sizeof(struct product));

     if (id == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

     for (int i = 0; i < x; i++)
     {
        scanf("what is name? %s\n",id[i].name);
        scanf("what is price? %s\n",id[i].price);
        scanf("how many is Quantity? %s\n",id[i].Quantity);
      
     }
     
     for (int i = 0; i < x; i++)
     {
        printid(id+i);
     }
     
    
    free(id);
    id = NULL;
     return 0;  
}