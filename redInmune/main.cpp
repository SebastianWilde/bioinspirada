#include <iostream>
//#include <algorithm>
//#include <math.h>
#include <bits/stdc++.h>
using namespace std;
#include "redesInmunes.h"
int main()
{
    vector <int*> patrones;
    int * pat = new int[2];
    pat[0] = 0;
    pat[1] = 0;
    patrones.push_back(pat);
    int * pat2 = new int[2];
    pat2[0] = 7;
    pat2[1] = 5;
    patrones.push_back(pat2);
    int * pat3 = new int[2];
    pat3[0] = 4;
    pat3[1] = 6;
    patrones.push_back(pat3);
    redesInmunes ri(patrones,0.17,0.17,5,1);
    ri.inicio();
    ri.Print();
    cout << "Hello world!" << endl;
    return 0;
}
