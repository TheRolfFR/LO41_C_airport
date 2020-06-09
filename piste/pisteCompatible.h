//
// Created by TheRolf on 09/06/2020.
//

#ifndef LO41_PROJET_PISTECOMPATIBLE_H
#define LO41_PROJET_PISTECOMPATIBLE_H

#include "../avion/avion.h"
#include "../constantes.h"
#include "../listeAttente/listeAttenteLongueur.h"

bool pisteCompatible(avion *a, avion* liste[NB_AVIONS],avion* autreListe[NB_AVIONS], bool grandePiste) {
    // impossible de mettre un gros avions sur une grosse piste
    if(a->grosAvion && !grandePiste)
        return false;

    // est-ce que j'y gagne a le mettre sur l'autre piste en terme de longueur, alors oui mais strictement inférieur
    return listeAttenteLongueur(autreListe) < listeAttenteLongueur(liste);
}

#endif //LO41_PROJET_PISTECOMPATIBLE_H
