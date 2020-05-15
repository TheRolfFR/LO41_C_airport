//
// Created by TheRolf on 15/05/2020.
//

#ifndef LO41_PROJET_METTREENATTENTE_H
#define LO41_PROJET_METTREENATTENTE_H

#include "avion.h"
#include "../constantes.h"

void mettreEnAttente(avion* a) {
    a->fuel -= MISE_EN_ATTENTE_FUEL;
}

#endif //LO41_PROJET_METTREENATTENTE_H
