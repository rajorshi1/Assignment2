#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>

int main() {
    pid_t c1;
    clock_t t;
    t = clock();
    c1 = fork();
    if (c1 == 0) {
        struct sched_param param;
        int pid_num = 0;
        sched_setscheduler(pid_num, SCHED_OTHER, &param);
        execl("bash compile.sh", NULL);
        exit(0);
    }
    else if (c1 > 0) {
        waitpid(0, NULL, 0);
    }
    else {
        printf("Error in forking");
    }
    t = clock() - t;
    float time_taken = ((float)t)/CLOCKS_PER_SEC;
    printf("Time taken in SCHED_OTHER: %f\n", time_taken);
    pid_t c2;
    t = clock();
    c2 = fork();
    if (c2 == 0) {
        struct sched_param param;
        int pid_num = 0;
        sched_setscheduler(pid_num, SCHED_FIFO, &param);
        execl("bash compile.sh", NULL);
        exit(0);
    }
    else if (c2 > 0) {
        waitpid(0, NULL, 0);
    }
    else {
        printf("Error in forking");
    }
    t = clock() - t;
    float time_taken = ((float)t)/CLOCKS_PER_SEC;
    printf("Time taken in SCHED_FIFO: %f\n", time_taken);
    pid_t c3;
    t = clock();
    c3 = fork();
    if (c3 == 0) {
        struct sched_param param;
        int pid_num = 0;
        sched_setscheduler(pid_num, SCHED_RR, &param);
        clock_t t;
        t = clock();
        execl("bash compile.sh", NULL);
        t = clock() - t;
        float time_taken = ((float)t)/CLOCKS_PER_SEC;
        printf("Time taken in SCHED_RR: %f\n", time_taken);
        exit(0);
    }
    else if (c1 > 0) {
        waitpid(0, NULL, 0);
    }
    else {
        printf("Error in forking");
    }
    t = clock() - t;
    float time_taken = ((float)t)/CLOCKS_PER_SEC;
    printf("Time taken in SCHED_RR: %f\n", time_taken);
}
