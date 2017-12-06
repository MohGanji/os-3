#include "utils.h"

using namespace std;

int main() {
    Thread t1, t2;
    Neuron n1;
    if (createThread(&t1, &n1)) {
        cerr << "Failed to create thread 1" << endl;
    }
    if (createThread(&t2, &n1)) {
        cerr << "Failed to create thread 2" << endl;
    }
    if (pthread_join(t1, NULL)) {
        cerr << "join failed 1" << endl;
    }
    if (pthread_join(t2, NULL)) {
        cerr << "join failed 2" << endl;
    }
    return 0;
}