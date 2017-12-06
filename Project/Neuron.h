#ifndef __NEURON__
#define __NEURON__

#include "Definitions.h"
#include <iostream>
#include <stdio.h>
#include <vector>

struct NeuronData;

class Neuron {
  public:
    Neuron(Semaphore *prev_sem, Semaphore *next_sem)
        : _next_sem(next_sem), _prev_sem(prev_sem) {}

    virtual void *action(NeuronData *nd) = 0;

  protected:
    Semaphore *_prev_sem, *_next_sem;

  private:
};

#endif