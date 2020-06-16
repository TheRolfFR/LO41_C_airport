//
// Created by TheRolf on 16/06/2020.
//

#ifndef LO41_PROJET_LISTERESSERRER_H
#define LO41_PROJET_LISTERESSERRER_H

#include "../avion/avion.h"
#include "../constantes.h"

void listeAttenteResserer(avion* liste[NB_AVIONS]) {
    int opti = 0;
    int i = opti;

    // pour toute la liste
    while(opti < NB_AVIONS) {
        // si on est nul
        if(liste[opti] == NULL) {
            // on cherche le non nul le plus proche
            while(i < NB_AVIONS && liste[i] == NULL)
                ++i;

            // on a trouve un non nul
            if(i < NB_AVIONS) {
                liste[opti] = liste[i];
                liste[i] = NULL;
            } else {
                // fin de la liste, au revoir
                return;
            }
        }

        // on augmente opti
        ++opti;
        i = opti;
    }
}

#endif //LO41_PROJET_LISTERESSERRER_H
