#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>

void * countA() {
    struct sched_param param;
    int pid_num = 0;
    sched_setscheduler(pid_num, SCHED_OTHER, &param);
    clock_t t;
    t = clock();
    unsigned int x = pow(2,32);
    unsigned int i = 0;
    while (i<x) {
        i++;
    }
    t = clock() - t;
    float time_taken = ((float)t)/CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_taken);
    return NULL;
}

void * countB() {
    struct sched_param param;
    int pid_num = 0;
    sched_setscheduler(pid_num, SCHED_FIFO, &param);
    clock_t t;
    t = clock();
    unsigned int x = pow(2,32);
    unsigned int i = 0;
    while (i<x) {
        i++;
    }
    t = clock() - t;
    float time_taken = ((float)t)/CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_taken);
    return NULL;
}

void * countC() {
    struct sched_param param;
    int pid_num = 0;
    sched_setscheduler(pid_num, SCHED_RR, &param);
    clock_t t;
    t = clock();
    unsigned int x = pow(2,32);
    unsigned int i = 0;
    while (i<x) {
        i++;
    }
    t = clock() - t;
    float time_taken = ((float)t)/CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_taken);
    return NULL;
}

int main() {
    pthread_t ThrA;
    pthread_t ThrB;
    pthread_t ThrC;
    pthread_create(&ThrA, NULL, &countA, NULL);
    pthread_create(&ThrB, NULL, &countB, NULL);
    pthread_create(&ThrC, NULL, &countC, NULL);
    pthread_join(ThrA, NULL);
    pthread_join(ThrB, NULL);
    pthread_join(ThrC, NULL);
    pthread_exit(NULL);
    return 0;
}