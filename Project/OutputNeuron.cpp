#include "OutputNeuron.h"

using namespace std;

void *OutputNeuron::action(struct NeuronData *nd) {
    sem_wait(_prev_sem);
    cout << "Second Place" << endl;
    vector<double> args = nd->inputNeuron->getArgs();
    printf("%lf %lf %lf\n", args[0], args[1], args[2]);
    sem_post(_prev_sem);
    return 0;
}