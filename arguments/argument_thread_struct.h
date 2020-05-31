//
// Created by TheRolf on 31/05/2020.
//

#ifndef LO41_PROJET_ARGUMENT_THREAD_STRUCT_H
#define LO41_PROJET_ARGUMENT_THREAD_STRUCT_H

#include "../mutex/avions/mutex_avions_struct.h"
#include "../piste/piste.h"

/// arguments passés au thread : les mutex pour les avions, les mutex pour les pistes (inutile, voir mutex_pistes_struct.h pourquoi), la file de messages pour les avions
typedef struct {
    mutex_avions_struct mutexAvions;
    int idFileMsgAvions;
    piste mesPistes[2];
} argument_thread_struct;

#endif //LO41_PROJET_ARGUMENT_THREAD_STRUCT_H
