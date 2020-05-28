//
// Created by TheRolf on 27/05/2020.
//

#ifndef LO41_PROJET_AFFICHAGE_STRUCT_H
#define LO41_PROJET_AFFICHAGE_STRUCT_H

#include <stdio.h>

typedef struct s_affichage {
    int margeHaut;
    int margeBas;
    int margeGauche;
    int hauteur;
    struct s_affichage *precedent;
    struct s_affichage *suivant;
} affichage_struct;

#endif //LO41_PROJET_AFFICHAGE_STRUCT_H
