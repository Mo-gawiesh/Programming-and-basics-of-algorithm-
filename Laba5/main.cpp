#include <iostream>
#include <bitset>
#include "myfuncs.h"
using namespace std;
int main(int argc, char *argv[]){
    setlocale(LC_ALL,"Russian");
    if(argc==2){
    long long x;
    try{
        x=stoll(argv[1]);}
    catch(invalid_argument&ia){
    cout<<"Unable to convert argument "<<ia.what();
    return 0;}
    cout<<"Number: "<<x<<"=";
    bitset<64> bin(x);
    int i,n{};
    for(i=63;i>0;i--)if(bin[i]==1)break;
    for(int j=i;j>=0;j--)cout<<bin[j];
    n=func(x);
    cout<<"\nResult: "<< n << endl;}
    else cout<<"One argument is required";
    return 0;}
