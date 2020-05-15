//
// Created by TheRolf on 15/05/2020.
//

#ifndef LO41_PROJET_AVION_H
#define LO41_PROJET_AVION_H

#include <stdbool.h>

typedef struct struct_avion {
    char *lieu;
    bool estArrivant;
    int fuel;
    bool grosAvion;
    bool atterissageUrgent;
} avion;

#endif //LO41_PROJET_AVION_H
