#ifndef H_ATT_THREAD
#define H_ATT_THREAD

#include <pthread.h>
#include "thread_struct.h"

void threadAttendre(thread_struct *t)
{
  pthread_join(t->id, NULL);
}

#endif