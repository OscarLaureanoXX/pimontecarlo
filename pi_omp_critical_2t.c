#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>


#define sqr2(x) ((x)*(x))
#define frand() ((double) rand() / (RAND_MAX))
#define MAXLEN 10000



int main(){
    int i,j, circles=0, rect=0;
    float pi;

    int numthreads = 2;

    #pragma omp parallel  num_threads(numthreads)
    for(i = 0; i < (MAXLEN); i++){
        float xcoord = (double)drand48();
        float ycoord = (double)drand48();
        float coord = sqr2(xcoord) + sqr2(ycoord);

        if(coord <= 1){
            #pragma omp critical
            circles = circles + 1;
        }
        usleep((rand()%3));
    }

    pi = 4*((float) circles/(float) MAXLEN);
    printf("After %d iterations circles is %d  PI is %2.4f : \n", MAXLEN ,circles, pi);
    return 0; 
}