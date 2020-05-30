//
// Created by TheRolf on 30/05/2020.
//

#ifndef LO41_PROJET_COLONNE_STRUCT_H
#define LO41_PROJET_COLONNE_STRUCT_H

#include "../affichage_struct.h"

#define COLONNE_TAILLE_BUFFER 200

typedef struct s_aff_col {
    int largeur;

    char contenu[COLONNE_TAILLE_BUFFER];

    struct s_aff_col *precedent;
    struct s_aff_col *suivant;
    struct s_affichage *affichage;
} colonne_struct;

#endif //LO41_PROJET_COLONNE_STRUCT_H
