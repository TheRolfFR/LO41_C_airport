#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "utilitaires/aleatoire.h"
#include "utilitaires/lireLigne.h"
#include "avion/creerAvion.h"
#include "avion/aficherAvion.h"
#include "avion/avionChangerDirection.h"
#include "affichage/affichage_fonction.h"
#include "affichage/loader.h"
#include "piste/piste.h"
#include "affichage/colonne/colonne_fonction.h"
#include "constantes.h"

#define MAX_ROTATIONS 42

int main (void) {
    initAleatoire(); // on initialise l'aléatoire

    avion* a = creerAvion();
    avion* b = creerAvion();

    // sleep(5);
    affichageNettoyerEcran();

    affichage_struct *liste = NULL;
    affichage_struct aff, deuxieme_ligne;

    loader_struct loader;

    // ajout de pistes
    piste mesPistes[2];
    initialiserPiste(&mesPistes[0], true);
    initialiserPiste(&mesPistes[1], false);

    mesPistes[0].avionEnCours = a;
    mesPistes[1].avionEnCours = b;

    affichageAjouter(&liste, &mesPistes[0].affichage);
    affichageAjouter(&liste, &mesPistes[1].affichage);

    afficherPiste(&mesPistes[0]);
    afficherPiste(&mesPistes[1]);

    // ajout des colonnes
    affichage_struct affichageColonne;
    colonne_struct mesColonnes[10];
    affichageInitialiser(&affichageColonne);
    colonneInitialiserTableau(&affichageColonne, mesColonnes, 10, 6, "yes");
    affichageAjouter(&liste, &affichageColonne);
    colonneLigneUpdate(&mesColonnes[0]);

    // initialize affichage
    affichageInitialiser(&loader.affichage);
    affichageInitialiser(&deuxieme_ligne);

    loader.affichage.hauteur = 1;
    affichageAjouter(&liste, &loader.affichage);
    affichageAjouter(&liste, &deuxieme_ligne);

    loaderAfficherTexteEtat(&loader, LOADER_TERMINE, "Je suis chargé.\n");

    affichagePrintf(&deuxieme_ligne, "Je suis une seconde ligne\n");

    sleep(1);

    loaderChangerEtat(&loader, LOADER_CHARGEMENT);
    int i = 0;
    while(i < MAX_ROTATIONS) {
        if(i%6 == 0) {
            avionChangerDirection(a);
            avionChangerDirection(b);

            afficherPiste(&mesPistes[0]);
            afficherPiste(&mesPistes[1]);
        }
        loaderAfficherTexte(&loader, "Je suis en train de charger : %d/%d\n", i + 1, MAX_ROTATIONS);
        usleep(75000);
        loaderUpdateCaractere(&loader);
        ++i;
    }

    sleep(1);

    // comment afficher une erreur
    loaderChangerEtat(&loader, LOADER_ERREUR);
    loaderAfficherTexte(&loader, "Ceci est une erreur.\n");

    affichagePrintf(&deuxieme_ligne, "Je suis une seconde ligne\n");

    detruireAvion(a);
    detruireAvion(b);

    return 0;
}