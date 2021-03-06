//
// Created by TheRolf on 28/05/2020.
//

#ifndef LO41_PROJET_AFFICHAGE_FONCTION_VARIABLE_H
#define LO41_PROJET_AFFICHAGE_FONCTION_VARIABLE_H

#include "affichage_fonction_va.h"
#include "affichage_fonction.h"
#include <stdarg.h>


void affichageWriteOffset(affichage_struct *affichage, int offsetX, int offsetY, char *format, ...) {

    // setting position
    printf("\033[%d;%dH", offsetY, offsetX);

    // extract args
    va_list args;
    va_start(args, format);
    // print body
    affichageWriteOffsetVa(affichage, offsetX, offsetY, format, args);
    // end args
    va_end(args);
}

#endif //LO41_PROJET_AFFICHAGE_FONCTION_VARIABLE_H
