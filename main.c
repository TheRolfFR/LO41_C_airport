#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "utilitaires/aleatoire.h"
#include "utilitaires/lireLigne.h"
#include "avion/creerAvion.h"
#include "avion/aficherAvion.h"
#include "constantes.h"

int main (void) {
    initAleatoire(); // on initialise l'aléatoire

    avion* a = creerAvion();

    afficherAvion(a);

    detruireAvion(a);
    return 0;
}