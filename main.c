#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include "utilitaires/aleatoire.h"
#include "mutex/avions/mutex_avions_struct.h"
#include "arguments/argument_thread_struct.h"
#include "arguments/argument_thread_avion.h"
#include "tarmac/tarmacInitialiser.h"
#include "utilitaires/erreur.h"
#include "thread/thread_lib.h"
#include "avion/avionThread.h"
#include "controleur/controleurThread.h"
#include "tarmac/tarmacAfficher.h"
#include "affichage/affichage_fonction_variable.h"
#include <signal.h>

// j'ai besoin de quelques choses :

// la stucture des arguments généraux
// le mutex général est dedans mais pas besoin de l'initialiser
argument_thread_struct mesArguments;

// la structure des aguments d'avions
argument_thread_avion argumentsMonAvion;

// il nous fout des structures de thread pour les avions
thread_struct mesAvions[NB_AVIONS];

// et une structure de thread pour notre controleur
thread_struct monControleur;

// affichage
affichage_struct *teteAffichage;

void arreterFileMessages() {
    // supprimer la file de message
    if(msgctl(mesArguments.idFileMsgAvions, IPC_RMID, 0) == -1) {
        erreur("Erreur lors de la suppression de la file ");
    }
}

// on est prudent, on met un traitant pour sigint
void traitantSigint(int num) {
    if(num == SIGINT) {
        // tuer les threads
        for (int i = 0; i < NB_AVIONS; ++i) {
            threadTuer(&mesAvions[i]);
        }

        // détruire les avions
        for(int i = 0; i < NB_AVIONS; ++i) {
            avionDetruire(mesArguments.mutexAvions.mesAvions[i]);
        }

        threadTuer(&monControleur);

        arreterFileMessages();

        erreur("Terminaison programme");
    }
}

int main (int argc, char *argv[]) {
    initAleatoire(); // on initialise l'aléatoire

    // on initialiser les mutex et les conditions
    mesArguments.mutexAvions.mutex = (pthread_mutex_t) PTHREAD_MUTEX_INITIALIZER;
    mesArguments.mutexAvions.avionsPrets = (pthread_cond_t) PTHREAD_COND_INITIALIZER;
    mesArguments.mutexAvions.avionQuelconque = (pthread_cond_t) PTHREAD_COND_INITIALIZER;
    for(int i = 0; i < NB_AVIONS; ++i) {
        mesArguments.mutexAvions.conditionsAvion[i] = (pthread_cond_t) PTHREAD_COND_INITIALIZER;
    }
    mesArguments.mutexAvions.atterissageForce = (pthread_cond_t) PTHREAD_COND_INITIALIZER;
    mesArguments.mutexAvions.nbAvionsPrets = 0;

    // initialiser les arguments généraux
    tarmacInitialiser(&mesArguments.monTarmac);

    // initialiser mes pistes
    pisteInitialiser(&mesArguments.mesPistes[0], true);
    pisteInitialiser(&mesArguments.mesPistes[1], false);

    // on ajoute les pistes à l'affichage
    affichageAjouter(&teteAffichage, &mesArguments.mesPistes[0].affichage);
    affichageAjouter(&teteAffichage, &mesArguments.mesPistes[1].affichage);

    // on ajoute le tarmac à l'affichage
    affichageAjouter(&teteAffichage, &mesArguments.monTarmac.affichage);

    // on affiche nos pistes et notre tarmac
    affichageNettoyerEcran();
    pisteAfficher(&mesArguments.mesPistes[0]);
    pisteAfficher(&mesArguments.mesPistes[1]);
    tarmacAfficher(&mesArguments.monTarmac);

    // on met les arguments généraux dans les arguments pour les avions
    argumentsMonAvion.argumentsThread = &mesArguments;

    // démarrer tous les threads des avions
    for(int i = 0; i < NB_AVIONS; ++i) {
        mesAvions[i].fonction = avionThread;
        argumentsMonAvion.index = i;
        lancerThread(&mesAvions[i], (void *) &argumentsMonAvion);
    }

    // démarrer le thread du contrôleur
    monControleur.fonction = controleurThread;
    lancerThread(&monControleur, (void *) &mesArguments);

    // attendre tous les threads
    for(int i = 0; i < NB_AVIONS; ++i) {
        threadAttendre(&mesAvions[i]);
    }
    threadAttendre(&monControleur);

    arreterFileMessages();

    return EXIT_SUCCESS;
}
