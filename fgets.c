#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){

    char text[100];

    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);

    int i=0;
    while( i < sizeof(text)){
        if(text[i]='\n'){
            text[i] = '\0';
        }
        i++;
    }

    printf("Length: %s\n", text);
}