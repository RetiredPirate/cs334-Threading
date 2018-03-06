// Bach Nguyen
// OS Spring 2018

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <math.h>       /* sqrt */
#include <pthread.h>
using namespace std;
#define INTERVAL 10000
template <typename T>

struct Point{
    T x;
    T y;
};

typedef struct{
    Point<int> center;
    int r;
}Circle;

typedef struct{
    Point<int> tl;
    Point<int> br;
}Square;

int count_circle_points = 0, count_square_points = 0;
double randomDouble(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}


void *Calcpoint(void *threaddid )
{
    double x1;
    double y2;
    x1 = ((double) rand() / (RAND_MAX));
    if (rand() % 2 == 0 )
    {
        x1 = x1*(-1);
    }
    y2 = ((double) rand() / (RAND_MAX));
    if (rand() % 2 == 0 )
    {
        y2 = y2*(-1);
    }
    // Define a circle
    Circle _circle;
    Square _square;
    
    // (0,0), r = 1
    _circle.center.x=0;
    _circle.center.y=0;
    _circle.r=1;
    // Base of the relationship between the circle in the square
    _square.tl.x=_circle.center.x-_circle.r;
    _square.tl.y=_circle.center.y+_circle.r;
    
    _square.br.x=_circle.center.x+_circle.r;
    _square.br.y=_circle.center.y-_circle.r;
    
    
    
    cout << "Circle("<< _circle.center.x << "," << _circle.center.y << "), R=" << _circle.r << endl;
    cout << "Square TL("<< _square.tl.x << "," << _square.tl.y << ")"<<", BL("<< _square.br.x << "," << _square.br.y << ")" << endl<<endl;
    
    
    
    
    //if (x1 <= _square.tl.x && y2 <= _square.tl.y)
    //{
        //count_square_points++ ;
        
    //}
    
    if ( (x1*x1) + (y2*y2) <= (_circle.r)*(_circle.r))
    {
        count_circle_points++;
    }
    return NULL;
}
 

int main(int argc, char * args[])
{
    
    int N = 50; //
    count_square_points = N;
    
    
    pthread_t* threadN = (pthread_t*)malloc(sizeof(pthread_t) *N);
    int i;
    for (i = 0; i < N; i++)
    {
        pthread_create(&threadN[i], NULL,*Calcpoint, NULL);
    }
    //stop until it hit the N thread
    for (i=0; i< N; i++)
    {
        pthread_join(threadN[i],NULL);
    }
    
    double pi = ( 4*(count_circle_points)/(double)(count_square_points));
    
    cout << "Estimation of Pi = " << pi  << "\n" ;
    
    return 0;
}

