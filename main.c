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
    loaderInitialiser(&loader);
    affichageInitialiser(&deuxieme_ligne);

    ajouterAffichage(&liste, &loader.affichage);
    ajouterAffichage(&liste, &deuxieme_ligne);

    loaderAfficherTexteEtat(&loader, LOADER_PAS_CHARGE, "Je ne suis pas chargé.");

    affichagePrintf(&deuxieme_ligne, "Je suis une seconde ligne");

    sleep(1);

    loaderChangerEtat(&loader, LOADER_CHARGEMENT);
    int i = 0;
    while(i < MAX_ROTATIONS) {
        loaderAfficherTexte(&loader, "Je suis en train de charger : %d/%d\n", i + 1, MAX_ROTATIONS);
        usleep(75000);
        loaderUpdateCaractere(&loader);
        ++i;
    }

    loaderAfficherTexteEtat(&loader, LOADER_TERMINE, "Je suis chargé.\n");

    sleep(1);

    // comment afficher une erreur
    loaderAfficherTexteEtat(&loader, LOADER_ERREUR, "Ceci est une erreur.\n");

    return 0;
}