
/*Este codigo usa el modelo de montecarlo para estimar el valor de la constante PI */
/* este codigo es original de http://stackoverflow.com/questions/17659652/calculating-pi-using-monte-carlo-method-gives-imprecise-answer*/
/* Ha sido modificado por Alejandro Parra Briones para fines academicos*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#define sqr2(x) ((x)*(x))
#define frand() ((double) rand() / (RAND_MAX))
#define MAXLEN 10000


/*Funcion para verificar si cayo dentro del circulo*/
int circumscribed(int radius){
    float xcoord = frand();
    float ycoord = frand(); 
    float coord = sqr2(xcoord) + sqr2(ycoord);

    if(coord <= radius)
        return 1;
    return -1;      
}


/*Creamos esta funcion para que se use con threads y hacerlo lo mas parecido a si lo hicieramos con threads */
void llamacircumscribed( void ){
int i,j, circles=0, rect=0;
  float pi;

   for(i = 0; i < (MAXLEN); i++)
    {
      if(circumscribed(1) > 0) {  // if(circumscribed(1)) shoul be enough but it doesn't work. Very odd in my opinion.
	circles++;

	}
	usleep((rand()%3)); /* Esto pone aleatoriadad cada vez que se hace un tiro */
    }
    pi = 4*((float) circles/(float) MAXLEN);
    printf("After %d iterations circles is %d  PI is %2.4f : \n", MAXLEN ,circles, pi);
}

int main()
{
	
  llamacircumscribed();
    return 0;   
}
