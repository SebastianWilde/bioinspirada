#include <iostream>
#include "genetico.h"
using namespace std;
inline int maximizar(int num)
{
    return (int)pow(num,2);
}

int main()
{
    int sol1 = aGenetico(maximizar);
    cout << "Hello world!" <<endl;
    return 0;
}
