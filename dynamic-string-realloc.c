#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
  char *str, c,*ps;
  int i = 0,capacity =2;

  str = malloc(capacity*sizeof(char));

  printf("Enter String : ");
 while (1)
{
    c = getc(stdin);
    if (c == '\n'){
        
        break;
    }
   
    if (i == (capacity-1))
{
    capacity *= 2;

    ps = realloc(str, capacity * sizeof(char));

    if (ps == NULL)
    {
        free(str);
        return 1;
    }

    str = ps;
}
str[i] = c;
i++;
}

  str[i] = '\0'; 

  printf("\nThe entered string is : %s", str);

  free(str); 

  return 0;
}
