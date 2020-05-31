//
// Created by TheRolf on 15/05/2020.
//

#ifndef LO41_PROJET_AVION_H
#define LO41_PROJET_AVION_H

#define AVION_TAILLE_NUM_VOL 6

#include <stdbool.h>
#include <time.h>

typedef struct struct_avion {
    char numeroVol[AVION_TAILLE_NUM_VOL];
    int numero;
    char *lieu;
    bool estArrivant;
    int fuel;
    bool grosAvion;
    bool atterissageUrgent;
    struct tm *date;
} avion;

#endif //LO41_PROJET_AVION_H
