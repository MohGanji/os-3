#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

using namespace std;

int get_current_thread() {
    pthread_t self;
    self = pthread_self();
    return self;
}

struct myinput {
    sem_t *s;
    int *d;
};

void *testf(void *param) {
    sem_t *sem = ((struct myinput *)param)->s;
    printf("one is waiting\n");
    sem_wait(sem);
    printf("one is IN\n");
    int *x_ptr = ((struct myinput *)param)->d;
    while (++(*x_ptr) < 10) {
        printf("in thread one x is : %d\n", *x_ptr);
    }
    printf("one is DONE\n");
    sem_post(sem);
}
void *testf1(void *param) {
    sem_t *sem = ((struct myinput *)param)->s;
    printf("two is waiting\n");
    sem_wait(sem);
    printf("two is IN\n");
    int *x_ptr = ((struct myinput *)param)->d;
    while (++(*x_ptr) < 20) {
        printf("in thread two x is : %d\n", *x_ptr);
    }
    printf("two is DONE\n");
    sem_post(sem);
}

int main() {
    int x = 0, y = 0;
    sem_t sem;
    if (sem_init(&sem, 0, 1) != 0) {
        fprintf(stderr, "Error creating semaphore\n");
        return 1;
    }

    struct myinput jallal = {&sem, &x};

    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, testf, &jallal)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }
    if (pthread_create(&t2, NULL, testf1, &jallal)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    if (pthread_join(t1, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }
    if (pthread_join(t2, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }
    cout << "Final x is : " << x << endl;
    return 0;
}