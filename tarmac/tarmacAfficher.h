//
// Created by TheRolf on 31/05/2020.
//

#ifndef LO41_PROJET_TARMACAFFICHER_H
#define LO41_PROJET_TARMACAFFICHER_H

#include "tarmac_struct.h"
#include "../affichage/affichage_fonction.h"
#include "../affichage/colonne/colonne_fonction.h"

void tarmacAfficher(tarmac *t) {
    if(t == NULL)
        return;

    // on affiche le titre
    affichagePrintf(&t->affichageTitre, t->titre);

    // on affiche le contenu du tarmac
    colonneLigneUpdate(&t->colonnesAvions[0]);
}

#endif //LO41_PROJET_TARMACAFFICHER_H
