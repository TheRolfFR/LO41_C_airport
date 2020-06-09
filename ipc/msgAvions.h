//
// Created by TheRolf on 31/05/2020.
//

#ifndef LO41_PROJET_MSGAVIONS_H
#define LO41_PROJET_MSGAVIONS_H

#include "../avion/avion.h"

/// structure simple de messages pour les pointeurs d'avions
typedef struct {
    long type;
    avion *a;
} msg_avion;

#define MSG_AVIONS_TYPE 1
#define MSG_AVIONS_MAIN_TYPE 2
#define MSG_AVIONS_LONGUEUR (sizeof(msg_avion) - sizeof(long))

#endif //LO41_PROJET_MSGAVIONS_H
