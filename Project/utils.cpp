#include "utils.h"

using namespace std;

void log(string p) { cerr << p << endl; }

int createThread(Thread *t, Neuron *n, NeuronData *nd) {
    return pthread_create(t, NULL, routine, nd);
}

void *routine(void *nd) {
    return ((Neuron *)((NeuronData *)nd)->neuron)->action((NeuronData *)nd);
}