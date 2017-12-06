#include "InputNeuron.h"

using namespace std;

void *InputNeuron::action(NeuronData *nd) {
    // wait for ghabli
    sem_wait(_prev_sem);
    cout << "First Place" << endl;
    if (fin && !fin.is_open())
        fin.open(this->_input.c_str());
    fin >> _args[0] >> _args[1] >> _args[2];
    sem_post(_prev_sem);
    return 0;
    // signal baadi
}