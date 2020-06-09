//
// Created by TheRolf on 09/06/2020.
//

#ifndef LO41_PROJET_LISTEATTENTEAVION_H
#define LO41_PROJET_LISTEATTENTEAVION_H

#include "../avion/avion.h"
#include "../constantes.h"

bool listeAttenteAvion(avion *grandeListe[NB_AVIONS], avion *petiteListe[NB_AVIONS], avion *misAJour) {
    int i = 0;
    while(grandeListe[i] != NULL) {
        if(grandeListe[i] == misAJour)
            return true;

        ++i;
    }

    i = 0;
    while(petiteListe[i] != NULL) {
        if(petiteListe[i] == misAJour)
            return false;

        ++i;
    }

    return false;
}

#endif //LO41_PROJET_LISTEATTENTEAVION_H
