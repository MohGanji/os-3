#ifndef __NEURON__
#define __NEURON__

#include <iostream>
#include <stdio.h>

class Neuron {
  public:
    static void *routine(void *context);
    int a = 0;

  private:
    void *print();
};

#endif