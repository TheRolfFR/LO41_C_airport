//
// Created by TheRolf on 31/05/2020.
//

#ifndef LO41_PROJET_CONTROLEURTHREAD_H
#define LO41_PROJET_CONTROLEURTHREAD_H

#include "../avion/avion.h"
#include "../constantes.h"
#include "../piste/piste.h"
#include "../arguments/argument_thread_struct.h"
#include "../listeAttente/liste_attente_struct.h"
#include "../listeAttente/listeAttenteCreer.h"
#include "../piste/pisteOcupee.h"
#include "../mutex/avions/mutexAvionsLibererAvion.h"
#include "../listeAttente/premiereGeneration.h"
#include "../listeAttente/mettreAJour.h"
#include <pthread.h>

/// Thread du controleur, doit être capapble de tout gérer
/// tourne à l'infini
/// \param arg arguments passés au thread : les mutex pour les avions, les mutex pour les pistes (inutile, voir mutex_pistes_struct.h pourquoi), la file de messages pour les avions
/// \return je ne sais pas encore
void *controleurThread(void* arg) {
    /* on décode les arguments contenant :
     * - les mutex pour controler les avions (chaque avions individuellement mais aussi le mutex pour les avions en atterissage force)
     * - les mutex pour controler les pistes (inutile, voir mutex_pistes_struct.h pourquoi)
     * - l'id de la file de message pour récupérer les avions
     * - les pistes
     */
    argument_thread_struct *arguments = (argument_thread_struct *) arg;
    pthread_mutex_t* mutex = &arguments->mutexAvions.mutex;

    // pas besoin de créer un tableau d'avions, on attend jusque qu'il se remplisse
    /*
     * on ne le vide pas car on s'en fiche totalement
     * cependant on va attendre d'avoir tous les avions avant de pouvoir continuer
     */

    // on attend d'avoir la ressource critique
    pthread_mutex_lock(mutex);

    /*
     * On doit aussi avoir des références aux pistes et pour les controler
     */
    // ajout de pistes
    pisteInitialiser(&arguments->mesPistes[0], true);
    pisteInitialiser(&arguments->mesPistes[1], false);

    // on doit creer nos deux listes d'attente
    avion* listeAttenteGrandePiste[NB_AVIONS];
    avion* listeAttentePetitePiste[NB_AVIONS];
    listeAttenteCreer(listeAttenteGrandePiste);
    listeAttenteCreer(listeAttentePetitePiste);

    pthread_mutex_unlock(mutex);

    int compteur;
    while(compteur != NB_AVIONS) {
        pthread_mutex_lock(mutex);

        compteur = arguments->mutexAvions.nbAvionsPrets;

        pthread_mutex_unlock(mutex);
    }

    pthread_mutex_lock(mutex);

    // on doit faire une première génération du planning
    premiereGeneration(listeAttenteGrandePiste, listeAttentePetitePiste, arguments->mutexAvions.mesAvions);

    // printf("Première génération terminée\n");fflush(stdout);

    // PREMIERS LANCEMENTS

    // grande piste
    if(!pisteEstOccupee(&arguments->mesPistes[0]) && listeAttenteGrandePiste[0] != NULL) {
        arguments->mesPistes[0].avionEnCours = listeAttenteGrandePiste[0];
        pisteAfficher(&arguments->mesPistes[0]);

        pthread_mutex_unlock(mutex);
        mutexAvionsLibererAvion(&arguments->mutexAvions, listeAttenteGrandePiste[0], true);
        pthread_mutex_lock(mutex);
    }

    // petite piste
    if(!pisteEstOccupee(&arguments->mesPistes[1]) && listeAttentePetitePiste[0] != NULL) {
        arguments->mesPistes[1].avionEnCours = listeAttentePetitePiste[0];
        pisteAfficher(&arguments->mesPistes[1]);

        pthread_mutex_unlock(mutex);
        mutexAvionsLibererAvion(&arguments->mutexAvions, listeAttentePetitePiste[0], false);
        pthread_mutex_lock(mutex);
    }

    // "enfin" on peut lancer la boucle infinie qui lancera la gestion des pistes
    while(true) {
        // on attend l'évènement de libération d'une piste QUELCONQUE, bref d'une action d'UN avion quelconque
        // ET D'UN SEUL, et il faudrait savoir lequel qu'on le retraite
        pthread_cond_wait(&arguments->mutexAvions.avionQuelconque, &arguments->mutexAvions.mutex);

        // on revoit la génération du planning
        // pour les deux pistes
        // C'EST UN SEUL A LA FOIS PAS PLUS
        // on réalise des actions sur 1 piste

        // grande piste
        if(arguments->mutexAvions.dernierAvionModifieGrandePiste != NULL && !pisteEstOccupee(&arguments->mesPistes[0]) && listeAttenteGrandePiste[0] != NULL) {
            mettreAJour(listeAttenteGrandePiste, listeAttentePetitePiste, arguments->mutexAvions.dernierAvionModifieGrandePiste);
            arguments->mutexAvions.dernierAvionModifieGrandePiste = NULL;

            arguments->mesPistes[0].avionEnCours = listeAttenteGrandePiste[0];
            pisteAfficher(&arguments->mesPistes[0]);

            pthread_mutex_unlock(mutex);
            mutexAvionsLibererAvion(&arguments->mutexAvions, listeAttenteGrandePiste[0], true);
            pthread_mutex_lock(mutex);
        } else if(arguments->mutexAvions.dernierAvionModifiePetitePiste != NULL && !pisteEstOccupee(&arguments->mesPistes[1]) && listeAttentePetitePiste[0] != NULL) {
            mettreAJour(listeAttenteGrandePiste, listeAttentePetitePiste, arguments->mutexAvions.dernierAvionModifiePetitePiste);
            arguments->mutexAvions.dernierAvionModifiePetitePiste = NULL;

            arguments->mesPistes[1].avionEnCours = listeAttentePetitePiste[0];
            pisteAfficher(&arguments->mesPistes[1]);

            pthread_mutex_unlock(mutex);
            mutexAvionsLibererAvion(&arguments->mutexAvions, listeAttentePetitePiste[0], false);
            pthread_mutex_lock(mutex);
        }

        // on attend de nouveau
    }

    return NULL;
}

#endif //LO41_PROJET_CONTROLEURTHREAD_H
