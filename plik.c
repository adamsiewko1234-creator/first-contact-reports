#include "plik.h"
#include <stdio.h>

void zapisanieDoPliku(const ListaImplantow *lista, const char *plikImplanty){
    FILE *plik = fopen(plikImplanty.txt, "w");
    if(!plik){
        printf("Przy zapisywaniu do pliku wystapil blad.\n");
        return;
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

void wczytanieZPliku(ListaImplantow *lista, const char *plikImplanty){
    FILE *plik = fopen(plikImplanty.txt, "r");
    if(!plik){
        printf("Wystapil blad przy odczycie danych z pliku.\n");
        return;
    }

    zwolnienieListy(lista);
    tworzenieListy(lista);

    Implant tymczasowy;
    int status;

    while(fscanf(plik, "%99[^;];%49[^;];%99[^;];%d;%f;%d\n",
        tymczasowy.nazwaImplantu,
        tymczasowy.idWlasciciela,
        tymczasowy.producent,
        &tymczasowy.poziomRyzyka,
        &tymczasowy.zapotrzebowanieEnergii,
        &status
    ) == 6){
        tymczasowy.legalnoscImplantu = (StatusLegalnosci)status;
        dodawanieImplantu(lista, tymczasowy);
    }
    fclose(plik);
    printf("Pomyslnie wczytano dane z pliku. \n");
}