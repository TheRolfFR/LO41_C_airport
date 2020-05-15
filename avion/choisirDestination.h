//
// Created by TheRolf on 15/05/2020.
//

#ifndef LO41_PROJET_CHOISIRDESTINATION_H
#define LO41_PROJET_CHOISIRDESTINATION_H

#include "avion.h"
#include "../utilitaires/aleatoire.h"
#include "../constantes.h"

void choisirDestination(avion* a) {
    // on détermine de manière aléatoire son lieu
    if(aleatoireFloatRange(0, 1, 3) <= PROBA_DESTINATION_INTER) {
        a->lieu = destinations_inter[aleatoireEntierMaxExclu(NB_DESTINATIONS_INTER)];
    } else {
        a->lieu = destionations_fr[aleatoireEntierMaxExclu(NB_DESTINATIONS_FRANCE)];
    }
}

#endif //LO41_PROJET_CHOISIRDESTINATION_H
