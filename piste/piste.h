//
// Created by TheRolf on 28/05/2020.
//

#ifndef LO41_PROJET_PISTE_H
#define LO41_PROJET_PISTE_H

#include <stdlib.h>
#include <stdbool.h>
#include "../avion/avion.h"
#include "../affichage/affichage_struct.h"
#include "../affichage/affichage_fonction.h"
#include "../affichage/affichage_fonction_variable.h"
#include <string.h>
#include "../utilitaires/ecrireSuite.h"
#include "../utilitaires/couleurs.h"

#define PISTE_HAUTEUR_TEXTE 1
#define PISTE_HAUTEUR (3 + PISTE_HAUTEUR_TEXTE)
#define PISTE_LONGUE_HAUTEUR (5 + PISTE_HAUTEUR_TEXTE)

#define PISTE_LONGUE_LARGEUR 20
#define PISTE_LARGEUR 15

#define PISTE_TAILLE_BUFFER 500

typedef struct s_piste {
    bool occupe;
    avion *avionEnCours;
    bool longue;
    affichage_struct affichage;
} piste;

int initialiserPiste(piste *p, bool longue) {
    if(p == NULL)
        return EXIT_FAILURE;

    // tout vide
    p->occupe = false;
    p->avionEnCours = NULL;
    p->longue = longue;

    // affichage tout initial
    affichageInitialiser(&p->affichage);

    // on ajoute des marges
    p->affichage.margeHaut = 1;
    p->affichage.margeBas = 1;

    // ajustement de la hauteur
    if(longue) {
        p->affichage.hauteur = PISTE_LONGUE_HAUTEUR;
    } else {
        p->affichage.hauteur = PISTE_HAUTEUR;
    }

    return EXIT_SUCCESS;
}

void afficherPiste(piste *p) {
    char buffer[PISTE_TAILLE_BUFFER];

    // on clean le buffer
    memset(buffer, 0, PISTE_TAILLE_BUFFER);
    strcpy(buffer, "");

    bool longue = p->longue;

    // ecrire le texte au début
    ecrireSuite(buffer, (longue) ? "Longue piste\n" : "Petite piste\n", PISTE_TAILLE_BUFFER);

    // la ligne horizontale
    int longueur = (longue) ? PISTE_LONGUE_LARGEUR : PISTE_LARGEUR;
    for(int i = 0; i < longueur; ++i) {
        ecrireSuite(buffer, "=", PISTE_TAILLE_BUFFER);
    }
    ecrireSuite(buffer, "\n", PISTE_TAILLE_BUFFER); // le retour a la ligne

    if(longue) {
        ecrireSuite(buffer, "\n", PISTE_TAILLE_BUFFER); // encore un espace
    }

    // au centre affichage de l'occupation de la piste
    if(p->avionEnCours != NULL) {
        if(p->avionEnCours->atterissageUrgent) {
            ecrireSuite(buffer, "Atterrissage d'urgence de l'avion\n", PISTE_TAILLE_BUFFER);
        } else {
            ecrireSuite(buffer, "Utilisation de la piste par un avion\n", PISTE_TAILLE_BUFFER);
        }
    } else {
        ecrireSuite(buffer, "Piste libre\n", PISTE_TAILLE_BUFFER);
    }

    if(longue) {
        ecrireSuite(buffer, "\n", PISTE_TAILLE_BUFFER); // encore un espace
    }

    // la ligne horizontale
    for(int i = 0; i < longueur; ++i) {
        ecrireSuite(buffer, "=", PISTE_TAILLE_BUFFER);
    }
    ecrireSuite(buffer, "\n", PISTE_TAILLE_BUFFER); // le retour a la ligne

    //avant print changer la couleur
    if(p->avionEnCours != NULL) {
        if(p->avionEnCours->atterissageUrgent) {
            printf("" KRED); // piste rouge atterrissage urgence
        } else {
            printf("" KYEL); // piste utilisée
        }
    }

    affichagePrintf(&p->affichage, buffer);

    printf("" KNRM); // on remet la couleur normale
}

#endif //LO41_PROJET_PISTE_H
