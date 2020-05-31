//
// Created by TheRolf on 31/05/2020.
//

#include "tarmac_struct.h"
#include "../affichage/affichage_fonction.h"
#include "../affichage/colonne/colonne_fonction.h"

#ifndef LO41_PROJET_TARMACINITIALISER_H
#define LO41_PROJET_TARMACINITIALISER_H

// fonction dédiée à l'initialisation du tarmac
int tarmacInitialiser(tarmac *t) {
    if(t == NULL)
        return EXIT_FAILURE;

    // on change le titre
    snprintf(t->titre, TARMAC_TAILLE_TITRE, "===Tarmac===");

    // on inititalise le titre
    affichageInitialiser(&t->affichageTitre);

    // on initialise l'affichage
    affichageInitialiser(&t->affichage);
    t->affichage.margeBas = 1;

    // on initialise l'affichage colonne
    colonneInitialiserTableau(&t->affichage, t->colonnesAvions, TARMAC_NB_AVIONS, 6, TARMAC_VALEUR_DEFAUT);

    // on met le tableau de pointeurs d'avions vides
    for(int i = 0; i < TARMAC_NB_AVIONS; ++i) {
        t->avionsPresents[i] = NULL;
    }

    return EXIT_SUCCESS;
}

#endif //LO41_PROJET_TARMACINITIALISER_H
