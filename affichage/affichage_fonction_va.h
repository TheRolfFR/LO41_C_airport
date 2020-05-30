//
// Created by TheRolf on 28/05/2020.
//

#ifndef LO41_PROJET_AFFICHAGE_FONCTION_VA_H
#define LO41_PROJET_AFFICHAGE_FONCTION_VA_H

#include "affichage_struct.h"

void affichageWriteOffsetVa(affichage_struct *affichage, int offsetX, int offsetY, char *format, va_list args) {

    // setting position
    printf("\033[%d;%dH", offsetY, offsetX);

    // print body
    vfprintf(stdout, format, args);

    // flush stdout
    fflush(stdout);
}

#endif //LO41_PROJET_AFFICHAGE_FONCTION_VA_H
