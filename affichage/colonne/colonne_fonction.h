//
// Created by TheRolf on 30/05/2020.
//

#ifndef LO41_PROJET_COLONNE_FONCTION_H
#define LO41_PROJET_COLONNE_FONCTION_H

#include <stdlib.h>
#include <stdarg.h>
#include "colonne_struct.h"
#include "../affichage_fonction_variable.h"
#include <string.h>

#define COLONNE_LARGEUR_DEFAUT (COLONNE_TAILLE_BUFFER - 1);

// initialise tout a 0
int colonneInitialiser(colonne_struct *colonne, affichage_struct *affichage) {
    if(colonne == NULL)
        return EXIT_FAILURE;

    colonne->largeur = COLONNE_LARGEUR_DEFAUT;

    strncpy(colonne->contenu, "", COLONNE_TAILLE_BUFFER);

    colonne->precedent = NULL;
    colonne->suivant = NULL;
    colonne->affichage = affichage;

    return EXIT_SUCCESS;
}

// ajoute une colonne a la suite
int colonneAjouterSuite(colonne_struct *premier, colonne_struct *source) {
    if(premier == NULL || source == NULL)
        return EXIT_FAILURE;

    // trouver la queue
    colonne_struct *colonneActuelle = premier;
    while (colonneActuelle->suivant != NULL)
        colonneActuelle = colonneActuelle->suivant;

    // une fois trouvée on peut les accrocher
    colonneActuelle->suivant = source;
    source->precedent = colonneActuelle;

    return EXIT_SUCCESS;
}

// change le contenu de la colonne
void colonneChangeContenu(colonne_struct *colonne, char *format, ...) {
    if(colonne == NULL)
        return;

    // debut arguments
    va_list args;
    va_start(args, format);

    // on print dedans
    // ici on prends COLONNE_TAILLE_BUFFER comme longueur car si on décide de changer la largeur d'affichage, le contenu n'est pas concerné
    vsnprintf(colonne->contenu, COLONNE_TAILLE_BUFFER, format, args);

    // fin arguments
    va_end(args);
}

int trouverOffsetColonne(colonne_struct *colonne) {
    if(colonne == NULL)
        return EXIT_FAILURE;

    int offset = 0;

    colonne_struct *colonneActuelle = colonne;
    while (colonneActuelle->precedent != NULL) {
        colonneActuelle = colonneActuelle->precedent;
        offset += colonneActuelle->largeur;
    }

    return offset;
}

// le but ici est de faire une chaine globale ou de write à l'offset en particuler
void colonneUpdate(colonne_struct *colonne) {
    if(colonne == NULL)
        return;

    // récupérer l'offset
    int x, y;
    trouverOffset(colonne->affichage, &x, &y);

    // trouver l'offset de la colonne
    x += trouverOffsetColonne(colonne);

    // il faut clean les caractères de la colonne en particulier
    char clean[COLONNE_TAILLE_BUFFER];
    int i;
    for(i = 0; i < colonne->largeur; ++i) // ATTENTION IL FAUT UNIQUEMENT CLEAR LA LARGEUR DE LA COLONNE
        clean[i] = ' ';
    clean[i] = '\0';

    // on clean les caractères
    affichageWriteOffset(colonne->affichage, x, y, clean);

    // on remplace les caractères
    affichageWriteOffset(colonne->affichage, x, y, colonne->contenu);
}

// permet de trouver le nombre de colonnes dans un affichage colonne
int colonneNombre(colonne_struct *colonne) {
    if(colonne == NULL)
        return EXIT_FAILURE;

    // trouver la tete
    colonne_struct *colonneActuelle = colonne;
    while (colonneActuelle->precedent != NULL)
        colonneActuelle = colonneActuelle->precedent;

    // pouvoir compter
    int compte = 0;

    // enfin on augmente jusqu'à la fin
    while (colonneActuelle != NULL) {
        ++compte;
        colonneActuelle = colonneActuelle->suivant;
    }

    return compte;
}

int colonneInitialiserTableau(affichage_struct *affichage, colonne_struct colonnes[], int longueurTableau, int largeurColonne, char *valeurParDefaut) {
    if(affichage == NULL || colonnes == NULL || longueurTableau < 1 || valeurParDefaut == NULL)
        return EXIT_FAILURE;

    //initialiser toutes les valeurs
    for(int i = 0; i < longueurTableau; ++i) {
        // on les initialise
        colonneInitialiser(&colonnes[i], affichage);

        // on change ENSUITE leur largeur (car l'initialisation change la largeur)
        colonnes[i].largeur = largeurColonne;

        // on change ENSUITE leur valeur(car l'initialisation change la valeur par défaut)
        colonneChangeContenu(&colonnes[i], valeurParDefaut);

        // enfin si ce n'est pas le premier on les chaine
        if(i > 0) {
            colonneAjouterSuite(&colonnes[0], &colonnes[i]);
        }
    }

    return EXIT_SUCCESS;
}

void colonneLigneUpdate(colonne_struct *colonne) {
    if(colonne == NULL)
        return;

    // trouver la tete
    colonne_struct *colonneActuelle = colonne;
    while (colonneActuelle->precedent != NULL)
        colonneActuelle = colonneActuelle->precedent;

    // une fois trouvée, on update jusqu'à la queue
    while (colonneActuelle != NULL) {
        colonneUpdate(colonneActuelle);
        colonneActuelle = colonneActuelle->suivant;
    }
}

#endif //LO41_PROJET_COLONNE_FONCTION_H
