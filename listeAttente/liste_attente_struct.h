//
// Created by TheRolf on 31/05/2020.
//

#ifndef LO41_PROJET_LISTE_ATTENTE_STRUCT_H
#define LO41_PROJET_LISTE_ATTENTE_STRUCT_H

#include "../avion/avion.h"

typedef struct s_la{
    avion *a;
    struct s_la *precedent;
    struct s_la *suivant;
} liste_attente_struct;

#endif //LO41_PROJET_LISTE_ATTENTE_STRUCT_H
