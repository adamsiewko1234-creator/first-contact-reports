#include "plik.h"
#include <stdio.h>

void zapisanieDoPliku(const ListaImplantow *lista, const char *nazwaPliku){
    FILE *plik = fopen(nazwaPliku, "w");
    if(!plik){
        printf("Przy zapisywaniu do pliku: %s wystapil blad.\n", nazwaPliku);
        return;
    }

    ElementListy *element = lista -> elementPierwszy;
    while(element){
        fprintf(plik, "%s; %s; %s; %d; %.2f; %d\n", 
        element -> implant.nazwaImplantu,
        element -> implant.idWlasciciela,
        element -> implant.producent,
        element -> implant.poziomRyzyka,
        element -> implant.zapotrzebowanieEnergii,
        element -> implant.legalnoscImplantu
        );
        element = element -> kolejny;
    }
    fclose(plik);
    printf("Pomyslnie zapisano dane do pliku: %s.\n", nazwaPliku);
}

void wczytanieZPliku(ListaImplantow *lista, const char *nazwaPliku){
    FILE *plik = fopen(nazwaPliku, "r");
    if(!plik){
        printf("Wystapil blad przy odczycie danych z pliku: %s.\n", nazwaPliku);
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
    printf("Pomyslnie wczytano dane z pliku: %s.\n", nazwaPliku);
}