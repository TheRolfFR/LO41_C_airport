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
void listeAttenteCreer(liste_attente_struct liste_attente[NB_AVIONS]) {
    for(int i = 0; i < NB_AVIONS; ++i) {
        // si ce n'est le premier, on lie le précédent
        if(i > 0)
            liste_attente[i].precedent = &liste_attente[i-1];

        // si ce n'est pas le dernier, on lie le suivant
        if( i < NB_AVIONS - 1)
            liste_attente[i].suivant = &liste_attente[i+1];
    }
}

#endif //LO41_PROJET_LISTEATTENTECREER_H
