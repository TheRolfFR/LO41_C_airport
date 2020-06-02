//
// Created by TheRolf on 15/05/2020.
//

#ifndef LO41_PROJET_DATE_H
#define LO41_PROJET_DATE_H

#include "../avion/avion.h"
#include <time.h>
#include "aleatoire.h"
#include "../constantes.h"
#include <stdio.h>

void mettreDate(avion* a) {
    if(a == NULL)
        return;

    a->temps = time(NULL);

    // on ajoute entre AJOUT_HORAIRE_SEC_MIN et AJOUT_HORAIRE_SEC_MAX secondes
    a->temps += aleatoireEntierRange(AJOUT_HORAIRE_SEC_MIN, AJOUT_HORAIRE_SEC_MAX);

    // on met la date
    a->date = localtime(&a->temps);
}

void afficherDate(struct tm* date) {
    printf("%d-%02d-%02d %02d:%02d:%02d", date->tm_year + 1900, date->tm_mon + 1, date->tm_mday, date->tm_hour, date->tm_min, date->tm_sec);
}

#endif //LO41_PROJET_DATE_H
