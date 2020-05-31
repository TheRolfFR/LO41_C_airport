//
// Created by TheRolf on 31/05/2020.
//

#ifndef LO41_PROJET_TARMAC_STRUCT_H
#define LO41_PROJET_TARMAC_STRUCT_H

#define TARMAC_TAILLE_TITRE 200
#define TARMAC_VALEUR_DEFAUT "vide"

#include "../affichage/colonne/colonne_struct.h"
#include "../constantes.h"
#include "../avion/avion.h"

typedef struct s_tarmac {
    char titre[TARMAC_TAILLE_TITRE];
    affichage_struct affichageTitre;
    affichage_struct affichage;
    colonne_struct colonnesAvions[TARMAC_NB_AVIONS];
    avion *avionsPresents[TARMAC_NB_AVIONS];
} tarmac;

#endif //LO41_PROJET_TARMAC_STRUCT_H
