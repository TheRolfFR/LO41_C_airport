#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "utilitaires/aleatoire.h"
#include "utilitaires/lireLigne.h"
#include "avion/creerAvion.h"
#include "avion/aficherAvion.h"
#include "affichage/affichage_fonction.h"
#include "affichage/affichage_fonction_variable.h"
#include "affichage/loader.h"
#include "constantes.h"

#define MAX_ROTATIONS 42

int main (void) {
    initAleatoire(); // on initialise l'aléatoire

    avion* a = creerAvion();

    afficherAvion(a);

    detruireAvion(a);

    // sleep(5);
    affichageNettoyerEcran();

    affichage_struct *liste = NULL;
    affichage_struct aff, deuxieme_ligne;

    loader_struct loader;

    // initialize affichage
    affichageInitialiser(&loader.affichage);
    affichageInitialiser(&deuxieme_ligne);

    loader.affichage.hauteur = 1;
    loader.affichage.margeBas = 2;
    ajouterAffichage(&liste, &loader.affichage);
    ajouterAffichage(&liste, &deuxieme_ligne);

    changerEtatLoader(&loader, LOADER_PAS_CHARGE);

    affichagePrintf(&deuxieme_ligne, "Je suis une seconde ligne");

    sleep(1);

    changerEtatLoader(&loader, LOADER_CHARGEMENT);
    int i = 0;
    while(i < MAX_ROTATIONS) {
        afficherLoaderTexte(&loader, "Je suis en train de charger : %d/%d\n", i+1, MAX_ROTATIONS);
        usleep(75000);
        updateCaractere(&loader);
        ++i;
    }

    changerEtatLoader(&loader, LOADER_TERMINE);

    afficherLoaderTexte(&loader, "Je suis chargé.\n");

    sleep(1);

    // comment afficher une erreur
    changerEtatLoader(&loader, LOADER_ERREUR);
    afficherLoaderTexte(&loader, "Ceci est une erreur.\n");

    return 0;
}