#ifndef __utils__
#define __utils__

#include "Definitions.h"
#include "Neuron.h"
#include "NeuronData.h"
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <string>
#include <vector>

void log(std::string);
int createThread(Thread *t, Neuron *n, NeuronData *nd);
void *routine(void *nd);

#endif