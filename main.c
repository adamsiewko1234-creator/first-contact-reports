#include <stdio.h>
#include "listaImplantow.h"
#include "implant.h"

int main(void){

    ListaImplantow lista;
    tworzenieListy(&lista);
   
    Implant x = {
        "reka", "21A", "Protezy50", 5, 20.0f, LEGALNY
    };

    dodawanieImplantu(&lista, x);
    wyswietlanieListy(&lista);

    zwolnienieListy(&lista);

    return 0;
}

