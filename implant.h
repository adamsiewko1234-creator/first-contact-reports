#ifndef IMPLANT_H
#define IMPLANT_H

#define MAX_DL_NAZWY 100
#define MAX_DL_ID 50
#define MAX_DL_PROD 100

typedef enum{
    LEGALNY = 1,
    SZARA_STREFA,
    NIELEGALNY
}StatusLegalnosci;

typedef struct{
    char nazwaImplantu[MAX_DL_NAZWY];
    char idWlasciciela[MAX_DL_ID];
    char producent[MAX_DL_PROD];
    int poziomRyzyka;
    float zapotrzebowanieEnergii;
    StatusLegalnosci legalnoscImplantu;
}Implant;

#endif