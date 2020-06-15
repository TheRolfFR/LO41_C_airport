//
// Created by TheRolf on 09/06/2020.
//

#ifndef LO41_PROJET_LISTEATTENTEDECALERTOT_H
#define LO41_PROJET_LISTEATTENTEDECALERTOT_H

#include "../constantes.h"
#include "../avion/avion.h"

void listeAttenteDecalerTot(int j, avion **liste, int longueur) {
    int nul = -1;
    for(int i = j; i < longueur-1; ++i) {
        liste[i] = liste[i+1];

        if(nul == -1 && liste[i] == NULL) {
            nul = i;
        }
    }
    liste[nul] = NULL;
}

#endif //LO41_PROJET_LISTEATTENTEDECALERTOT_H
