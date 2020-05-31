#ifndef H_LANCER_THREAD
#define H_LANCER_THREAD

#include <pthread.h>
#include "thread_struct.h"

int lancerThread(thread_struct *t, void *arg)
{
  return pthread_create(&t->id, 0, (void *(*)())t->fonction, arg);
}

#endif