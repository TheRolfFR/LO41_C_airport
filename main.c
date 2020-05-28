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
    system("clear");

    affichage_struct *liste = NULL;
    affichage_struct aff, loader_aff;

    // initialize affichage
    affichageInitialiser(&aff);
    affichageInitialiser(&loader_aff);

    aff.hauteur = 1;
    aff.margeHaut = 2;
    ajouterAffichage(liste, &aff);
    ajouterAffichage(liste, &loader_aff);

    affichage_dupliquer(&aff, &loader_aff);

    loader_struct loader;
    ajouterMargeLoader(&aff);
    changerEtatLoader(&loader, LOADER_PAS_CHARGE);

    affichageClean(&aff);
    afficherLoader(&loader_aff, &loader);
    affichageWrite(&aff, "Je ne charge pas.\n");

    sleep(1);

    changerEtatLoader(&loader, LOADER_CHARGEMENT);
    int i = 0;
    while(i < 42) {
        affichageClean(&aff);
        afficherLoader(&loader_aff, &loader);
        affichageWrite(&aff,"Je suis en train de charger : %d/8\n", i+1);
        usleep(250000);
        updateCaractere(&loader);
        ++i;
    }

    changerEtatLoader(&loader, LOADER_TERMINE);

    affichageClean(&aff);
    afficherLoader(&loader_aff, &loader);
    affichageWrite(&aff, "Je suis chargé.\n");
    return 0;
}