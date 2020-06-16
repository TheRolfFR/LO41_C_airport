//
// Created by TheRolf on 09/06/2020.
//

#ifndef LO41_PROJET_PREMIEREGENERATION_H
#define LO41_PROJET_PREMIEREGENERATION_H

#include "../avion/avion.h"
#include "../constantes.h"
#include "../avion/avionComparer.h"
#include "listeAttenteDecalerTard.h"

void premiereGeneration(avion *grandeListe[NB_AVIONS], avion *petiteListe[NB_AVIONS], avion *listeAvions[NB_AVIONS]) {
    // pour chaque avion
    bool grandAvion;
    int j;

    int longueurPetite = 0;
    int longueurGrande = 0;

    for(int i = 0; i < NB_AVIONS; ++i) {
        // on regarde quelle pistes sont compatibles
        /*printf("\n%p\n", listeAvions[i]);
        fflush(stdout);*/
        grandAvion = listeAvions[i]->grosAvion;

        // si on ne peut faire que la grande piste, on ne parcourt qu'elle
        if(grandAvion) {
            j = 0;
            while (grandeListe[j] != NULL && avionComparer(listeAvions[i], grandeListe[j]) >= 1) {
                ++j; // on avance
            }

            if(grandeListe[j] != NULL) {
                // on est arrivé à la fin
                // on décale les autres et on insère le celui-ci
                listeAttenteDecalerTard(j, grandeListe, longueurGrande);
            }
            // on le place à la fin
            grandeListe[j] = listeAvions[i];

            ++longueurGrande;
        } else {
            // on fait tout en parallèle
            j = 0;
            int k = 0;

            bool petitMeilleur, grandMeileur;
            while (grandeListe[j] != NULL && petiteListe[k] == NULL && (petitMeilleur = avionComparer(listeAvions[i], grandeListe[j])) >= 1 && (grandMeileur = avionComparer(listeAvions[i], petiteListe[k])) >= 1) {

                // on avance tant qu'on peut
                if(grandeListe[j] != NULL)
                    ++j;

                // on avance tant qu'on peut
                if(petiteListe[k] != NULL)
                    ++k;
            }

            // cas le plus défavorable : les deux sont à la fin, on met sur la plut petite liste
            if(grandeListe[j] == NULL && petiteListe[k] == NULL) {
                if(longueurGrande < longueurPetite) {
                    grandeListe[j] = listeAvions[i];
                    ++longueurGrande;
                } else {
                    petiteListe[k] = listeAvions[i];
                    ++longueurPetite;
                }
            } else {
                // cas moins défavorable : un est arrivé à la fin, l'autre peut se placer, ou autre ou deux meilleurs, bref j meilleur que k ou inversement
                if(j < k) {
                    // grande piste plus tot
                    listeAttenteDecalerTard(j, grandeListe, longueurGrande);
                    grandeListe[j] = listeAvions[i];
                    ++longueurGrande;
                } else if(j > k) {
                    // petite piste plus tot
                    listeAttenteDecalerTard(k, petiteListe, longueurPetite);
                    petiteListe[k] = listeAvions[i];
                    ++longueurPetite;
                } else {
                    // même nombre, un était meilleur que l'autre
                    if(grandMeileur && !petitMeilleur) {
                        listeAttenteDecalerTard(j, grandeListe, longueurGrande);
                        grandeListe[j] = listeAvions[i];
                        ++longueurGrande;
                    } else if(petitMeilleur && !grandMeileur) {
                        listeAttenteDecalerTard(k, petiteListe, longueurPetite);
                        petiteListe[k] = listeAvions[i];
                        ++longueurPetite;
                    } else {
                        // autant meilleurs l'un que l'autre, on équilibre les longueurs, sinon grande
                        if(longueurGrande < longueurPetite) {
                            // on rééquilibre la grande
                            listeAttenteDecalerTard(j, grandeListe, longueurGrande);
                            grandeListe[j] = listeAvions[i];
                            ++longueurGrande;
                        } else {
                            // on rééquilibre la petite
                            listeAttenteDecalerTard(k, petiteListe, longueurPetite);
                            petiteListe[k] = listeAvions[i];
                            ++longueurPetite;
                        }
                    }
                }
            }
        }
    }

}

#endif //LO41_PROJET_PREMIEREGENERATION_H
