//
// Created by TheRolf on 09/06/2020.
//


#ifndef LO41_PROJET_AVIONCOMPARER_H
#define LO41_PROJET_AVIONCOMPARER_H

#include "avion.h"
#include "../constantes.h"

int avionComparer(avion* a1, avion* a2) {
    // on compare s'ils sont NULL

    if(a1 == NULL && a2 == NULL)
        return -1;
    else if(a1 == NULL)
        return 1;
    else if(a2 == NULL)
        return -1;
    else if(a1 == a2)
        return 0;

    int resultat;

    // si ce sont deux atterissage d'urgence
    resultat = a1->atterissageUrgent * -1 + a2->atterissageUrgent * 1;
    if(resultat != 0)
        return resultat;

    // sinon il faut trouver un autre critère, le fuel en urgence ?
    resultat = (a1->fuel <= MISE_EN_ATTENTE_FUEL) * -1 + (a2->fuel <= MISE_EN_ATTENTE_FUEL) * 1;
    if(resultat != 0)
        return resultat;

    // en dernier, la date le plus tot ?
    resultat = (a1->temps < a2->temps) * -1 + (a1->temps > a2->temps);

    return resultat;
}

#endif //LO41_PROJET_AVIONCOMPARER_H
