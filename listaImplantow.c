#include "listaImplantow.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tworzenieListy(ListaImplantow *lista){
    lista -> elementPierwszy = NULL;
}

void dodawanieImplantu(ListaImplantow *lista, Implant implant){
    ElementListy *nowy = malloc(sizeof(ElementListy));
    if(!nowy){
        printf("Blad rezerwacji miejsca w pamieci\n");
        return;
    }
    nowy -> implant = implant;
    nowy -> kolejny = lista -> elementPierwszy;
    lista -> elementPierwszy = nowy;
}

void wyswietlanieListy(const ListaImplantow *lista){
    ElementListy *aktualny = lista -> elementPierwszy;
    if(!aktualny){
        printf("Nie dodano zadnego implantu\n");
        return;
    }

    while(aktualny){
        printf("Nazwa: %s, ", aktualny -> implant.nazwaImplantu);
        printf("Producent: %s, ", aktualny -> implant.producent);
        printf("Poziom ryzyka: %d, ", aktualny -> implant.poziomRyzyka);
        printf("Zapotrzebowanie energii: %.2f, ", aktualny -> implant.zapotrzebowanieEnergii);
        printf("Status legalnosci: %s, ", zamianaNaTekst(aktualny-> implant.legalnoscImplantu));
        printf("ID: %s \n\n", aktualny-> implant.idWlasciciela);

        aktualny = aktualny -> kolejny;
    }
}

void zwolnienieListy(ListaImplantow *lista){
    while(lista -> elementPierwszy){
        ElementListy *tymczasowy = lista -> elementPierwszy;
        lista -> elementPierwszy = tymczasowy -> kolejny;
        free(tymczasowy);
    }
}

int edycjaImplantu(ListaImplantow *lista, const char *nazwa, const char *id){
    ElementListy *aktualny = lista -> elementPierwszy;

    while(aktualny){
        if(strcmp(aktualny -> implant.nazwaImplantu, nazwa) == 0 && strcmp(aktualny -> implant.idWlasciciela, id) == 0){
            printf("Edycja nazwy implantu oraz id wlasciciela nie jest mozliwa.\n");
            printf("Wprowadz nowe dane: \n");

            printf("Producent: \n");
            while(getchar() != '\n');
            fgets(aktualny -> implant.producent, MAX_DL_PROD, stdin);

            printf("Poziom ryzyka(0-10): \n");
            while(scanf("%d", &aktualny -> implant.poziomRyzyka) !=1 ||  aktualny -> implant.poziomRyzyka < 0 ||  aktualny -> implant.poziomRyzyka > 10){
                printf("Wprowadzono bledna wartosc, wprowac liczcby z zakresu 1-10: \n");
                while(getchar() != '\n'); 
            }

            printf("Zapotrzebowanie energii: \n");
            while(scanf("%f", &aktualny -> implant.zapotrzebowanieEnergii) != 1){
                printf("Wprowadzono bledna wartosc, podaj liczbe: \n");
                while(getchar() != '\n');
            }
        
            int stat;
            do{
                printf("Status implantu: (1-LEGALNY, 2-SZARA STREFA, 3-NIELEGALNY): \n");
                scanf("%d", &stat);
                while(getchar() != '\n');
            }while(stat < 1 || stat > 3);

            aktualny -> implant.legalnoscImplantu = (StatusLegalnosci)stat;
            return 1;  
        }
        aktualny = aktualny -> kolejny;
    }
    printf("Brak implantow do edycji.\n");
    return 0;
}

int usuwanieImplantu(ListaImplantow *lista, const char *nazwa, const char *id){
    ElementListy *aktualny = lista -> elementPierwszy;
    ElementListy *poprzedni = NULL;

    while(aktualny){
         if(strcmp(aktualny -> implant.nazwaImplantu, nazwa) == 0 && strcmp(aktualny -> implant.idWlasciciela, id) == 0){
            if(aktualny -> implant.legalnoscImplantu == NIELEGALNY){
                printf("Implant jest nielegalny i nie mozna go usunac.\n");
                return 0;
            }
            if(poprzedni){
                poprzedni -> kolejny = aktualny -> kolejny;
            }
            else{
                 lista -> elementPierwszy = aktualny -> kolejny;
            }
            free(aktualny);
            printf("Usunieto implant.\n");
            return 1;
        }
        poprzedni = aktualny;
        aktualny = aktualny -> kolejny;
    }
    printf("Brak Implantow o podanej nazwie i ID.\n");
    return 0;
}

void wyszukaniePoNazwie(const ListaImplantow *lista, const char *nazwa){

    ElementListy *aktualny = lista -> elementPierwszy;
    int znaleziony = 0;

    while(aktualny){
        if(strcmp(aktualny -> implant.nazwaImplantu, nazwa) == 0 ){
        printf("Wyszukany implant:\n");
        printf("Nazwa: %s, ", aktualny -> implant.nazwaImplantu);
        printf("ID: %s, ", aktualny-> implant.idWlasciciela);
        printf("Producent: %s, ", aktualny -> implant.producent);
        printf("Poziom ryzyka: %d, ", aktualny -> implant.poziomRyzyka);
        printf("Zapotrzebowanie energii: %.2f, ", aktualny -> implant.zapotrzebowanieEnergii);
        printf("Status legalnosci: %s\n\n", zamianaNaTekst(aktualny-> implant.legalnoscImplantu));
        znaleziony = 1;
        }
        aktualny = aktualny -> kolejny;
    }
    if(!znaleziony){
        printf("Brak implantow o podanej nazwie.\n");
    }
}

