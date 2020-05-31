#ifndef H_THREAD_STRUCT
#define H_THREAD_STRUCT

#include <pthread.h>

typedef struct s_thread
{
  pthread_t id;
  void *fonction;
} thread_struct;

#endif