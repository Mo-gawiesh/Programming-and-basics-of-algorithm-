#include <iostream>
#include <string>
#include<fstream>
#include "myfuncs.h"
using namespace std;

int main()
{
    int n;
    int i{},j{1},k,l;
    while(j==1){
        cout<<"Where to get the input data from?(file-1, console-0)"<<endl;
        k=one_or_zero(k);
        cout<<"Where to output the result?(file-1, console-0)"<<endl;
        l=one_or_zero(l);
        if(k==0){
        cout<<"Input n: ";
        n=natural(n);}
        else if(k==1){
        j=0;
        ifstream file;
        file.open("input.txt");
        file>>n;}
        double a[n];
        double b[n];
        if(k==0){
            for(i=0;i<n;i++){cout<<"Input a"<<i+1<<": ";
            a[i]=realnum(a[i]);}}
        else if(k==1){
        ifstream file;
        file.open("input.txt");
        file>>n;
        for(int i=0;i<n;i++)file>>a[i];}
        b[0]=a[0];
        b[n-1]=a[n-1];
        for(int i=1;i<n-1;i++)b[i]=((a[i+1]-a[i])/3);
        if(l==1){
        ofstream file;
        file.open("output.txt");
        file<<"Input data:\n";
        file<<"n="<<n<<endl;
        for(i=0;i<n;i++)file<<"a"<<i+1<<"="<<a[i]<<endl;
        file<<"Result:\n";
        for(i=0;i<n;i++)file<<"b"<<i+1<<"="<<b[i]<<endl;
    }
    else if(l==0){
        cout<<"Input data:\n";
        cout<<"n="<<n<<endl;
        for(i=0;i<n;i++)cout<<"a"<<i+1<<"="<<a[i]<<endl;
        cout<<"Result:\n";
        for(i=0;i<n;i++)cout<<"b"<<i+1<<"="<<b[i]<<endl;
    }
    if(j==1){cout<<endl<<"Continue(0-no; 1-yes)?";j=one_or_zero(j);}
    }
    return 0;
}
