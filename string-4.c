#include <stdio.h>

int my_strcmp(const char *a, const char *b)
{
    int i=0;
  while (*(a+i)!='\0' &&  *(b+i) != '\0')
  {
    if(a[i] == b[i]){
        return 1;
        i++;  
    }
    else{
        return a[i] - b[i];
        break;
    }
      
  }
     return 1;
}

int main()
{
char a[] = "hell";
char b[] = "hello";

int result = printf("%d",my_strcmp(a,b));

    return 0;
}