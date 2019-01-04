#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
2. Tablica 2D  (O)

Napisz program zawierający następujące funkcje:
double** createMatrix(int n);
która tworzy macierz o wymiarze nxn. Fukcja zwraca utworzoną tablicę.
W funkcji każdy wiersz ma być alokowany osobno. W funkcji należy użyć funkcji deleteMatrix().

void fillMatrix(double** tab, int n);
która otrzymuje macierz tab o wymiarze ''nxn'', a następnie wypełnia ją kolejnymi liczbami naturalnymi począwszy od 1.

void printMatrix(double** tab, int n);
która wypisuje na ekran macierz tab o wymiarze ''nxn''.

void deleteMatrix(double*** a_tab, int n);
która otrzymuje poprzez adres macierz utworzoną przez funkcję createMatrix() i zwalnia zajmowaną przez macierz pamięć, a wskaźnik reprezentujący tablicę ustawia na NULL.


W programie (main) należy użyć  wymienionych powyżej funkcji do utworzenia tablicy o ustalonym przez siebie  rozmiarze, wypełnienia jej i zwolnienia całej przydzielonej pamięci po wypisaniu tablicy.

*/

int* createMatrix(int n){
    int* buffer;
    int* matrix = (int*)malloc(sizeof(int)*n*n);
    for(int i =0;i<n;i++){
        buffer = (int*)malloc(sizeof(int)*n);
        matrix[i] = *buffer;
        free(buffer);
    }
    return matrix;
}

void fillMatrix(int* tab,int n){
    for(int i =0;i<n*n;i++){
        *(tab+i) = i+1;
    }
}

void printMatrix(int* tab, int n){
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%3d",*(tab+i*n+j));
        }
        printf("\n");
    }
}


int main(){
    printf("Podaj rozmiar>>");
    int n;
    scanf("%d",&n);
    
    int* tab = createMatrix(n);
    fillMatrix(tab,n);
    printMatrix(tab,n);
    
    return 0;
}


