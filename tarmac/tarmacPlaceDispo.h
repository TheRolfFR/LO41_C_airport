//
// Created by TheRolf on 09/06/2020.
//

#ifndef LO41_PROJET_TARMACPLACEDISPO_H
#define LO41_PROJET_TARMACPLACEDISPO_H

#include <stdbool.h>
#include "../constantes.h"
#include "../avion/avion.h"

bool tarmacPlaceDispo(avion *grandeListe[NB_AVIONS], avion *petiteListe[NB_AVIONS], int posg, int posp, bool estArrivant) {
    if(!estArrivant) // si tu pars oui il y aura de la place sur le tarmac
        return true;

    int places = TARMAC_NB_AVIONS;

    int i = 0, j = 0;

    while ((grandeListe[i] != NULL || petiteListe[j] != NULL) && places >= 0) {
        // il faut avancer en parallèle

        if(grandeListe[i] != NULL) {
            places += (grandeListe[i]->estArrivant) ? -1 : +1;
            ++i;
        }

        if(petiteListe[j] != NULL) {
            places += (petiteListe[j]->estArrivant) ? -1 : +1;
            ++j;
        }
    }

    return places > 0;
}

#endif //LO41_PROJET_TARMACPLACEDISPO_H
