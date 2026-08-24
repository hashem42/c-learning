#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (){

char name[50];
char namecopy[50];
int i=0;

 printf("Please enter a string: ");
  scanf("%s", name);

/* while (name[i+1] != '\0')
 {
   printf("your name is :%s\n", i);
   i++;
 }
*/
printf("%zu\n", strlen(name));



printf("%s\n", strcpy(namecopy, name));


if (strcmp(name,namecopy) == 0)
{
    printf("Same\n");
}
else{
    printf("Not Same\n");
}

char second[50]="is learning c.";
strcat(namecopy, second);
printf("your copy of name now is :%s\n",namecopy);

return 0;
}