#include <iostream>
#include <cmath>
using namespace std;
int func(long long x){
    int n{};
    while(x!=0){
            x = x&(x-1);
    n++;}
    return n;}

