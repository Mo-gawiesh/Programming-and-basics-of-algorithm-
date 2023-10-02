#include <iostream>
#include <string>
#include <limits>
#include<sstream>
using namespace std;
double* func(double* a, int n){
double* b=new double[n];
   b[0]=a[0];
   b[n-1]=a[n-1];
  for(int i=1;i<n-1;i++){
    b[i]=((a[i+1]-a[i])/3);}
 return b;

}

int one_or_zero(int a) {
    string m;
    getline(cin, m);
    while (m.length() != 1 || (stoi(m) != 0 && stoi(m) != 1)) {
        cout << "!!!Error!!!\nInput 1 or 0" << endl;
        cin.clear();
        getline(cin, m);
    }
    a = stoi(m);
    return a;
}
int natural(int n){
    float m;
    while (!(cin >> m) || m<=0 || (n=m)!=m){
        cout << "Error, try again:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return n;
    }
float realnum(float n){
    while (!(cin >> n)){
        cout << "Error, try again:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return n;
    }
