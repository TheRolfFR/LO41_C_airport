//
// Created by TheRolf on 27/05/2020.
//

#ifndef LO41_PROJET_AFFICHAGE_FONCTION_H
#define LO41_PROJET_AFFICHAGE_FONCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "affichage_struct.h"

int affichageInitialiser(affichage_struct *affichage) {
    if(affichage == NULL)
        return EXIT_FAILURE;

    affichage->margeHaut = 0;
    affichage->margeGauche = 0;
    affichage->hauteur = 1;
    affichage->margeBas = 0;

    affichage->precedent = NULL;
    affichage->suivant = NULL;

    return EXIT_SUCCESS;
}

int affichageAjouter(affichage_struct **liste, affichage_struct *affichage) {

    if(affichage == NULL)
        return EXIT_FAILURE;


    if (*liste == NULL) {
        *liste = affichage;
        return EXIT_SUCCESS;
    }

    affichage_struct *affichageActuel = *liste;
    while (affichageActuel->suivant != NULL) {
        affichageActuel = affichageActuel->suivant;
    }

    // on s'ajoute à la fin
    affichageActuel->suivant = affichage;
    affichage->precedent = affichageActuel;

    return EXIT_SUCCESS;
}

int affichageSupprimer(affichage_struct **liste, affichage_struct* affichage) {
    if(affichage == NULL)
        return EXIT_FAILURE;

    affichage_struct *prec = affichage->precedent, *suiv = affichage->suivant;

    // si c'est le seul de sa liste
    if(prec == NULL && suiv == NULL) {
        *liste = NULL; // on vide la liste
    } else {
        // sinon

        // si on est au milieu, on relie tout
        if(prec != NULL && suiv != NULL) {
            prec->suivant = suiv;
            suiv->precedent = prec;
        } else {
            // si on est le premier
            if(affichage->precedent == NULL) {
                *liste = suiv; // on met en premier le suivant
                suiv->precedent = NULL; // on indique que au suivant qu'il est premier (possible car on est pas le seul de la liste)
            } else {
                // on est le dernier, on précise au précédent qu'il est dernier
                prec->suivant = NULL;
            }
        }
    }

    return EXIT_SUCCESS;
}

// toruver la tete de la liste d'affichage
affichage_struct* trouverTete(affichage_struct *affichage) {
    if(affichage == NULL)
        return NULL;

    affichage_struct *affichageActuel = affichage;
    while(affichageActuel->precedent != NULL) { // on remonte la liste
        affichageActuel = affichageActuel->precedent;
    }

    return affichageActuel;
}

void trouverOffset(affichage_struct *affichage, int *x, int *y) {
    int offset = 0;

    // on calcule l'offset
    affichage_struct *affichageActuel = trouverTete(affichage);
    while(affichageActuel != NULL && affichageActuel != affichage) {
        offset += affichageActuel->margeHaut + affichageActuel->hauteur + affichageActuel->margeBas;
        affichageActuel = affichageActuel->suivant;
    }

    // goto x = 0 and y = offset
    *x = affichage->margeGauche + 1;
    *y = offset + affichage->margeHaut + 1;
}

void affichageNettoyerEcran() {
    // system("cls"); // on windows
    system("clear"); // on linux
}

void affichageClean(affichage_struct* affichage) {
    int x, y;
    trouverOffset(affichage, &x, &y);

    for(unsigned int i = 0; i < affichage->hauteur; ++i) {
        printf("\033[%d;%dH", y+i, x);
        printf("%c[2K", 27);
    }
}

void affichageWrite(affichage_struct* affichage, char* format, ...) {
    int x, y;
    trouverOffset(affichage, &x, &y);

    // setting position
    printf("\033[%d;%dH", y, x);

    // extract args
    va_list args;
    va_start(args, format);
    // print body
    vfprintf(stdout, format, args);
    // end args
    va_end(args);
}

void affichagePrintf(affichage_struct* affichage, char* format, ...) {
    affichageClean(affichage);

    // extract args
    va_list args;
    va_start(args, format);

    affichageWrite(affichage, format, args);
    // end args
    va_end(args);
}

int affichageDupliquer(affichage_struct *source, affichage_struct *destination) {
    if(source == NULL && destination == NULL)
        return EXIT_FAILURE;

    destination->margeHaut = source->margeHaut;
    destination->margeGauche = source->margeGauche;
    destination->hauteur = source->hauteur;
    destination->margeBas = source->margeBas;
}

#endif //LO41_PROJET_AFFICHAGE_FONCTION_H