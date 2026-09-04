#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
  char *str, c,*ps;
  int i = 0;

  str = malloc(2*sizeof(char));

  printf("Enter String : ");
 while (1)
{
    c = getc(stdin);

    if (c == '\n')
        break;

    ps = realloc(str, (i+2) * sizeof(char));

    if (ps == NULL)
    {
        free(str);
        return 1;
    }

    str = ps;

    str[i] = c;

    i++;
}

  str[i] = '\0'; 

  printf("\nThe entered string is : %s", str);

  free(str); 

  return 0;
}
