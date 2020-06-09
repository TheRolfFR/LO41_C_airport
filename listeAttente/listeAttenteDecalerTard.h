//
// Created by TheRolf on 09/06/2020.
//

#ifndef LO41_PROJET_LISTEATTENTEDECALERTARD_H
#define LO41_PROJET_LISTEATTENTEDECALERTARD_H

#include "../constantes.h"
#include "../avion/avion.h"

void listeAttenteDecalerTard(int j, avion **liste, int longueur) {
    for(int i = longueur-1; i > j; --i) {
        liste[i] = liste[i-1];
    }
}

#endif //LO41_PROJET_LISTEATTENTEDECALERTARD_H
