//
// Created by TheRolf on 31/05/2020.
//

#ifndef LO41_PROJET_CONTROLEURTHREAD_H
#define LO41_PROJET_CONTROLEURTHREAD_H

#include "../avion/avion.h"
#include "../constantes.h"
#include "../piste/piste.h"
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
     */

    // on doit créer un tableau d'avions
    // attention: la liste d'avions est différente des deux listes d'attentes pour les pistesz
    avion *tableauAvions[NB_AVIONS];

    /*
     * on ne le vide pas car on s'en fiche totalement
     * cependant on va attendre d'avoir tous les avions avant de pouvoir continuer
     */
    for(int i = 0; i < NB_AVIONS; ++i) {
        // attente de messages IPC et ajout des avions à la liste

        // ajout des nouveaux avions à la liste
    }

    /*
     * On doit aussi avoir des références aux pistes et pour les controler
     */
    // ajout de pistes
    piste mesPistes[2];
    initialiserPiste(&mesPistes[0], true);
    initialiserPiste(&mesPistes[1], false);

    // on doit creer nos deux listes d'attente

    // on doit faire une première génération du planning


    // "enfin" on peut lancer la boucle infinie qui lancera la gestion des pistes
    while(true) {
        // on attend l'évènement de libération d'une piste QUELCONQUE, bref d'une action d'avion quelconque

        // on revoit la génération du planning

        // on réalise des actions sur les pistes

        // on attend de nouveau
    }

    return NULL;
}

#endif //LO41_PROJET_CONTROLEURTHREAD_H
