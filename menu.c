#include "menu.h"
#include "listaImplantow.h" 
#include "plik.h"
#include <stdio.h>

void uruchamianieMenu(cosnt char *nazwaPliku){
    ListaImplantow lista;
    tworzenieListy(&lista);

    int wybor;
    do{
        printf("Menu Rejestru Implantow: \n\n");
        printf("1. Dodaj nowy implant\n");
        printf("2. Wyswietl liste implantow\n");
        printf("3. Szukaj implantu\n");
        printf("4. Edytuj implant\n");
        printf("5. Usun implant\n");
        printf("6. Zapisz do pliku\n");
        printf("0. Zakoncz dzialanie programu\n");
        scanf("%d", &wybor);
        while(getchar() != '\n');

        switch(wybor){
            case 1:

                Implant x;
                printf("Nazwa: "); 
                fgets(x.nazwaImplantu, 100, stdin);
                printf("ID: ");
                fgets(x.idWlasciciela, 50, stdin);
                printf("Producent: ");
                fgets(x.producent, 100, stdin);
                printf("Poziom ryzyka: ");
                scanf("%d", &x.poziomRyzyka);
                printf("Ilosc energii: ");
                sccanf("%f", &x.zapotrzebowanieEnergii);
                printf("Status legalnosci: ");
                scanf("%d", (int*)&x.legalnoscImplantu);
                dodawanieImplantu(&lista, x);
                break;

            case 2:
                wyswietlanieListy(&lista);
                break;

            case 3:
                char t[MAX_DL_NAZWY];
                char id[MAX_DL_ID];

                printf("Nazwa: ");
                fgets(t, MAX_DL_NAZWY, stdin);
                printf("ID: ");
                fgets(id, MAX_DL_ID, stdin);
                edyjaImplantu(&lista, t, id);
                break;

            case 4:
                zapisanieDoPliku(&lista, nazwaPliku);
                printf("Zapisano do pliku tekstowego.\n");
                break;

            case 5:
                wczytanieZPliku(&lista, nazwaPliku);
                printf("Wczytano z pliku tekstowego.\n");
                break;

            default:
                printf("Nieprawidlowa operacja\n");
        }
    }while(wybor != 0);
    
    zwolnienieListy(&lista);
}