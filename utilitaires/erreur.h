//
// Created by TheRolf on 31/05/2020.
//

#ifndef LO41_PROJET_ERREUR_H
#define LO41_PROJET_ERREUR_H

#include <stdio.h>
#include <stdlib.h>

void erreur(const char* msg) {
    perror(msg);
    exit(1);
}

#endif //LO41_PROJET_ERREUR_H
