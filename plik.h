#ifndef PLIK_TXT_H
#define PLIK_TXT_H

#include "listaImplantow.h"

void zapisanieDoPliku(const ListaImplantow *lista, const char *nazwaPliku);
void wczytanieDoPliku(ListaImplantow *lista, const char *nazwaPliku);

#endif