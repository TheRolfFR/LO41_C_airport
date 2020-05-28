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

    sleep(5);
    system("clear");

    affichage_struct aff;
    aff.hauteur = 1;
    aff.margeHaut = 2;
    ajouterAffichage(&aff);
    loader_struct loader;
    ajouterMargeLoader(&aff);
    changerEtatLoader(&loader, LOADER_PAS_CHARGE);

    affichageClean(&aff);
    afficherLoader(&aff, &loader);
    affichagePrintf(&aff, "Je ne charge pas.\n");

    changerEtatLoader(&loader, LOADER_CHARGEMENT);
    int i = 0;
    while(i < 8) {
        affichageClean(&aff);
        afficherLoader(&aff, &loader);
        affichageWrite(&aff,"Je suis en train de charger : %d/8\n", i+1);
        sleep(1);
        updateCaractere(&loader);
        ++i;
    }

    changerEtatLoader(&loader, LOADER_TERMINE);
    affichagePrintf(&aff, "Je suis chargé.\n");
    afficherLoader(&aff, &loader);
    return 0;
}