#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>

#define sqr2(x) ((x)*(x))
#define frand() ((double) rand() / (RAND_MAX))
#define MAXLEN 10000

void *thread_pi1();
int circles=0;
int i;
pthread_mutex_t lock;

int main(){
    float pi;
    
    int res;
    pthread_t thread1,thread2,thread3,thread4;

    res = pthread_create(&thread1, NULL, thread_pi1, NULL);
	res = pthread_create(&thread2, NULL, thread_pi1, NULL);
    res = pthread_create(&thread3, NULL, thread_pi1, NULL);
	res = pthread_create(&thread4, NULL, thread_pi1, NULL);
    res = pthread_join(thread1, NULL);
	res = pthread_join(thread2, NULL);
    res = pthread_join(thread3, NULL);
	res = pthread_join(thread4, NULL);


    pi = 4*((float) circles/(float) MAXLEN);
    printf("After %d iterations circles is %d  PI is %2.4f : \n", MAXLEN ,circles, pi);
    return 0; 
}

void *thread_pi1(){
    for(i = 0; i < (MAXLEN); i++){
        float xcoord = (double)drand48();
        float ycoord = (double)drand48();
        float coord = sqr2(xcoord) + sqr2(ycoord);

        if(coord <= 1){
            pthread_mutex_lock(&lock);
            circles = circles + 1;
            pthread_mutex_unlock(&lock);
        }
        usleep((rand()%3));
    }
}
