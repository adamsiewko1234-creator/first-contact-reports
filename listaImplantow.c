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
        printf("Status legalnosci: %d, ", aktualny-> implant.legalnoscImplantu);
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
            fgets(aktualny -> implant.producent, MAX_DL_PROD, stdin);

            printf("Poziom ryzyka(1-10): \n");
            while(scanf("%d", &aktualny -> implant.poziomRyzyka) !=1 ||  aktualny -> implant.poziomRyzyka < 1 ||  aktualny -> implant.poziomRyzyka > 10){
                printf("Wprowadzono bledna wartosc, wprowac liczcby z zakresu 1-10:");
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
    printf("Brak Implantow.\n");
    return 0;
}