//
// Created by TheRolf on 31/05/2020.
//

#ifndef LO41_PROJET_AVIONTHREAD_H
#define LO41_PROJET_AVIONTHREAD_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "avion.h"
#include "avionCreer.h"
#include "../arguments/argument_thread_avion.h"
#include "avionChangerDirection.h"
#include "../tarmac/tarmacAjouterAvion.h"
#include "../tarmac/tarmacSupprimerAvion.h"

/// Thread de "l'avion", doit être capapble de tout gérer
/// tourne à l'infini
/// \param arg arguments passés au thread : les mutex pour les avions, les mutex pour les pistes (inutile, voir mutex_pistes_struct.h pourquoi), la file de messages pour les avions
/// \return je ne sais pas encore
void *avionThread(void *arg) {

    // décodage des arguments
    argument_thread_avion *arguments = (argument_thread_avion *) arg;
    argument_thread_struct *argumentsThread = arguments->argumentsThread;

    pthread_mutex_t* mutex = &argumentsThread->mutexAvions.mutex;


    // on attend l'accès à la ressource
    pthread_mutex_lock(mutex);

    int index = arguments->index;

    avion *a = avionCreer(index);
    argumentsThread->mutexAvions.mesAvions[index] = a;
    argumentsThread->mutexAvions.nbAvionsPrets++;
    pthread_mutex_unlock(mutex);

    // boucle infinie de l'avion
    while (true) {
        // en premier on attend d'être autorisé
        pthread_mutex_lock(mutex);
        pthread_cond_wait(&argumentsThread->mutexAvions.conditionsAvion[index], mutex);

        // faire l'action (décollage / atterrissage)
        sleep(ACTION_DUREE);

        if(a->estArrivant) {
            tarmacAjouterAvion(&argumentsThread->monTarmac, a);
        } else {
            tarmacSupprimerAvion(&argumentsThread->monTarmac, a);
        }

        // on change la direction
        avionChangerDirection(a);

        // on envoie le dernier avion modifie
        pthread_cond_signal(&argumentsThread->mutexAvions.avionQuelconque);

        // on libère la ressource critique
        pthread_mutex_unlock(mutex);
    }

    avionDetruire(a);

    return NULL;
}

#endif //LO41_PROJET_AVIONTHREAD_H
