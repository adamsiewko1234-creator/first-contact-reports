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

#endif