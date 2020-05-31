//
// Created by TheRolf on 31/05/2020.
//

#ifndef LO41_PROJET_AVIONATTERISSAGEFORCE_H
#define LO41_PROJET_AVIONATTERISSAGEFORCE_H

#include "avion.h"
#include "../utilitaires/aleatoire.h"
#include "../constantes.h"

// fonction dédiée à l'atterrissage forcé
void avionAtterissageForce(avion *a) {
    if(a == NULL)
        return;

    //atterissage d'urgence
    if(aleatoireFloatRange(0, 1, 3) <= PROBA_ATTERISSAGE_FORCE) { // si la probabilité correspond à celle définie dans constantes.h
        a->atterissageUrgent = true;
    }
}

#endif //LO41_PROJET_AVIONATTERISSAGEFORCE_H
