#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>

void * countA() {
    struct sched_param param;
    param.sched_priority = 0;
    int pid_num = 0;
    sched_setscheduler(pid_num, SCHED_OTHER, &param);
    struct timespec before;
    clock_gettime(CLOCK_MONOTONIC, &before);
    unsigned long x =  4294967296UL;
    unsigned long i = 0;
    while (i<x) {
        i++;
    }
    struct timespec after;
    clock_gettime(CLOCK_MONOTONIC, &after);
    int time1 = (before.tv_sec * 1000000000) + before.tv_nsec;
    int time2 = (after.tv_sec * 1000000000) + after.tv_nsec;
    float time_taken = (time2 - time1)/1000000000;
    printf("Time taken in SCHED_OTHER: %f\n", time_taken);
    return NULL;
}

void * countB() {
    struct sched_param param;
    param.sched_priority = 99;
    int pid_num = 0;
    sched_setscheduler(pid_num, SCHED_FIFO, &param);
    struct timespec before;
    clock_gettime(CLOCK_MONOTONIC, &before);
    unsigned long x =  4294967296UL;
    unsigned long i = 0;
    while (i<x) {
        i++;
    }
    struct timespec after;
    clock_gettime(CLOCK_MONOTONIC, &after);
    int time1 = (before.tv_sec * 1000000000) + before.tv_nsec;
    int time2 = (after.tv_sec * 1000000000) + after.tv_nsec;
    float time_taken = (time2 - time1)/1000000000;
    printf("Time taken in SCHED_FIFO: %f\n", time_taken);
    return NULL;
}

void * countC() {
    struct sched_param param;
    param.sched_priority = 99;
    int pid_num = 0;
    sched_setscheduler(pid_num, SCHED_RR, &param);
    struct timespec before;
    clock_gettime(CLOCK_MONOTONIC, &before);
    unsigned long x =  4294967296UL;
    unsigned long i = 0;
    while (i<x) {
        i++;
    }
    struct timespec after;
    clock_gettime(CLOCK_MONOTONIC, &after);
    int time1 = (before.tv_sec * 1000000000) + before.tv_nsec;
    int time2 = (after.tv_sec * 1000000000) + after.tv_nsec;
    float time_taken = (time2 - time1)/1000000000;
    printf("Time taken in SCHED_RR: %f\n", time_taken);
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
