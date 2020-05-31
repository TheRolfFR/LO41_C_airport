//
// Created by TheRolf on 15/05/2020.
//

#ifndef LO41_PROJET_CHOISIRDESTINATION_H
#define LO41_PROJET_CHOISIRDESTINATION_H

#include "avion.h"
#include "../utilitaires/aleatoire.h"
#include "../constantes.h"
#include <ctype.h>

void choisirDestination(avion* a) {
    // on détermine de manière aléatoire son lieu
    if(aleatoireFloatRange(0, 1, 3) <= PROBA_DESTINATION_INTER) {
        a->lieu = destinations_inter[aleatoireEntierMaxExclu(NB_DESTINATIONS_INTER)];
    } else {
        a->lieu = destionations_fr[aleatoireEntierMaxExclu(NB_DESTINATIONS_FRANCE)];
    }

    // on change le numéro de vol
    snprintf(a->numeroVol, AVION_TAILLE_NUM_VOL, "%d%c%c", rand()%1000, toupper(a->lieu[0]), toupper(a->lieu[1]));
}

#endif //LO41_PROJET_CHOISIRDESTINATION_H
