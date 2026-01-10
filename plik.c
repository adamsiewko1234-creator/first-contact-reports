#include "plik.h"
#include <stdio.h>

void zapisanieDoPliku(const ListaImplantow *lista, const char *plikImplanty){
    FILE *plik = fopen(plikImplanty.txt, "w");
    if(!plik){
        return
    }

    ElementListy *element = lista -> elementPierwszy;
    while(element){
        fprintf(plik, "%s; %s; %s; %d; %.2f; %d\n", 
        element -> implant.nazwaImplantu,
        element -> implant.producent,
        element -> implant.poziomRyzyka,
        element -> implant.zapotrzebowanieEnergii,
        element -> implant.legalnoscImplantu,
        element -> implant.idWlasciciela,
        );
        element = element -> kolejny;
    }
    fclose(plik);

}