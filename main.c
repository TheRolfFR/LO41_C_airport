#include <unistd.h>
#include <string.h>
#include "utilitaires/aleatoire.h"
#include "avion/creerAvion.h"
#include "affichage/affichage_fonction.h"
#include "affichage/affichage_fonction_variable.h"
#include "affichage/loader.h"
#include "piste/piste.h"
#include "constantes.h"
#include "affichage/colonne/colonne_fonction.h"

#define MAX_ROTATIONS 42

int main (void) {
    affichageNettoyerEcran();

    initAleatoire(); // on initialise l'aléatoire

    // on cree un avion
    avion* a = creerAvion();
    avion *b = creerAvion();

    // on initalise les pistes
    piste courte, longue;
    initialiserPiste(&longue, true);
    initialiserPiste(&courte, false);

    longue.avionEnCours = a;

    b->atterissageUrgent = true;
    courte.avionEnCours = b;

    afficherPiste(&longue);
    afficherPiste(&courte);

    affichage_struct *liste = NULL;
    affichage_struct deuxieme_ligne;

    loader_struct loader;

    // initialize affichage
    loaderInitialiser(&loader);
    affichageInitialiser(&deuxieme_ligne);
    // on ajoute plein de choses ici
    ajouterAffichage(&liste, &longue.affichage);
    ajouterAffichage(&liste, &courte.affichage);

    // on initialise l'affichage colonne
    affichage_struct affichageColonne;
    colonne_struct mesColonnes[10];
    affichageInitialiser(&affichageColonne);
    colonneInitialiserTableau(&affichageColonne, mesColonnes, 10, 6, "yes");
    ajouterAffichage(&liste, &affichageColonne);
    colonneLigneUpdate(&mesColonnes[0]);

    ajouterAffichage(&liste, &loader.affichage);
    ajouterAffichage(&liste, &deuxieme_ligne);

    loaderAfficherTexteEtat(&loader, LOADER_PAS_CHARGE, "Je ne suis pas chargé.");

    affichagePrintf(&deuxieme_ligne, "Je suis une seconde ligne\n");

    sleep(1);

    loaderChangerEtat(&loader, LOADER_CHARGEMENT);
    int i = 0;
    while(i < MAX_ROTATIONS) {
        afficherPiste(&longue);
        afficherPiste(&courte);
        loaderAfficherTexte(&loader, "Je suis en train de charger : %d/%d\n", i + 1, MAX_ROTATIONS);
        usleep(75000);
        loaderUpdateCaractere(&loader);
        ++i;
    }

    loaderAfficherTexteEtat(&loader, LOADER_TERMINE, "Je suis chargé.\n");

    sleep(1);

    // comment afficher une erreur
    loaderAfficherTexteEtat(&loader, LOADER_ERREUR, "Ceci est une erreur.\n");

    affichagePrintf(&deuxieme_ligne, "Je suis une seconde ligne\n");

    detruireAvion(a);

    return 0;
}