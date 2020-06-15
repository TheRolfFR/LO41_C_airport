//
// Created by TheRolf on 09/06/2020.
//

#ifndef LO41_PROJET_METTREAJOUR_H
#define LO41_PROJET_METTREAJOUR_H

#include "../avion/avion.h"
#include "../constantes.h"
#include "listeAttenteAvion.h"
#include "../piste/pisteCompatible.h"
#include "../avion/avionDansListe.h"
#include <string.h>

void traiterAvion(avion *maPiste[NB_AVIONS], avion *lAutrePiste[NB_AVIONS], avion* a, bool grandePiste) {
    int i = 1;
    avion *m = maPiste[i];
    while (avionComparer(a, m) > 0){ // METTRE APRES LE COMPARER EN DERNIER RECOURS
        // 1. je bouge tant que possible

        m = maPiste[i];
        ++i;
    }

    if(pisteCompatible(a, maPiste, lAutrePiste, grandePiste)) { // 2. ça vaut le coup de bouger
        // 3. on détermine où aller dans l'autre liste
        int mouvement = avionComparer(a, lAutrePiste[i]);
        i += mouvement;
        int sens = mouvement;
        while(i > 0 && mouvement != 0 && sens == mouvement) {
            mouvement = avionComparer(a, lAutrePiste[i]);
            i+= mouvement;
        } // 3. quand on a fini de bouger, on décale le reste vers la droite et on s'insère

        listeAttenteDecalerTard(i, lAutrePiste, NB_AVIONS); // decaler les avions a partir de ce rang
        lAutrePiste[i] = a; // le placer a cet endroit
    } else {
        listeAttenteDecalerTard(i, maPiste, NB_AVIONS); // decaler les avions a partir de ce rang
        lAutrePiste[i] = a; // le placer a cet endroit
    }
}

// il n'y a pas de première fois, on retraite quand même le premier avion
void mettreAJour(avion *grandeListe[NB_AVIONS], avion *petiteListe[NB_AVIONS], avion *misAJour) {
    // on sait quand traiter les listes
    avion *traite[NB_AVIONS];
    memset(traite, 0, sizeof(bool) * NB_AVIONS);

    // le premier avion est particulier car avant

    // on recule jusqu'à ne plus pouvoir dans sa liste
    // encore fauut il connaitre dans quelle liste on est
    bool jeSuisSurGrandePiste = listeAttenteAvion(grandeListe, petiteListe, misAJour);

    // si c'est la grande on a moins de chance de passer sur la petite
    if (jeSuisSurGrandePiste) {
        traiterAvion(grandeListe, petiteListe, misAJour, jeSuisSurGrandePiste);
    } else {
        traiterAvion(petiteListe, grandeListe, misAJour, jeSuisSurGrandePiste);
    }
    int traiteindex = 0;
    traite[traiteindex] = misAJour;
    ++traiteindex;

    int i = 0;
    avion *a;
    while (grandeListe[i] != NULL) {
        a = grandeListe[i];
        if (!avionDansListe(a, traite)) {
            traiterAvion(grandeListe, petiteListe, a, true);
            traite[traiteindex] = a;
            ++traiteindex;
        }

        ++i;
    }

    i = 0;
    while (petiteListe[i] != NULL) {
        a = petiteListe[i];
        if (!avionDansListe(a, traite)) {
            traiterAvion(petiteListe, grandeListe, a, false);
            traite[traiteindex] = a;
            ++traiteindex;
        }

        ++i;
    }
}

#endif //LO41_PROJET_METTREAJOUR_H
