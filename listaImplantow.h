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
void edycjaImplantu(ListaImplantow *lista, const char *nazwa, const char *id);
void usuwanieImplantu(ListaImplantow *lista, const char *nazwa, const char *id);

#endif