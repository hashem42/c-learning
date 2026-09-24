#include<stdio.h>
#include <stdlib.h>

char *duplicate_string(const char *source){
    int count=1;
    int i=0;
    char *copy_src;
    while(source[i] != '\0'){
        count=count+1;
        i++;
    }

    copy_src = malloc(count*sizeof(char));


      if (copy_src == NULL)
    {
        return NULL;
    }

    int j=0;
     while(!(j == count)){
        copy_src[j] = source[j];
        j++;
    }

    return copy_src;
}


int main(){
   
    char *copy = duplicate_string("Hello C");
    if (copy == NULL)
    {
       return 1;
    }
    printf("address: %p",copy);
    free(copy);
    return 0;
}