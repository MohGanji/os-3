#include "Neuron.h"

using namespace std;

void *Neuron::routine(void *context) { return ((Neuron *)context)->print(); }

void *Neuron::print() {
    for (int i = 0; i < 100; i++) {
        this->a++;
        printf("%d\n", a);
    }
    return 0;
}