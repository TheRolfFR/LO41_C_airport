//
// Created by TheRolf on 31/05/2020.
//

#ifndef LO41_PROJET_AVIONCHANGERDIRECTION_H
#define LO41_PROJET_AVIONCHANGERDIRECTION_H

#include <stdbool.h>
#include "avionChoisirDestination.h"
#include "../utilitaires/date.h"

// fonction permettant de changer de direction : atterrissage->décollage mais aussi décollage->atterrissage
void avionChangerDirection(avion *a) {
    if(a == NULL)
        return;

    // on le change de destination
    avionChoisirDestination(a);

    // si on passe de atterrissage a décollage
    if(a->estArrivant) {
        a->atterissageUrgent = false;
    } else {
        // sinon il nous faut dire si oui ou non c'est un atterissage force
        avionAtterissageForce(a);
    }

    // il nous faut aussi changer la datte
    mettreDate(a);

    a->estArrivant = !a->estArrivant; // on inverse entre atterrissage et décollage
}

#endif //LO41_PROJET_AVIONCHANGERDIRECTION_H
