#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
using namespace std;
#include "ACO.h"


int main()
{
    ACO * aco;
    aco = new ACO(5,1,5,0.5,4,4,5,0.000001,100);
    //(int maxit, double alpha, double beta, double ro, int nAnts, int nCiudades, int b, double taumin, int q)
    aco ->cPosicion(0,10.1,20.1);
    aco ->cPosicion(1,20.1,40.1);
    aco ->cPosicion(2,30.1,10.1);
    aco ->cPosicion(3,40.1,20.1);
    aco ->inicializar();
;

    cout << "Hello world!" << endl;
    return 0;
}
