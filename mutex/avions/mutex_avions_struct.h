//
// Created by TheRolf on 31/05/2020.
//

#ifndef LO41_PROJET_MUTEX_AVIONS_STRUCT_H
#define LO41_PROJET_MUTEX_AVIONS_STRUCT_H

#include <pthread.h>
#include "../../constantes.h"

/// Il va nous falloir créer la structure permettant de stocker tous les mutex pour controler les avions
/// (chaque avions individuellement mais aussi le mutex pour les avions en atterissage force)

typedef struct s_mutex_avions {
    pthread_mutex_t mutex;
    pthread_cond_t conditionsAvion[NB_AVIONS];
    pthread_cond_t atterissageForce;
    pthread_cond_t avionQuelconque;
} mutex_avions_struct;

#endif //LO41_PROJET_MUTEX_AVIONS_STRUCT_H
