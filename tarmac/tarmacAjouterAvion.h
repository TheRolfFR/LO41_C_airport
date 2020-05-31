//
// Created by TheRolf on 31/05/2020.
//

#include <stdlib.h>
#include "tarmac_struct.h"
#include "../affichage/colonne/colonne_fonction.h"

#ifndef LO41_PROJET_TARMACAJOUTERAVION_H
#define LO41_PROJET_TARMACAJOUTERAVION_H

/// fonction qui rajoute un avions au tarmac si possible
/// \param t tarmac concerné
/// \param a avions a ajouter
/// \return -1 si pas de place ou erreur, position de l'avions dans le tarmac sinon sinon
int tarmacAjouterAvion(tarmac *t, avion *a) {
    if(t == NULL || a == NULL)
        return EXIT_FAILURE;

    int position = -1;
    int i = 0;

    while(i < TARMAC_NB_AVIONS && position == -1) {
        if(t->avionsPresents[i] == NULL)
            position = i;

        ++i;
    }

    // on a pas trouvé de place
    if(i == TARMAC_NB_AVIONS)
        return EXIT_FAILURE;

    // sinon on affecte l'avions
    t->avionsPresents[position] = a;

    // on met a jour le numéro de l'avions dans le tarmac
    colonneChangeContenu(&t->colonnesAvions[position], a->numeroVol);
    colonneUpdate(&t->colonnesAvions[position]);

    // on retourne la position de l'avions dans le tarmac
    return position;
}

#endif //LO41_PROJET_TARMACAJOUTERAVION_H
