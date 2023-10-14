#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sched.h>
#include <unistd.h>
#include <pthread.h>
void *countA(){
    clock_t start_t, end_t;
   double total_t;
   start_t = clock();

    int i = 1;
    for(long int j = 1 ; j < pow(2,32) ; j++){
        i++;
    }
    end_t=clock();
    total_t = (double)(end_t - start_t)/ CLOCKS_PER_SEC;
    printf("Thread RR policy: %f\n", total_t);
    return NULL;
}
void *countB(){
    clock_t start_t, end_t;
   double total_t;
   start_t = clock();

    int i = 1;
    for(long int j = 1 ; j < pow(2,32) ; j++){
        i++;
    }
    end_t=clock();
     total_t = (double)(end_t - start_t)/ CLOCKS_PER_SEC;
    printf("Thread FIFO policy: %f\n", total_t);
    return NULL;
}
void *countC(){
    clock_t start_t, end_t;
   double total_t;
   start_t = clock();
    int i = 1;
    for(long int j = 0 ; j < pow(2,32) ; j++){
        i++;
    }
    end_t=clock();
    total_t = (double)(end_t - start_t)/ CLOCKS_PER_SEC;
    printf("Thread OTHER policy: %f\n", total_t);
    return NULL;
}
int main(){
struct sched_param schedparam1,schedparam2,schedparam3;
pthread_t thread1,thread2,thread3;
schedparam1.sched_priority = 1;
schedparam2.sched_priority = 1;
schedparam3.sched_priority = 1;
pthread_create(&thread1, NULL, countA, NULL);
pthread_setschedparam(thread1,SCHED_RR,&schedparam1);
pthread_create(&thread2, NULL, countB, NULL);
pthread_setschedparam(thread2,SCHED_FIFO,&schedparam2);
pthread_create(&thread3, NULL, countC, NULL);
pthread_setschedparam(thread3,SCHED_OTHER,&schedparam3);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
pthread_join(thread3,NULL);
}
