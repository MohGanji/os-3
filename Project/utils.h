#ifndef __utils__
#define __utils__

#include "Neuron.h"
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <string>

typedef pthread_t Thread;
typedef sem_t Semaphore;

void log(std::string);
int createThread(Thread *t, Neuron *n);

#endif