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
#include "affichage/loader.h"
#include "constantes.h"

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
    affichageInitialiser(&aff);
    affichageInitialiser(&deuxieme_ligne);
    affichageInitialiser(&loader.affichage);

    aff.hauteur = 1;
    aff.margeBas = 2;
    ajouterAffichage(&liste, &aff);
    ajouterAffichage(&liste, &deuxieme_ligne);

    affichage_dupliquer(&aff, &(loader.affichage));
    ajouterMargeLoader(&aff);
    changerEtatLoader(&loader, LOADER_PAS_CHARGE);

    affichageClean(&aff);
    afficherLoader(&loader);
    affichageWrite(&aff, "Je ne charge pas.\n");

    affichagePrintf(&deuxieme_ligne, "Je suis une seconde ligne");

    sleep(1);

    changerEtatLoader(&loader, LOADER_CHARGEMENT);
    int i = 0;
    while(i < 42) {
        affichageClean(&aff);
        afficherLoader(&loader);
        affichageWrite(&aff,"Je suis en train de charger : %d/8\n", i+1);
        usleep(75000);
        updateCaractere(&loader);
        ++i;
    }

    changerEtatLoader(&loader, LOADER_TERMINE);

    affichageClean(&aff);
    afficherLoader(&loader);
    affichageWrite(&aff, "Je suis chargé.\n");
    return 0;
}