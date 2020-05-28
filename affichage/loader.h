//
// Created by TheRolf on 27/05/2020.
//

#ifndef LO41_PROJET_LOADER_H
#define LO41_PROJET_LOADER_H

#include "affichage_struct.h"
#include "affichage_fonction.h"
#include "../utilitaires/couleurs.h"


typedef enum enum_etat_loader {
    LOADER_PAS_CHARGE,
    LOADER_CHARGEMENT,
    LOADER_TERMINE
} etat_loader;

const char loader_caractere_pas_charge = '_';

#define ETAPES_CHARGEMENT 4
const char loader_caracteres_chargement[ETAPES_CHARGEMENT] = {
        '|',
        '/',
        '-',
        '\\'
};

const char loader_caractere_termine = 'V';

typedef struct s_loader {
    etat_loader etat; // etat du loader
    unsigned int offset_caractere; // offset (loader_caracteres_chargement)
    char caractere; // caractère actuel
    int vitesse; // en secondes
    affichage_struct affichage;
} loader_struct;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedGlobalDeclarationInspection"

int changerEtatLoader(loader_struct *loader, etat_loader nouvelEtat) {
    loader->etat = nouvelEtat;

    switch (nouvelEtat) {
        case LOADER_CHARGEMENT:
            loader->caractere = loader_caracteres_chargement[0];
            break;
        case LOADER_TERMINE:
            loader->caractere = loader_caractere_termine;
            break;
        default:
            loader->caractere = loader_caractere_pas_charge;
            break;
    }
}

/// Permet de changer le caractere lors du chargement
/// \param loader le loader affecté
void updateCaractere(loader_struct* loader) {
    if(loader->etat == LOADER_CHARGEMENT) {
        unsigned int offset = loader->offset_caractere;
        offset = (offset + 1) % ETAPES_CHARGEMENT;
        loader->offset_caractere = offset;
        loader->caractere = loader_caracteres_chargement[offset];
    }
}

int ajouterMargeLoader(affichage_struct *affichage) {
    if(affichage == NULL)
        return EXIT_FAILURE;

    // on ajoute 3 de marge
    affichage->margeGauche = affichage->margeGauche + 3;
    return EXIT_SUCCESS;
}

int enleverMargeLoader(affichage_struct *affichage) {
    if(affichage == NULL || affichage->margeGauche < 3)
        return EXIT_FAILURE;

    // on enlève 3 de marge
    affichage->margeGauche = affichage->margeGauche - 3;
    return EXIT_SUCCESS;
}

/// Affiche le loader dans un affichage
/// \param affichage place dans l'affichage
/// \param loader loader concerné
void afficherLoader(loader_struct *loader) {
    switch (loader->etat) {
        case LOADER_CHARGEMENT:
            printf("" KYEL);
            affichageWrite(&loader->affichage, " %c", loader->caractere);
            printf("" KNRM);
            break;
        case LOADER_TERMINE:
            printf("" KGRN);
            affichageWrite(&loader->affichage, " %c ", loader->caractere);
            printf("" KNRM);
            break;
        default:
            affichageWrite(&loader->affichage, " %c ", loader->caractere);
            break;
    }
}

#pragma clang diagnostic pop

#endif //LO41_PROJET_LOADER_H
