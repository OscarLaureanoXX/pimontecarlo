#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>

#define sqr2(x) ((x)*(x))
#define frand() ((double) rand() / (RAND_MAX))
#define MAXLEN 10000

void *thread_pi1();
void *thread_pi2();
void *thread_pi3();
void *thread_pi4();
double sum1=0,sum2=0,sum3=0,sum4=0;



int main(){
    int i,j, circles=0, rect=0;
    float pi;
    
    int res;
    pthread_t thread1,thread2,thread3,thread4;

    res = pthread_create(&thread1, NULL, thread_pi1, NULL);
	res = pthread_create(&thread2, NULL, thread_pi2, NULL);
    res = pthread_create(&thread3, NULL, thread_pi3, NULL);
	res = pthread_create(&thread4, NULL, thread_pi4, NULL);
    res = pthread_join(thread1, NULL);
	res = pthread_join(thread2, NULL);
    res = pthread_join(thread3, NULL);
	res = pthread_join(thread4, NULL);

    circles = sum1 + sum2 + sum3 + sum4;

    pi = 4*((float) circles/(float) MAXLEN);
    printf("After %d iterations circles is %d  PI is %2.4f : \n", MAXLEN ,circles, pi);
    return 0; 
}

void *thread_pi1(){
    int i;

    for(i = 0; i < (MAXLEN / 4); i++){
        float xcoord = (double)drand48();
        float ycoord = (double)drand48();
        float coord = sqr2(xcoord) + sqr2(ycoord);

        if(coord <= 1){
            sum1 = sum1 + 1;
        }
        usleep((rand()%3));
    }
}

void *thread_pi2(){
    int i;

    for(i = (MAXLEN / 4); i < (MAXLEN/2); i++){
        float xcoord = (double)drand48();
        float ycoord = (double)drand48();
        float coord = sqr2(xcoord) + sqr2(ycoord);

        if(coord <= 1){
            sum2 = sum2 + 1;
        }
        usleep((rand()%3));
    }
}

void *thread_pi3(){
    int i;

    for(i = (MAXLEN / 2); i < ((MAXLEN/4) + (MAXLEN/2)); i++){
        float xcoord = (double)drand48();
        float ycoord = (double)drand48();
        float coord = sqr2(xcoord) + sqr2(ycoord);

        if(coord <= 1){
            sum3 = sum3 + 1;
        }
        usleep((rand()%3));
    }
}
void *thread_pi4(){
    int i;

    for(i = ((MAXLEN/4) + (MAXLEN/2)); i < (MAXLEN); i++){
        float xcoord = (double)drand48();
        float ycoord = (double)drand48();
        float coord = sqr2(xcoord) + sqr2(ycoord);

        if(coord <= 1){
            sum4 = sum4 + 1;
        }
        usleep((rand()%3));
    }
}