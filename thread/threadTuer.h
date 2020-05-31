//
// Created by TheRolf on 31/05/2020.
//

#ifndef LO41_PROJET_THREADTUER_H
#define LO41_PROJET_THREADTUER_H

#include <pthread.h>
#include "thread_struct.h"

void threadTuer(thread_struct *thread) {
    if(thread == NULL)
        return;

    pthread_cancel(thread->id);
}

#endif //LO41_PROJET_THREADTUER_H
