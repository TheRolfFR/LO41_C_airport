//
// Created by TheRolf on 15/05/2020.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedMacroInspection"

#ifndef LO41_PROJET_CONSTANTES_H
#define LO41_PROJET_CONSTANTES_H

#define LONGUEUR_BUFFER 200

// destinations
#define NB_DESTINATIONS_FRANCE 20
char* destionations_fr[NB_DESTINATIONS_FRANCE] = {
        "Bordeaux",
        "Brest",
        "Caen",
        "Cherbourg",
        "Clermont-Ferrand",
        "Dijon",
        "Grenoble",
        "Le Havre",
        "Lille",
        "Lyon",
        "Marseille",
        "Metz-Nancy",
        "Nantes",
        "Nice",
        "Paris",
        "Rennes",
        "Strasbourg",
        "Toulon",
        "Toulouse",
        "Tours"
};

#define NB_DESTINATIONS_INTER 10
char* destinations_inter[NB_DESTINATIONS_INTER] = {
        "Allemagne",
        "Afrique du Sud",
        "Canada",
        "Chine",
        "Espagne",
        "Etats-Unis",
        "Maroc",
        "Norvege",
        "Portugal",
        "Tasmanie"
};

// pistes
#define LONGUEUR_PISTE_PRINCIPALE 4000
#define LONGUEUR_PISTE_SECONDAIRE 2500

// paramètres de modele
#define PROBA_DESTINATION_INTER 0.15

#define FUEL_MIN 100
#define FUEL_MAX 800

#define PROBA_GROS_AVION 0.4

#define PROBA_ATTERISSAGE_FORCE 0.1

#define AJOUT_HORAIRE_SEC_MIN 3
#define AJOUT_HORAIRE_SEC_MAX 8


#endif //LO41_PROJET_CONSTANTES_H