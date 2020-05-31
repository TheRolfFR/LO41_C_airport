//
// Created by TheRolf on 31/05/2020.
//

#include <stdlib.h>
#include "tarmac_struct.h"
#include "../affichage/colonne/colonne_fonction.h"

#ifndef LO41_PROJET_TARMACSUPPRIMERAVION_H
#define LO41_PROJET_TARMACSUPPRIMERAVION_H

/// fonction permettant de possiblement supprimer un avion du tarmac
/// \param t tarmac concerné
/// \param a avion a supprimer
void tarmacSupprimerAvion(tarmac *t, avion *a) {
    if(t == NULL || a == NULL)
        return;

    int position = -1;
    int i = 0;
    while(i < TARMAC_NB_AVIONS && position == -1) {
        if(t->avionsPresents[i] == a) // on cherche l'avion
            position = i;

        ++i;
    }

    // on a pas trouvé de place
    if(i == TARMAC_NB_AVIONS)
        return;

    // on le supprime et on met a jour l'interface
    t->avionsPresents[position] = NULL;

    // on met a jour le contenu de la colonne dans le tarmac
    colonneChangeContenu(&t->colonnesAvions[position], TARMAC_VALEUR_DEFAUT);
    colonneUpdate(&t->colonnesAvions[position]);

    return;
}

#endif //LO41_PROJET_TARMACSUPPRIMERAVION_H
