//
// Created by TheRolf on 31/05/2020.
//

#include "liste_attente_struct.h"
#include "../constantes.h"

#ifndef LO41_PROJET_LISTEATTENTECREER_H
#define LO41_PROJET_LISTEATTENTECREER_H

/// creer de faire une liste chainée basée sur un tableau
/// on fait notre liste de façon totolement inverse. On crée un tableau puis on relie
/// le tout comme une liste
/// \param liste_attente le tableau a traiter
void listeAttenteCreer(avion *liste[NB_AVIONS]) {
    for(int i = 0; i < NB_AVIONS; ++i) {
        liste[i] = NULL;
    }
}

#endif //LO41_PROJET_LISTEATTENTECREER_H
