//
// Created by TheRolf on 15/05/2020.
//

#ifndef LO41_PROJET_CREERAVION_H
#define LO41_PROJET_CREERAVION_H

#include "avion.h"
#include "choisirDestination.h"
#include "../utilitaires/aleatoire.h"
#include "../constantes.h"
#include "../utilitaires/date.h"
#include "avionAtterissageForce.h"

// fonction lancée quand on veut créer un nouvel avion aléatoire
avion* creerAvion() {
    avion* resultat = (avion*) malloc(sizeof(avion)); // on génère dynamiquement un nouvel avion

    resultat->estArrivant = true;

    // on choisit une nouvelle destination
    choisirDestination(resultat);

    // on génère une quantité aléatoire de fuel entre FUEL_MIN et FUEL_MAX
    resultat->fuel = aleatoireEntierRange(FUEL_MIN, FUEL_MAX);

    // on se demande si c'est un gros avion
    resultat->grosAvion = aleatoireFloatRange(0, 1, 3) <= PROBA_GROS_AVION;

    avionAtterissageForce(resultat);

    // date d'atterissage
    mettreDate(resultat);

    return resultat;
}

void detruireAvion(avion* a) {
    free(a);
}


#endif //LO41_PROJET_CREERAVION_H