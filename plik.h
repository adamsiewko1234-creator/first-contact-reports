#ifndef PLIK_TXT_H
#define PLIK_TXT_H

#include "listaImplantow.h"

void zapisanieDoPliku(const ListaImplantow *lista, const char *plikImplanty);
void wczytanieZPliku(ListaImplantow *lista, const char *plikImplanty);

#endif