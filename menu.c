#include "menu.h"
#include "listaImplantow.h" 
#include "plik.h"
#include "implant.h"
#include <stdio.h>

void uruchamianieMenu(const char *nazwaPliku){
    ListaImplantow lista;
    tworzenieListy(&lista);

    int wybor;
    do{
        printf("Menu Rejestru Ulepszen Cybernetycznych Obywateli: \n\n");
        printf("1. Dodaj nowy implant\n");
        printf("2. Wyswietl liste implantow\n");
        printf("3. Szukaj implantu\n");
        printf("4. Edytuj implant\n");
        printf("5. Usun implant\n");
        printf("6. Zapisz do pliku\n");
        printf("7. Wczytaj z pliku\n");
        printf("0. Zakoncz dzialanie programu\n");
        scanf("%d", &wybor);
        while(getchar() != '\n');

        switch(wybor){
            case 1:

                Implant x;
                printf("Nazwa: "); 
                fgets(x.nazwaImplantu, MAX_DL_NAZWY, stdin);
                x.nazwaImplantu[strcspn(x.nazwaImplantu, "\n")] = '\0';
                printf("ID: ");
                fgets(x.idWlasciciela, MAX_DL_ID, stdin);
                x.idWlasciciela[strcspn(x.idWlasciciela, "\n")] = '\0';
                printf("Producent: ");
                fgets(x.producent, 100, stdin);
                x.producent[strcspn(x.producent, "\n")] = '\0';
                printf("Poziom ryzyka (0-10): ");
                scanf("%d", &x.poziomRyzyka);
                while(getchar() != '\n');
                printf("Ilosc energii: ");
                scanf("%f", &x.zapotrzebowanieEnergii);
                while(getchar() != '\n');
                int stat;
                do{
                    printf("Status legalnosci: (1-LEGALNY, 2-SZARA STREFA, 3-NIELEGALNY): \n");
                    scanf("%d", &stat);
                    while(getchar() != '\n');
                }while(stat < 1 || stat > 3);
                x.legalnoscImplantu = (StatusLegalnosci)stat;
                
                dodawanieImplantu(&lista, x);
                break;

            case 2:
                wyswietlanieListy(&lista);
                break;

            case 3:
                char t[MAX_DL_NAZWY];
                char id[MAX_DL_ID];

                printf("Nazwa implantu: ");
                fgets(t, MAX_DL_NAZWY, stdin);
                t[strcspn(t, "\n")] = '\0';
                printf("ID wlasciciela: ");
                fgets(id, MAX_DL_ID, stdin);
                id[strcspn(id, "\n")] = '\0';

                edycjaImplantu(&lista, t, id);
                break;

            case 4:
                zapisanieDoPliku(&lista, nazwaPliku);
                printf("Zapisano do pliku tekstowego.\n");
                break;

            case 5:
                wczytanieZPliku(&lista, nazwaPliku);
                printf("Wczytano z pliku tekstowego.\n");
                break;

            case 6:

                printf("Nazwa implantu: ");
                fgets(t, MAX_DL_NAZWY, stdin);
                t[strcspn(t, "\n")] = '\0';
                printf("ID wlasciciela: ");
                fgets(id, MAX_DL_ID, stdin);
                id[strcspn(id, "\n")] = '\0';

                usuwanieImplantu(&lista, t, id);
                break;

            case 0:
                printf("Wylaczanie programu.\n");
                break;

            default:
                printf("Nieprawidlowa operacja\n");
        }
    }while(wybor != 0);
    
    zwolnienieListy(&lista);
}