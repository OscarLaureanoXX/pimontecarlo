#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>

#define sqr2(x) ((x)*(x))
#define frand() ((double) rand() / (RAND_MAX))
#define MAXLEN 100000

void *thread_pi1();
void *thread_pi2();
void *thread_pi3();
void *thread_pi4();
void *thread_pi5();
void *thread_pi6();
void *thread_pi7();
void *thread_pi8();
double sum1=0,sum2=0,sum3=0,sum4=0;
double sum5=0,sum6=0,sum7=0,sum8=0;



int main(){
    int i,j, circles=0, rect=0;
    float pi;
    
    int res;
    pthread_t thread1,thread2,thread3,thread4;
    pthread_t thread5,thread6,thread7,thread8;

    res = pthread_create(&thread1, NULL, thread_pi1, NULL);
	res = pthread_create(&thread2, NULL, thread_pi2, NULL);
    res = pthread_create(&thread3, NULL, thread_pi3, NULL);
	res = pthread_create(&thread4, NULL, thread_pi4, NULL);
    res = pthread_create(&thread5, NULL, thread_pi5, NULL);
	res = pthread_create(&thread6, NULL, thread_pi6, NULL);
    res = pthread_create(&thread7, NULL, thread_pi7, NULL);
	res = pthread_create(&thread8, NULL, thread_pi8, NULL);
    res = pthread_join(thread1, NULL);
	res = pthread_join(thread2, NULL);
    res = pthread_join(thread3, NULL);
	res = pthread_join(thread4, NULL);
    res = pthread_join(thread5, NULL);
	res = pthread_join(thread6, NULL);
    res = pthread_join(thread7, NULL);
	res = pthread_join(thread8, NULL);

    circles = sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7 + sum8;

    pi = 4*((float) circles/(float) MAXLEN);
    printf("After %d iterations circles is %d  PI is %2.4f : \n", MAXLEN ,circles, pi);
    return 0; 
}

void *thread_pi1(){
    int i;

    for(i = 0; i < (MAXLEN / 8); i++){
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

    for(i = (MAXLEN / 8); i < (MAXLEN/4); i++){
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

    for(i = (MAXLEN / 4); i < ((MAXLEN/8) + (MAXLEN/4)); i++){
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

    for(i = ((MAXLEN/8) + (MAXLEN/4)); i < (MAXLEN / 2); i++){
        float xcoord = (double)drand48();
        float ycoord = (double)drand48();
        float coord = sqr2(xcoord) + sqr2(ycoord);

        if(coord <= 1){
            sum4 = sum4 + 1;
        }
        usleep((rand()%3));
    }
}

void *thread_pi5(){
    int i;

    for(i = (MAXLEN / 2); i < ((MAXLEN/8) + (MAXLEN/2)); i++){
        float xcoord = (double)drand48();
        float ycoord = (double)drand48();
        float coord = sqr2(xcoord) + sqr2(ycoord);

        if(coord <= 1){
            sum5 = sum5 + 1;
        }
        usleep((rand()%3));
    }
}

void *thread_pi6(){
    int i;

    for(i = ((MAXLEN/8) + (MAXLEN/2)); i < ((MAXLEN/4) + (MAXLEN/2)); i++){
        float xcoord = (double)drand48();
        float ycoord = (double)drand48();
        float coord = sqr2(xcoord) + sqr2(ycoord);

        if(coord <= 1){
            sum6 = sum6 + 1;
        }
        usleep((rand()%3));
    }
}

void *thread_pi7(){
    int i;

    for(i = ((MAXLEN/4) + (MAXLEN/2)); i < ((MAXLEN/8) + (MAXLEN/4) + (MAXLEN/2)); i++){
        float xcoord = (double)drand48();
        float ycoord = (double)drand48();
        float coord = sqr2(xcoord) + sqr2(ycoord);

        if(coord <= 1){
            sum7 = sum7 + 1;
        }
        usleep((rand()%3));
    }
}

void *thread_pi8(){
    int i;

    for(i = ((MAXLEN/8) + (MAXLEN/4) + (MAXLEN/2)); i < (MAXLEN); i++){
        float xcoord = (double)drand48();
        float ycoord = (double)drand48();
        float coord = sqr2(xcoord) + sqr2(ycoord);

        if(coord <= 1){
            sum8 = sum8 + 1;
        }
        usleep((rand()%3));
    }
}