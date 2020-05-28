//
// Created by TheRolf on 27/05/2020.
//

#ifndef LO41_PROJET_AFFICHAGE_FONCTION_H
#define LO41_PROJET_AFFICHAGE_FONCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "affichage_struct.h"

int ajouterAffichage(affichage_struct* affichage) {
    if(affichage == NULL)
        return EXIT_FAILURE;


    if (listeAffichage == NULL) {
        listeAffichage = affichage;
        return EXIT_SUCCESS;
    }

    affichage_struct *affichageActuel = listeAffichage;
    while (affichageActuel->suivant != NULL) {
        affichageActuel = affichageActuel->suivant;
    }

    // on s'ajoute à la fin
    affichageActuel->suivant = affichage;
    affichage->precedent = affichageActuel;

    return EXIT_SUCCESS;
}

int supprimerAffichage(affichage_struct* affichage) {
    if(affichage == NULL)
        return EXIT_FAILURE;

    // on lie avec le précédent
    if(affichage->precedent != NULL)
        affichage->precedent->suivant = NULL;

    // on lie avec le suivant
    if(affichage->suivant != NULL)
        affichage->suivant->precedent = NULL;

    return EXIT_SUCCESS;
}

void trouverOffset(affichage_struct *affichage, unsigned int *x, unsigned int *y) {
    unsigned int offset = 0;

    // on calcule l'offset
    affichage_struct *affichageActuel = listeAffichage;
    while(affichageActuel != NULL && affichageActuel != affichage) {
        offset += affichageActuel->margeHaut + affichageActuel->hauteur + affichageActuel->margeBas;
        affichageActuel = affichageActuel->suivant;
    }

    // goto x = 0 and y = offset
    *x = affichage->margeGauche + 1;
    *y = offset + 1;
}

void affichageClean(affichage_struct* affichage) {
    unsigned int x, y;
    trouverOffset(affichage, &x, &y);

    for(unsigned int i = 0; i < affichage->hauteur; ++i) {
        printf("\033[%d;%dH", y+i, x);
        printf("%c[2K", 27);
        printf("                                                                                 ");
    }
}

void affichageWrite(affichage_struct* affichage, char* format, ...) {
    unsigned int x, y;
    trouverOffset(affichage, &x, &y);

    // clear line
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

#endif //LO41_PROJET_AFFICHAGE_FONCTION_H
