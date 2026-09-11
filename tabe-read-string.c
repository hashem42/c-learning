#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_string(char **str, int *i){
char *ps;
char c;
int capacity =2;

*str = malloc(capacity*sizeof(char));
  if (*str == NULL)
{
    return;
}

  printf("Enter String : ");
 while (1)
{
    c = getc(stdin);
    if (c == '\n'){
        
        break;
    }
   
    if (*i == (capacity-1))
{
    capacity *= 2;

    ps = realloc(*str, capacity * sizeof(char));

    if (ps == NULL)
    {
        free(*str);
        return;
    }

   *str = ps;
}
(*str)[*i] = c;
(*i)++;
}

  (*str)[*i] = '\0'; 
printf("Name: %s\n",*str);
printf("Length: %d\n", *i);

}



int main()
{
char *name;
int i=0;

read_string(&name, &i);

if (name == NULL)
{
    return 1;
}



free(name);
return 0;
}
