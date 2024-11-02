#include <semaphore.h> // POSIX semaphore library
#include <pthread.h>
#include <queue>

#ifndef SHARED_BUFFER_H
#define SHARED_BUFFER_H
#define BUFFER_SIZE 2

extern std::queue<int> buffer;
extern pthread_mutex_t mutex;
extern pthread_cond_t buffer_not_full;
extern pthread_cond_t buffer_not_empty;

#endif