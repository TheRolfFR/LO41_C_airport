//
// Created by TheRolf on 15/06/2020.
//

#ifndef LO41_PROJET_AVIONPISTE_H
#define LO41_PROJET_AVIONPISTE_H

#include "avion.h"
#include "../arguments/argument_thread_avion.h"

#define NO_RESULT true

int avionPiste(avion* a, argument_thread_avion* arg) {
    // c'est un gros avion il est forcément dans la grande piste
    if(a->grosAvion)
        return 0;

    // on regarde s'il est sur la petite piste
    bool noResult = NO_RESULT;
    int i = 0;
    while(i < NB_AVIONS && noResult) {
        if(a == arg->argumentsThread->mesPistes[1].avionEnCours)
            noResult = false;
        ++i;
    }

    // s'il est sur la petite piste
    if(!noResult)
        return 1;

    // sinon sur la grande
    return 0;
}

#endif //LO41_PROJET_AVIONPISTE_H
