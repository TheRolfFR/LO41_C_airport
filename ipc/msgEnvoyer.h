//
// Created by TheRolf on 31/05/2020.
//

#ifndef LO41_PROJET_MSGENVOYER_H
#define LO41_PROJET_MSGENVOYER_H

#include <sys/msg.h>
#include <stddef.h>

/// fonction claire d'envoi' de messages ipc
/// \param idFileMessage l'id de la file de messages
/// \param pointeurMessage le pointeur vers le message recepteur
/// \param tailleMessage la taille du message (moins long)
/// \return -1 si il y a une erreur
int msgEnvoyer(int idFileMessage, void* pointeurMessage, size_t tailleMessage) {
    return msgsnd(idFileMessage, &pointeurMessage, tailleMessage,0);
}

#endif //LO41_PROJET_MSGENVOYER_H
