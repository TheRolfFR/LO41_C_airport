//
// Created by TheRolf on 31/05/2020.
//

#ifndef LO41_PROJET_MUTEXAVIONSLIBERERAVION_H
#define LO41_PROJET_MUTEXAVIONSLIBERERAVION_H

#include <pthread.h>
#include "mutex_avions_struct.h"

/// fonction permettant de liberer un avions à faire son action
/// \param m la structure pour les avions
void mutexAvionsLibererAvion(mutex_avions_struct *m, avion* a, bool grandPiste) {
    if(m == NULL || a->numero < 0 || a->numero >= NB_AVIONS)
        return;

    // on attend l'accès à la ressource
    pthread_mutex_lock(&m->mutex);

    // on libère l'avions en envoyant le signal
    pthread_cond_signal(&m->conditionsAvion[a->numero]);

    // on unlock l'acces au mutex
    pthread_mutex_unlock(&m->mutex);
}

#endif //LO41_PROJET_MUTEXAVIONSLIBERERAVION_H
