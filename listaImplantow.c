#include "listaImplantow.h"
#include <stdio.h>
#include <stdlib.h>

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