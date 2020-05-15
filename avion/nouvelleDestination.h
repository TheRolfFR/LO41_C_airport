//
// Created by TheRolf on 15/05/2020.
//

#ifndef LO41_PROJET_NOUVELLEDESTINATION_H
#define LO41_PROJET_NOUVELLEDESTINATION_H

#include <stdbool.h>
#include "avion.h"
#include "choisirDestination.h"

void nouvelleDestination(avion* a) {
    // on enlève les marques arrivant et atterissage arrivant
    a->estArrivant = false;
    a->atterissageUrgent = false;

    choisirDestination(a);
}

#endif //LO41_PROJET_NOUVELLEDESTINATION_H
