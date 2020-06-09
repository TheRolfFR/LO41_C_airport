//
// Created by TheRolf on 09/06/2020.
//

#ifndef LO41_PROJET_LISTEATTENTELONGUEUR_H
#define LO41_PROJET_LISTEATTENTELONGUEUR_H

#include "../avion/avion.h"
#include "../constantes.h"

int listeAttenteLongueur(avion* liste[NB_AVIONS]) {
    int reponse = 0;

    while(liste[reponse] != NULL)
        ++reponse;

    return reponse;
}

#endif //LO41_PROJET_LISTEATTENTELONGUEUR_H
