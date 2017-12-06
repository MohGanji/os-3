#include "InputNeuron.h"
#include "OutputNeuron.h"
#include "utils.h"

using namespace std;

int main() {
    // semaphores
    Semaphore sem1, sem2;
    if (sem_init(&sem1, 0, 1)) {
        cout << "Failed to initialize first semaphore" << endl;
    }
    if (sem_init(&sem2, 0, 1)) {
        cout << "Failed to initialize Second semaphore" << endl;
    }

    // input layer init
    Thread inputThread;
    InputNeuron *inputNeuron;

    struct NeuronData inputNd;

    // hidden layer init

    // output layer init
    Thread outputThread;
    OutputNeuron *outputNeuron;
    struct NeuronData outputNd;

    // input layer action
    inputNeuron = new InputNeuron(INPUTFILE, &sem1, &sem2);
    inputNd.neuron = inputNeuron;
    if (createThread(&inputThread, inputNeuron, &inputNd)) {
        cerr << "Failed to create input thread" << endl;
    }

    // hidden layer action

    // output layer action
    outputNeuron = new OutputNeuron(&sem1, &sem2);
    outputNd.neuron = outputNeuron;
    outputNd.inputNeuron = inputNeuron;

    if (createThread(&outputThread, outputNeuron, &outputNd)) {
        cerr << "Failed to create output thread" << endl;
    }

    // join threads to avoid segmentation fault
    if (pthread_join(inputThread, NULL)) {
        cerr << "Failed to join input thread" << endl;
    }
    if (pthread_join(outputThread, NULL)) {
        cerr << "Failed to join output thread" << endl;
    }

    return 0;
}