#ifndef __DEFINITIONS__
#define __DEFINITIONS__

#include <pthread.h>
#include <semaphore.h>

#define INPUTFILE "../InputFile.txt"
#define INPUT_NEURON_COUNT 3
#define HIDDEN_NEURON_COUNT 10
#define OUTPUT_NEURON_COUNT 1
typedef pthread_t Thread;
typedef sem_t Semaphore;

#endif // !1