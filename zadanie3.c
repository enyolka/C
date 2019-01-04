#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*2. Powiększanie tablicy (O)

Napisz funkcję
float * add(float* tab, int n, float new_elem);
która powiększa przekazaną  n-elementową tablicę o jeden element new_elem (umieszczany na końcu powiększonej tablicy). Funkcja zwraca adres powiększonej tablicy (nowo przydzielonej pamięci) lub NULL w wypadku niepowodzenia. Funkcja powinna zostać wywołana 10-krotnie w programie głównym (main) celem utworzenia tablicy 10-cio elementowej, która następnie ma zostać wypisana. W main wskaźnik, który stanie się powiększaną tablicą należy ustawić wstępnie na NULL. W tworzonej funkcji proszę nie używać funkcji realloc().

UWAGI:

Kolejność działań funkcji: przydzielenie pamięci o 1 większej od n, przepisanie zawartości tablicy do nowo przydzielonego miejsca, zwolnienie pamięci tablicy (starej), zwrócenie wskaźnika na nowo przydzieloną pamięć (nowej tablicy).
*/

float* add(float* tab,int n,float new_elem){

    float* tmp = (float*)malloc(sizeof(float)*(n+1));

    for(int i=0;i<n;i++){
        tmp[i]=tab[i];
    }
    tmp[n]=new_elem;

    //free(tab);

    return tmp;
}


int main(){
    float tab[3] = {2.1,3.2,3.5};
    float* t2 = add(tab,3,5.2);
    for(int i = 0;i<4;i++){
        printf("%f\n",t2[i]);
    }
      
    return 0;
}
