#ifndef __OUTPUT_NEURON__
#define __OUTPUT_NEURON__

#include "Neuron.h"
#include "NeuronData.h"

class OutputNeuron : public Neuron {
  public:
    OutputNeuron(Semaphore *next_sem, Semaphore *prev_sem)
        : Neuron(next_sem, prev_sem) {}

    virtual void *action(NeuronData *nd);

  private:
};

#endif