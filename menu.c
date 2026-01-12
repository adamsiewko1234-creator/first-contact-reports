#include "menu.h"
#include "listaImplantow.h" 
#include "plik.h"
#include "implant.h"
#include <stdio.h>
#include <string.h>

void uruchamianieMenu(const char *nazwaPliku){
    ListaImplantow lista;
    tworzenieListy(&lista);

    int wybor;
    do{
        printf("Menu Rejestru Ulepszen Cybernetycznych Obywateli: \n\n");
        printf("1. Dodaj nowy implant\n");
        printf("2. Wyswietl liste implantow\n");
        printf("3. Szukaj implantow po nazwie\n");
        printf("4. Szukaj implantow po producencie\n");
        printf("5. Szukaj implantow po poziomie ryzyka\n");
        printf("6. Sortuj liste po nazwie implantu\n");
        printf("7. Sortuj liste po ID wlasciciela implantu\n");
        printf("8. Sortuj liste po poziomie ryzyka implantu\n");
        printf("9. Edytuj implant\n");
        printf("10. Usun implant\n");
        printf("11. Wczytaj z pliku tekstowego\n");
        printf("12. Zapisz do pliku tekstowego\n");
        printf("0. Zakoncz dzialanie programu\n");
        if(scanf("%d", &wybor) != 1){
            printf("Niepoprawny wybor operacji.\n");
            while(getchar() != '\n');
            continue;
        }

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

                do{
                printf("Poziom ryzyka (0-10): ");
                scanf("%d", &x.poziomRyzyka);
                while(getchar() != '\n');
                }while(x.poziomRyzyka < 0 || x.poziomRyzyka > 10);
                
                printf("Zapotrzebowanie energii: ");
                while(scanf("%f", &x.zapotrzebowanieEnergii) != 1){
                    printf("Wprowadz poprawne dane.\n");
                    while(getchar() != '\n');
                }
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
                 
            case 3:{
                char nazwa[MAX_DL_NAZWY];
                printf("Podaj nazwe implantu: \n");
                fgets(nazwa, MAX_DL_NAZWY, stdin);
                nazwa[strcspn(nazwa, "\n")] = '\0';
                wyszukaniePoNazwie(&lista, nazwa);
                break;
            }

            case 4:{
                char producent[MAX_DL_PROD];
                printf("Podaj producenta implantu: \n");
                fgets(producent, MAX_DL_PROD, stdin);
                producent[strcspn(producent, "\n")] = '\0';
                wyszukaniePoProducencie(&lista, producent);
                break;
            }
            
            case 5:{
                int poziomRyzyka;
                printf("Podaj poziom ryzyka (0-10): ");
                while(scanf("%d", &poziomRyzyka) != 1 || poziomRyzyka < 0 || poziomRyzyka > 10){
                    printf("Blednie wprowadzono wartosc.\n");
                    while(getchar() != '\n');
                }
                wyszukaniePoRyzyku(&lista, poziomRyzyka);
                break;
            }

            case 6:
                sortowaniePoNazwie(&lista);
                break;

            case 7:
                sortowaniePoId(&lista);
                break;

            case 8: 
                sortowaniePoRyzyku(&lista);
                break;

            case 9:{
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
            }

            case 10:{
                char t[MAX_DL_NAZWY];
                char id[MAX_DL_ID];

                printf("Nazwa implantu: ");
                fgets(t, MAX_DL_NAZWY, stdin);
                t[strcspn(t, "\n")] = '\0';
                printf("ID wlasciciela: ");
                fgets(id, MAX_DL_ID, stdin);
                id[strcspn(id, "\n")] = '\0';

                usuwanieImplantu(&lista, t, id);
                break;
            }

            case 11:
                wczytanieZPliku(&lista, nazwaPliku);
                break;
            
            case 12:
                zapisanieDoPliku(&lista, nazwaPliku);
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