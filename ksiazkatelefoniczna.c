#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 255

struct Person {
    char imie[30];
    char nazwisko[30];
    long int numer;
};

// wezel listy osob
struct PersonNode {
    struct Person* person; // wskaznik na osobe
    struct PersonNode* next; // wskaznik na next element
};

//alokacja pamieci dla osoby + tworzenie
struct Person* stworz_osobe(char *imie,char *nazwisko,long int numer){
    struct Person* newPerson = (struct Person*)malloc(sizeof(struct Person)); // alokacja bajtow na osobe
    

    strcpy(newPerson->imie,imie);
    strcpy(newPerson->nazwisko,nazwisko);
    newPerson->numer = numer;
    
    return newPerson;
}

// przyjmuje start listy , zwraca ostatni element
struct PersonNode* getLastPersonNode(struct PersonNode* list){
    while(list->next != NULL){ // dopoki wezel ma potomka , dopoki istnieje kolejny element listy
        list = list->next; //przejdz do niego
    }
    return list;
}

// dodajemy nowy wezel na koniec
// list - wskaznik na start listy
// full_name - wsk na buffor full_name
// pesel - wsk na buffor z pesel

void dodaj_wezel(struct PersonNode* list,struct Person* person){
    // tworzenie wezla
    struct PersonNode* newPersonNode = malloc(sizeof(struct PersonNode));
    
    //ustawiamy w tym wezle osobe na ta ktora podalismy jako argument funkcji
    newPersonNode->person = person;
    // nastepny element , potomek pusty,bo ten wezel jest dodawany jako ostatni
    newPersonNode->next = NULL;
    
    
    //znajdz koncowy element listy
    struct PersonNode* last;
    last = getLastPersonNode(list);
    // ustawiamy ostatniemu elementowi , element nastepny na biezacy
    last->next = newPersonNode;
    
}



void dodaj(struct PersonNode* pNode){

    char buffer[2];
    int len;
    char imie[30];
    char nazwisko[30];
    long int numer;
    
        
    printf("Podaj imie>> ");
    scanf("%s",imie);
    printf("Podaj nazwisko>> ");
    scanf("%s",nazwisko);
  /*  char *imie_buffer = (char *)malloc((sizeof(char)) * MAX);
    gets(imie_buffer);
    len = strlen(imie_buffer);
    imie = (char*)malloc(sizeof(char)*len + 1);
    strcpy(imie,imie_buffer);
    free(imie_buffer);
        
        
    printf("Podaj nazwisko>> ");
    char *nazwisko_buffer = (char *)malloc((sizeof(char))* MAX);
    gets(nazwisko_buffer);
    len = strlen(nazwisko_buffer);
    nazwisko = (char*)malloc(sizeof(char) * len +1);
    strcpy(nazwisko,nazwisko_buffer);
    free(nazwisko_buffer); */
        
        
        
    printf("Podaj numer>> ");

    scanf("%ld",&numer);
        
        
    dodaj_wezel(pNode,stworz_osobe(imie,nazwisko,numer));
        
}

void wyswietl(struct PersonNode* pNode){
    printf("\n==========================\n");
    //wez liste podan
    struct PersonNode* element = pNode->next;
    int i = 1;
    while(element!=NULL){
        printf("\n\n%d.Imie i nazwisko: %s %s\t%ld",i,element->person->imie,element->person->nazwisko,element->person->numer);
        element = element->next;
        i++;
    }
}

int dlugoscListy(struct PersonNode* pNode){
    int d=0;
    struct PersonNode* element = pNode->next;

    while(element!=NULL){
        element = element->next;
        d++;
    }
    return d;
}

void usun(struct PersonNode* pNode,int n){
    struct PersonNode* wsk = pNode;
    int i =0;
    while(wsk->next != NULL){
        if(i==n-1){
            struct PersonNode* usuwany = wsk->next;
            wsk->next = usuwany->next;
            free(usuwany);
        }else{
            wsk = wsk->next;
        }
        
        i++;
    }
}

void opcje(void){
    printf("\n\n|================|\n");
    printf("|=Co mam zrobic?=|\n");
    printf("|================|\n");
    printf("|======[1]=======|\n");
    printf("|=Dodaj kontakt==|\n");
    printf("|================|\n");
    printf("|======[2]=======|\n");
    printf("|Wyswiel kontakty|\n");
    printf("|================|\n");
    printf("|======[3]=======|\n");
    printf("|====Usuwanie====|\n");
    printf("|================|\n");
    printf("|======[4]=======|\n");
    printf("|====Wyjscie=====|\n");
    
}


int main(void) {
    
    struct PersonNode* lista = malloc(sizeof(struct PersonNode));
    
    lista->next = NULL;
    
    int wybor;
    int LOOP = 1;
    do{
        opcje();
        scanf("%d",&wybor);

        switch(wybor){
            case 1:{
                
                dodaj(lista);
                break;
            }
            case 2:{
                if(dlugoscListy(lista)==0){
                    printf("\n\nTwoja ksiazka telefoniczna jest pusta! \n\n");
                    break;
                }
                wyswietl(lista);
                break;
            }
            case 3:{
                printf("\n\nKtory kontakt chcesz usunac? Podaj nr: ");
                int n;
                scanf("%d",&n);
                usun(lista,n);
                break;
            }

        }
    }while(wybor!=4 && wybor < 4);
    
    return 0;
}
