#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
1. Dynamiczna tablica (O)

Napisz funkcję, która stworzy dynamicznie tablicę o długości podanej przez argument wywołania i zwróci wskaźnik na zaalokowaną pamięć. Ponadto w funkcji tablica powinna zostać wypełniona kolejnymi, nieparzystymi liczbami całkowitymi (począwszy od 1). Funkcję należy użyć w main-ie do utworzenia tablicy o rozmiarze podanym z klawiatury, następnie tablicę należy wypisać na ekranie. Proszę pamiętać o zwalnianiu pamięci przydzielonej dynamicznie. */



int main(){
    
    int dlugosc;
    
    scanf("%d",&dlugosc);
    int* tab = (int*)malloc(sizeof(int)*dlugosc);
    
    for(int i =0;i<dlugosc;i++){
        *(tab+i)=2*i+1;
    }
    
    for(int i = 0;i<dlugosc;i++){
        printf("%d\n",*(tab+i));
    }
    
    free(tab);
    return 0;
}


