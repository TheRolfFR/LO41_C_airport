//
// Created by TheRolf on 15/05/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "utilitaires/aleatoire.h"
#include "utilitaires/lireLigne.h"
#include "avion/avionCreer.h"
#include "constantes.h"

int prompt (void) {
    initAleatoire(); // on initialise l'aléatoire

    int rc;
    char buff[LONGUEUR_BUFFER];

    rc = lireLigne("Enter string> ", buff, sizeof(buff));
    if (rc == NO_INPUT) {
        printf ("No input\n");
        return 1;
    }

    if (rc == TOO_LONG) {
        printf ("Input too long\n");
        return 1;
    }

    printf ("OK [%s]\n", buff);

    return 0;
}