void wyszukaniePoProducencie(const ListaImplantow *lista, const char *szukanyProducent){
    ElementListy *aktualny = lista -> elementPierwszy;
    int znaleziony = 0;

    while(aktualny){
        if(strcmp(aktualny -> implant.producent, szukanyProducent) == 0 ){
        printf("Nazwa: %s, ", aktualny -> implant.nazwaImplantu);
        printf("ID: %s, ", aktualny-> implant.idWlasciciela);
        printf("Producent: %s, ", aktualny -> implant.producent);
        printf("Poziom ryzyka: %d, ", aktualny -> implant.poziomRyzyka);
        printf("Zapotrzebowanie energii: %.2f, ", aktualny -> implant.zapotrzebowanieEnergii);
        printf("Status legalnosci: %s\n\n", zamianaNaTekst(aktualny-> implant.legalnoscImplantu));
        
        znaleziony = 1;
        }
        aktualny = aktualny -> kolejny;
    }
    if(!znaleziony){
        printf("Brak implantow danego producenta.\n");
    }
}

void wyszukaniePoRyzyku(const ListaImplantow *lista, int poziomRyzyka){

    ElementListy *aktualny = lista -> elementPierwszy;
    int znaleziony = 0;
        while(aktualny){
        if(aktualny -> implant.poziomRyzyka == poziomRyzyka){
        printf("Nazwa: %s, ", aktualny -> implant.nazwaImplantu);
        printf("ID: %s, ", aktualny-> implant.idWlasciciela);
        printf("Producent: %s, ", aktualny -> implant.producent);
        printf("Poziom ryzyka: %d, ", aktualny -> implant.poziomRyzyka);
        printf("Zapotrzebowanie energii: %.2f, ", aktualny -> implant.zapotrzebowanieEnergii);
        printf("Status legalnosci: %s\n\n", zamianaNaTekst(aktualny-> implant.legalnoscImplantu));

        znaleziony = 1;
        }
        aktualny = aktualny -> kolejny;
    }
    if(!znaleziony){
    printf("Brak implantow o wpisanym poziomie ryzyka.\n");
    }
}

void sortowaniePoNazwie(ListaImplantow *lista){
    if(!lista ->elementPierwszy){
        return;
    }
    int przestawienie;
    ElementListy *a;
    ElementListy *b;
    Implant tymczasowy;
    
    do{
        przestawienie = 0;
        a = lista ->elementPierwszy;

        while(a -> kolejny){
            b = a -> kolejny;
            if(strcmp(a -> implant.nazwaImplantu, b -> implant.nazwaImplantu) > 0){
                tymczasowy = a -> implant;
                a -> implant = b -> implant;
                b -> implant = tymczasowy;
                przestawienie = 1;
            }
            a = a -> kolejny;
        }
    }while(przestawienie);
    printf("Posortowano liste alfabretycznie po nazwie.\n");
}

void sortowaniePoId(ListaImplantow *lista){
        if(!lista ->elementPierwszy){
        return;
    }
    int przestawienie;
    ElementListy *a;
    Implant tymczasowy;
    
    do{
        przestawienie = 0;
        a = lista ->elementPierwszy;

        while(a -> kolejny){

            if(strcmp(a -> implant.idWlasciciela, a -> kolejny -> implant.idWlasciciela) > 0){
                tymczasowy = a -> implant;
                a -> implant = a -> kolejny -> implant;
                a -> kolejny -> implant = tymczasowy;
                przestawienie = 1;
            }
            a = a -> kolejny;
        }
    }while(przestawienie);
    printf("Posortowano liste po ID.\n");
}

void sortowaniePoRyzyku(ListaImplantow *lista){
    if(!lista ->elementPierwszy){
    return;
    }
    int przestawienie;
    ElementListy *a;
    Implant tymczasowy;
    
    do{
        przestawienie = 0;
        a = lista ->elementPierwszy;

        while(a -> kolejny){

            if(a -> implant.poziomRyzyka > a -> kolejny -> implant.poziomRyzyka){
                tymczasowy = a -> implant;
                a -> implant = a -> kolejny -> implant;
                a -> kolejny -> implant = tymczasowy;
                przestawienie = 1;
            }
            a = a -> kolejny;
        }
    }while(przestawienie);
    printf("Posortowano liste po poziomie ryzyka.\n");
}

const char *zamianaNaTekst(StatusLegalnosci status){
    switch(status){
        case LEGALNY: return "LEGALNY";
        case SZARA_STREFA: return "SZARA_STREFA";
        case NIELEGALNY: return "NIELEGALNY";
        default: return "NIEZNANY";
    }
}