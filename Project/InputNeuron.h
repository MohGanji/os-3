#ifndef __INPUTNEURON__
#define __INPUTNEURON__

#include "Neuron.h"
#include <fstream>
#include <string>
#include <vector>

class InputNeuron : public Neuron {
  public:
    InputNeuron(std::string inputFile, Semaphore *next_sem, Semaphore *prev_sem)
        : Neuron(next_sem, prev_sem), _input(inputFile) {
        _args.push_back(0);
        _args.push_back(0);
        _args.push_back(0);
    }
    std::vector<double> getArgs() { return _args; }

  private:
    std::ifstream fin;
    std::string _input;
    std::vector<double> _args;

    virtual void *action(NeuronData *nd);
};

#endif
