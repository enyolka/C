#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 255

struct Person {
    char *full_name;
    char pesel[12]; // 11 + pole na \0
};

// wezel listy osob
struct PersonNode {
    struct Person* person; // wskaznik na osobe
    struct PersonNode* next; // wskaznik na next element
};

//alokacja pamieci dla osoby + tworzenie
struct Person* createPerson(char* name,char* pesel){
    struct Person* newPerson = (struct Person*)malloc(sizeof(struct Person)); // alokacja bajtow na osobe
    
    newPerson->full_name = malloc(strlen(name)+1); // alokacja tylu bajtow co ma imie + 1 na \0
    
    
    // kopiowanie z buforow
    strcpy(newPerson->full_name,name);
    strcpy(newPerson->pesel,pesel);
    
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

void addNewPersonNode(struct PersonNode* list,struct Person* person){
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



void fillPersonList(struct PersonNode* pNode){

    char buffer[2];
    int len;
    char* full_name;
    char* pesel;
    
    printf("\nCzy chcesz dodac osobe do listy? [y/n]: ");
    while(strcmp(gets(buffer),"n")!=0){
        
        printf("Podaj imie i nazwisko>> ");
        char *full_name_buffer = (char *)malloc((sizeof(char)) * MAX);
        gets(full_name_buffer);
        len = strlen(full_name_buffer);
        full_name = (char*)malloc(sizeof(char)*len + 1);
        strcpy(full_name,full_name_buffer);
        free(full_name_buffer);
        
        printf("Podaj pesel>> ");
        char *pesel_buffer = (char *)malloc((sizeof(char))* MAX);
        gets(pesel_buffer);
        len = strlen(pesel_buffer);
        pesel = (char*)malloc(sizeof(char) * len +1);
        strcpy(pesel,pesel_buffer);
        free(pesel_buffer);
        
        addNewPersonNode(pNode,createPerson(full_name,pesel));
        
        printf("\nCzy chcesz kontunuowac dodawanie?[y/n]: ");
    }
}

void printPeople(struct PersonNode* pNode){
    printf("\n==========================\n");
    //wez liste podan
    struct PersonNode* element = pNode->next;
    int i = 1;
    while(element!=NULL){
        printf("\n\n%d.Imie i nazwisko: %s\nPesel: %s",i,element->person->full_name,element->person->pesel);
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

void usunElement(struct PersonNode* pNode,int n){
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




int main(void) {
    
    struct PersonNode* pNode = malloc(sizeof(struct PersonNode));
    
    pNode->next = NULL;
    
    fillPersonList(pNode);
    
    printPeople(pNode);
    
    printf("\n\nDLUGOSC : %d",dlugoscListy(pNode));
    
    int d;
    printf("\nKtory element usunac? ");
    scanf("%d",&d);
    
    usunElement(pNode,d);
    
    printf("\n\nDLUGOSC : %d",dlugoscListy(pNode));
    
    printPeople(pNode);
    
    
    return 0;
}