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
        msg_avion msgAvion;
        for(int i = 0; i < NB_AVIONS; ++i) {
            msgRecevoir(mesArguments.idFileMsgAvions, &msgAvion, MSG_AVIONS_LONGUEUR, MSG_AVIONS_MAIN_TYPE);
            avionDetruire(msgAvion.a);
        }

        threadTuer(&monControleur);

        arreterFileMessages();

        erreur("Terminaison programme");
    }
}

int main (int argc, char *argv[]) {
    initAleatoire(); // on initialise l'aléatoire

    // tenter de générer une file de messages
    if((mesArguments.idFileMsgAvions = msgget(ftok(argv[0], 'S'), IPC_CREAT | 0600)) == -1)
        erreur("Erreur lors de la création de la file de message.");

    // initialiser les arguments généraux
    tarmacInitialiser(&mesArguments.monTarmac);

    // initialiser mes pistes
    pisteInitialiser(&mesArguments.mesPistes[0], true);
    pisteInitialiser(&mesArguments.mesPistes[1], false);

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
