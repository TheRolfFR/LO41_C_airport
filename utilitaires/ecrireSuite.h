//
// Created by TheRolf on 28/05/2020.
//

#ifndef LO41_PROJET_ECRIRESUITE_H
#define LO41_PROJET_ECRIRESUITE_H

#include <stdlib.h>
#include <string.h>

// fonction permettant d'écrire à la suite d'une chaîne de caractère
int ecrireSuite(char *destination, char *chaine, int taille) {
    if(taille < 1) // il faut une taille strictement positive
        return EXIT_FAILURE;

    // sinon

    int foundIndex = -1; // l'index trouvé est négatif
    int index = 0; // on intialise l'index

    // on recherche le caractère de fin de chaine de caractère
    while(index < taille && foundIndex == -1) { // on cherche l'index
        if(*(destination + index) == '\0')
            foundIndex = index; // on donne l'inverse

        ++index;
    }

    if(foundIndex < 0 || foundIndex + strlen(chaine) > taille) { // si on a pas trouvé ou que ça rentrera pas on renvoie une erreur
        return EXIT_FAILURE;
    }

    // sinon on peut finalement remplir
    strcpy(destination + foundIndex, chaine);
    return EXIT_SUCCESS;
}

#endif //LO41_PROJET_ECRIRESUITE_H
