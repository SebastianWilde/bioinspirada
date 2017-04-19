#include <iostream>
#include "genetico.h"
#include "hillClimbing.h"
using namespace std;
inline int maximizar(int num)
{
    return (int)pow(num,2);
}

int main()
{
    int sol1 = aGenetico(maximizar);
    int sol2 = hClimbing(maximizar);
    cout<<"Solucion con algoritmo genetico "<<sol1<<endl;
    cout<<"Solucion con hill climbing "<<sol2<<endl;
    cout << "Hello world!" <<endl;
    return 0;
}
