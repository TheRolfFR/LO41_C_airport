//
// Created by TheRolf on 09/06/2020.
//

#ifndef LO41_PROJET_AVIONDANSLISTE_H
#define LO41_PROJET_AVIONDANSLISTE_H

#include "avion.h"
#include "../constantes.h"

bool avionDansListe(avion* a, avion* tab[NB_AVIONS]) {
    int i = 0;
    while(i < NB_AVIONS && tab[i] != a)
        ++i;

    return i != NB_AVIONS;
}

#endif //LO41_PROJET_AVIONDANSLISTE_H
