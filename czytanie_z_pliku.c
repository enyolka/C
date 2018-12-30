#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void) {
    
    FILE *plik;
    if((plik=fopen("test.txt","r"))==NULL){
        printf("ERROR!");
        exit(1);
    }
    char buffor[100];
    
    int najdluzszy = 0;
    char linia[100];
    int dlugosc;
        while(fgets(buffor,sizeof buffor,plik)!=NULL){
        printf("%s",buffor);
        dlugosc = strlen(buffor);
        if(dlugosc > najdluzszy) {
            najdluzszy = dlugosc;
            strcpy(linia,buffor);
        }
    }
    
    
    fclose(plik);
    
    printf("NAJDLUZSZA LINIJKA MA %d znakow! \n",najdluzszy);
    printf("%s",linia);
    return 0;
}