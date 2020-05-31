//
// Created by TheRolf on 31/05/2020.
//


#ifndef LO41_PROJET_MUTEXAVIONSINITIALISER_H
#define LO41_PROJET_MUTEXAVIONSINITIALISER_H

#include "mutex_avions_struct.h"
#include <pthread.h>

/// fonction permettant l'initialisation de la structure de données pour les avions
/// \param m la structure pour les avions
void mutexAvionsInitialiser(mutex_avions_struct *m) {
    if(m == NULL)
        return;

    // on libère l'accès au mutex
    pthread_mutex_unlock(&m->mutex);
}

#endif //LO41_PROJET_MUTEXAVIONSINITIALISER_H
