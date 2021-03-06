//
// Created by TheRolf on 15/05/2020.
//

#ifndef LO41_PROJET_AVIONAFFICHER_H
#define LO41_PROJET_AVIONAFFICHER_H

#include <stdio.h>
#include "avion.h"
#include "../utilitaires/date.h"

void avionAfficher(avion* a) {
    // départ ou arrivée
    if(a->estArrivant) {
        printf("%7s", "ARRIVEE");
    } else {
        printf("%7s", "DEPART");
    }

    // lieu
    printf(" %16s", a->lieu);

    // fuel
    printf(" Fuel:%3d", a->fuel);

    // gros avions
    printf(" G:%d", a->grosAvion);

    // atterissage urgent
    printf(" AF:%d\n", a->atterissageUrgent);

    // date
    afficherDate(a->date);printf("\n");
}

#endif //LO41_PROJET_AVIONAFFICHER_H
