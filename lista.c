#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255


struct Osoba {
    char imie[30];
    char nazwisko[30];
};

struct Wezel {
    struct Osoba* osoba;
    struct Wezel* next;
};

struct Osoba* StworzOsobe(char* imie,char* nazwisko){
    struct Osoba* NowaOsoba = (struct Osoba*)malloc(sizeof(struct Osoba));

    strcpy(NowaOsoba->imie,imie);
    strcpy(NowaOsoba->nazwisko,nazwisko);

    return NowaOsoba;
}

void DodajWezel(struct Wezel* lista,struct Osoba* osoba){
    struct Wezel* NowaOsoba = (struct Wezel*)malloc(sizeof(struct Wezel));

    NowaOsoba->osoba = osoba;
    NowaOsoba->next = NULL;

    struct Wezel* OstatniaOsoba;
    while(lista->next != NULL){
        lista = lista->next;
    }
    OstatniaOsoba = lista;
    OstatniaOsoba->next = NowaOsoba;

}

void Wczytaj_i_stworz(struct Wezel* lista){
    printf("Podaj imie>> ");
    char imie[30];
    scanf("%s",imie);

    printf("Podaj nazwisko>> ");
    char nazwisko[30];
    scanf("%s",nazwisko );

    DodajWezel(lista,StworzOsobe(imie,nazwisko));

}

void wyswietl(struct Wezel* lista){
    struct Wezel* element = lista->next;
    while(element!=NULL){
        printf("\n%s %s",element->osoba->imie,element->osoba->nazwisko);
        element=element->next;
    }
}

int main(void){
    struct Wezel* lista = (struct Wezel*)malloc(sizeof(struct Wezel));
    lista->next = NULL;

    Wczytaj_i_stworz(lista);
    Wczytaj_i_stworz(lista);
    wyswietl(lista);

    return 0;
}
