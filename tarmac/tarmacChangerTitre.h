//
// Created by TheRolf on 31/05/2020.
//

#include "tarmac_struct.h"

#ifndef LO41_PROJET_TARMACCHANGERTITRE_H
#define LO41_PROJET_TARMACCHANGERTITRE_H

#include <stdarg.h>

// fonction permettant de changer de manière sure le titre
void tarmacChangerTitre(tarmac *t, char* format, ...) {
    if(t == NULL || format == NULL)
        return;

    // démarrer une va liste
    va_list args;
    va_start(args, format);

    // changer le titre
    vsnprintf(t->titre, TARMAC_TAILLE_TITRE, format, args);

    // finir la va liste
    va_end(args);
}

#endif //LO41_PROJET_TARMACCHANGERTITRE_H
