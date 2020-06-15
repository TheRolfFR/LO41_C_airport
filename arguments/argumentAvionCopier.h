//
// Created by therolf on 15/06/2020.
//

#ifndef LO41_PROJET_ARGUMENTAVIONCOPIER_H
#define LO41_PROJET_ARGUMENTAVIONCOPIER_H

#include "argument_thread_avion.h"

void argumentAvionCopier(argument_thread_avion *source, argument_thread_avion *destination) {
    destination->argumentsThread = source->argumentsThread;
}

#endif //LO41_PROJET_ARGUMENTAVIONCOPIER_H
