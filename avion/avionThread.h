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
#include "../ipc/msgEnvoyer.h"
#include "../ipc/msgAvions.h"
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

    avion *a = avionCreer(arguments->index);

    msg_avion msgAvion = { MSG_AVIONS_TYPE, a };
    msgEnvoyer(argumentsThread->idFileMsgAvions, &msgAvion, MSG_AVIONS_LONGUEUR);

    // boucle infinie de l'avion
    while (true) {
        // en premier on attend d'être autorisé
        pthread_cond_wait(&argumentsThread->mutexAvions.conditionsAvion[arguments->index], &argumentsThread->mutexAvions.mutex);

        // faire l'action (décollage / atterrissage)
        sleep(ACTION_DUREE);

        if(a->estArrivant) {
            tarmacAjouterAvion(&argumentsThread->monTarmac);
        } else {
            tarmacSupprimerAvion(&argumentsThread->monTarmac);
        }

        // on change la direction
        avionChangerDirection(a);
    }

    return NULL;
}

#endif //LO41_PROJET_AVIONTHREAD_H
