#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 255



int main(){
    
    char* tablica_stringow[5];
    
    for(int i = 0 ; i < 5 ; i++){
        char* buffor = (char*)malloc(sizeof(char)*MAX);
        printf("Podaj napis %d >> ",i+1);
        gets(buffor);
        tablica_stringow[i] = (char*)malloc(sizeof(char)*strlen(buffor));
        strcpy(tablica_stringow[i],buffor);
        free(buffor);
    }
    
    for(int i =0;i < 5 ; i++){
        printf("%s\n",tablica_stringow[i]);
    }
    
    
    return 0;
}


