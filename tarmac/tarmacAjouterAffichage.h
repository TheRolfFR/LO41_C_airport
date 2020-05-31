//
// Created by TheRolf on 31/05/2020.
//

#include "tarmac_struct.h"
#include "../affichage/affichage_fonction.h"

#ifndef LO41_PROJET_TARMACAJOUTERAFFICHAGE_H
#define LO41_PROJET_TARMACAJOUTERAFFICHAGE_H

int tarmacAjouterAffichage(affichage_struct **liste, tarmac *t) {
    // on ajoute le titre
    affichageAjouter(liste, &t->affichageTitre);

    // on ajoute ensuite l'affichage colonne du tarmac
    affichageAjouter(liste, &t->affichage);
}

#endif //LO41_PROJET_TARMACAJOUTERAFFICHAGE_H
