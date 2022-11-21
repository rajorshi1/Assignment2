#include <sys/wait.h>
#include<math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h> //linux specific library
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h> //Used for handling directory files
#include <errno.h> //For EXIT codes and error handling
#include <stddef.h>
#include <sys/time.h>
#include <sched.h>

unsigned long long int time1diff,time2diff,time3diff;

int main(){
    pid_t a=fork();
    pid_t b=fork();
    if(a==0 && b>0){
        struct sched_param parameter;
        pid_t p_num=getpid();
        sched_setscheduler(p_num,SCHED_OTHER,&parameter);
        //execl("/bin/sh", "sh","vidur.sh",(char*) NULL);
        for(int i=0;i<4;i++){
            printf("$$$\n");
        }
    }
    else if(a==0 && b==0){
        struct sched_param parameter;
        pid_t p_num=getpid();
        sched_setscheduler(p_num,SCHED_FIFO,&parameter);
        //execl("/bin/sh", "sh","vidur.sh",(char*) NULL);
        for(int i=0;i<4;i++){
            printf("$$\n");
        }
    }
    else if(a>0 && b==0){
        struct sched_param parameter;
        pid_t p_num=getpid();
        sched_setscheduler(p_num,SCHED_RR,&parameter);
        //execl("/bin/sh", "sh","vidur.sh",(char*) NULL);
        for(int i=0;i<4;i++){
            printf("$\n");
        }
    }
    else{
        wait(NULL);
    }
}