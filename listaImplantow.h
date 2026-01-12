#ifndef LISTA_IMPLANTOW_H
#define LISTA_IMPLANTOW_H

#include "implant.h"

typedef struct ElementListy{
    Implant implant;
    struct ElementListy *kolejny;
}ElementListy;

typedef struct{
    ElementListy *elementPierwszy;
}ListaImplantow;

void tworzenieListy(ListaImplantow *lista);
void dodawanieImplantu(ListaImplantow *lista, Implant implant);
void wyswietlanieListy(const ListaImplantow *lista);
void zwolnienieListy(ListaImplantow *lista);
int edycjaImplantu(ListaImplantow *lista, const char *nazwa, const char *id);
int usuwanieImplantu(ListaImplantow *lista, const char *nazwa, const char *id);
void wyszukaniePoProducencie(const ListaImplantow *lista, const char *szukanyProducent);
void wyszukaniePoRyzyku(const ListaImplantow *lista, int poziomRyzyka);

#endif