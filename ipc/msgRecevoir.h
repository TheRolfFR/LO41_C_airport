//
// Created by TheRolf on 31/05/2020.
//

#ifndef LO41_PROJET_MSGRECEVOIR_H
#define LO41_PROJET_MSGRECEVOIR_H

#include <sys/msg.h>
#include <stddef.h>

/// fonction claire de réception de messages ipc
/// \param idFileMessage l'id de la file de messages
/// \param pointeurMessage le pointeur vers le message recepteur
/// \param tailleMessage la taille du message (moins long)
/// \param typeMessage le type du message à recevoir
/// \return -1 si il y a une erreur
int msgRecevoir(int idFileMessage, void *pointeurMessage, int tailleMessage, long typeMessage) {
    return msgrcv(idFileMessage, &pointeurMessage, tailleMessage, typeMessage, 0);
}

#endif //LO41_PROJET_MSGRECEVOIR_H
