//
// Created by TheRolf on 15/05/2020.
//

#ifndef LO41_PROJET_AFICHERAVION_H
#define LO41_PROJET_AFICHERAVION_H

#include <stdio.h>
#include "avion.h"

void afficherAvion(avion* a) {
    // départ ou arrivée
    if(a->estArrivant) {
        printf("%7s", "ARRIVEE");
    } else {
        printf("%7s", "DEPART");
    }

    // lieu
    printf(" %20s", a->lieu);

    // fuel
    printf(" %3d", a->fuel);

    // atterissage urgent
    printf(" %d\n", a->atterissageUrgent);
}

#endif //LO41_PROJET_AFICHERAVION_H
