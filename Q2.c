#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>
#include <sys/resource.h>
#include <sys/time.h>

float times[3];

int main() {
    pid_t c1;
    pid_t c2;
    pid_t c3;
    struct timespec before1;
    struct timespec before2;
    struct timespec before3;
    struct timespec buffer;
    struct timespec after1;
    struct timespec after2;
    struct timespec after3;
    clock_gettime(CLOCK_MONOTONIC,&before1);
    c1 = fork();
    if (c1 == 0) {
        setpriority(0, PRIO_PROCESS, 1);
        execl("/bin/sh","sh","compile.sh", (char *) NULL);
        exit(0);
    }
    else {
        printf("Error in forking");
    }
    clock_gettime(CLOCK_MONOTONIC,&before2);
    c2 = fork();
    if (c2 == 0) {
        setpriority(0, PRIO_PROCESS,20);
        execl("/bin/sh","sh","compile.sh", (char *) NULL);
        exit(0);
    }
    else {
        printf("Error in forking");
    }
    clock_gettime(CLOCK_MONOTONIC,&before3);
    c3 = fork();
    if (c3 == 0) {
        setpriority(0, PRIO_PROCESS, 40);
        execl("/bin/sh","sh","compile.sh", (char *) NULL);
        exit(0);
    }
    else {
        printf("Error in forking");
    }
    pid_t nig = wait(NULL);
    clock_gettime(CLOCK_MONOTONIC,&buffer);
    if (nig == c1) {
        clock_gettime(CLOCK_MONOTONIC, &after1);
        unsigned long time1 = (before1.tv_sec * 1000000000) + before1.tv_nsec;
        unsigned long time2 = (buffer.tv_sec * 1000000000) + buffer.tv_nsec;
        float time_taken = ((float)(time2 - time1))/1000000000;
        times[0] = time_taken;
    }
    else if (nig == c2)  {
        clock_gettime(CLOCK_MONOTONIC, &after1);
        unsigned long time1 = (before2.tv_sec * 1000000000) + before2.tv_nsec;
        unsigned long time2 = (buffer.tv_sec * 1000000000) + buffer.tv_nsec;
        float time_taken = ((float)(time2 - time1))/1000000000;
        times[1] = time_taken;
    }
    else if (nig == c3) {
        clock_gettime(CLOCK_MONOTONIC, &after1);
        unsigned long time1 = (before3.tv_sec * 1000000000) + before3.tv_nsec;
        unsigned long time2 = (buffer.tv_sec * 1000000000) + buffer.tv_nsec;
        float time_taken = ((float)(time2 - time1))/1000000000;
        times[2] = time_taken;
    }
    nig = wait(NULL);
    clock_gettime(CLOCK_MONOTONIC,&buffer);
    if (nig == c1) {
        clock_gettime(CLOCK_MONOTONIC, &after1);
        unsigned long time1 = (before1.tv_sec * 1000000000) + before1.tv_nsec;
        unsigned long time2 = (buffer.tv_sec * 1000000000) + buffer.tv_nsec;
        float time_taken = ((float)(time2 - time1))/1000000000;
        times[0] = time_taken;
    }
    else if (nig == c2)  {
        clock_gettime(CLOCK_MONOTONIC, &after1);
        unsigned long time1 = (before2.tv_sec * 1000000000) + before2.tv_nsec;
        unsigned long time2 = (buffer.tv_sec * 1000000000) + buffer.tv_nsec;
        float time_taken = ((float)(time2 - time1))/1000000000;
        times[1] = time_taken;
    }
    else if (nig == c3) {
        clock_gettime(CLOCK_MONOTONIC, &after1);
        unsigned long time1 = (before3.tv_sec * 1000000000) + before3.tv_nsec;
        unsigned long time2 = (buffer.tv_sec * 1000000000) + buffer.tv_nsec;
        float time_taken = ((float)(time2 - time1))/1000000000;
        times[2] = time_taken;
    }
    nig = wait(NULL);
    clock_gettime(CLOCK_MONOTONIC,&buffer);
    if (nig == c1) {
        clock_gettime(CLOCK_MONOTONIC, &after1);
        unsigned long time1 = (before1.tv_sec * 1000000000) + before1.tv_nsec;
        unsigned long time2 = (buffer.tv_sec * 1000000000) + buffer.tv_nsec;
        float time_taken = ((float)(time2 - time1))/1000000000;
        times[0] = time_taken;
    }
    else if (nig == c2)  {
        clock_gettime(CLOCK_MONOTONIC, &after1);
        unsigned long time1 = (before2.tv_sec * 1000000000) + before2.tv_nsec;
        unsigned long time2 = (buffer.tv_sec * 1000000000) + buffer.tv_nsec;
        float time_taken = ((float)(time2 - time1))/1000000000;
        times[1] = time_taken;
    }
    else if (nig == c3) {
        clock_gettime(CLOCK_MONOTONIC, &after1);
        unsigned long time1 = (before3.tv_sec * 1000000000) + before3.tv_nsec;
        unsigned long time2 = (buffer.tv_sec * 1000000000) + buffer.tv_nsec;
        float time_taken = ((float)(time2 - time1))/1000000000;
        times[2] = time_taken;
    }
    for (int i=0; i<3; i++) {
        printf("Time taken with Priority %d: %f\n", 1, times[i]);
    }
}
