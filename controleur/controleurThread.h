//
// Created by TheRolf on 31/05/2020.
//

#ifndef LO41_PROJET_CONTROLEURTHREAD_H
#define LO41_PROJET_CONTROLEURTHREAD_H

#include "../avion/avion.h"
#include "../constantes.h"
#include "../piste/piste.h"
#include "../arguments/argument_thread_struct.h"
#include "../ipc/msgAvions.h"
#include "../ipc/msgRecevoir.h"
#include "../listeAttente/liste_attente_struct.h"
#include "../listeAttente/listeAttenteCreer.h"
#include "../piste/pisteOcupee.h"
#include "../mutex/avions/mutexAvionsLibererAvion.h"
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

    // on doit créer un tableau d'avions
    // attention: la liste d'avions est différente des deux listes d'attentes pour les pistesz
    avion *tableauAvions[NB_AVIONS];

    /*
     * on ne le vide pas car on s'en fiche totalement
     * cependant on va attendre d'avoir tous les avions avant de pouvoir continuer
     */
    msg_avion msgAvion;
    for(int i = 0; i < NB_AVIONS; ++i) {
        // attente de messages IPC et ajout des avions à la liste
        msgRecevoir(arguments->idFileMsgAvions, &msgAvion, MSG_AVIONS_TYPE);

        // ajout des nouveaux avions à la liste
        tableauAvions[i] = msgAvion.a;
    }

    /*
     * On doit aussi avoir des références aux pistes et pour les controler
     */
    // ajout de pistes
    initialiserPiste(&arguments->mesPistes[0], true);
    initialiserPiste(&arguments->mesPistes[1], false);

    // on doit creer nos deux listes d'attente
    liste_attente_struct listeAttenteGrandePiste[NB_AVIONS];
    liste_attente_struct listeAttentePetitePiste[NB_AVIONS];
    listeAttenteCreer(listeAttenteGrandePiste);
    listeAttenteCreer(listeAttentePetitePiste);

    // on doit faire une première génération du planning


    // "enfin" on peut lancer la boucle infinie qui lancera la gestion des pistes
    while(true) {
        // on attend l'évènement de libération d'une piste QUELCONQUE, bref d'une action d'avion quelconque
        pthread_cond_wait(&arguments->mutexAvions.avionQuelconque, &arguments->mutexAvions.mutex);

        // on revoit la génération du planning
        // pour les deux pistes

        // on réalise des actions sur les pistes

        // tu débloques le mutex
        pthread_mutex_unlock(&arguments->mutexAvions.mutex);

        // grande piste
        if(pisteEstOccupee(&arguments->mesPistes[0])) {
            arguments->mesPistes[0].avionEnCours = listeAttenteGrandePiste[0].a;
            afficherPiste(&arguments->mesPistes[0]);
            mutexAvionsLibererAvion(&arguments->mutexAvions, listeAttenteGrandePiste[0].a->numero);
        }

        // petite piste
        if(pisteEstOccupee(&arguments->mesPistes[1])) {
            arguments->mesPistes[1].avionEnCours = listeAttenteGrandePiste[1].a;
            afficherPiste(&arguments->mesPistes[1]);
            mutexAvionsLibererAvion(&arguments->mutexAvions, listeAttenteGrandePiste[1].a->numero);
        }

        // on attend de nouveau
    }

    return NULL;
}

#endif //LO41_PROJET_CONTROLEURTHREAD_H
