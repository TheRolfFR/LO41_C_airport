//
// Created by TheRolf on 31/05/2020.
//

#ifndef LO41_PROJET_PISTEOCUPEE_H
#define LO41_PROJET_PISTEOCUPEE_H

#include "piste.h"

bool pisteEstOccupee(piste *p) {
    return p->avionEnCours != NULL;
}

#endif //LO41_PROJET_PISTEOCUPEE_H
