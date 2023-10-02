#include <iostream>
#include <string>
#include <limits>
using namespace std;
void func(int** a,int* b,int** c){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(a[i][j]<c[i][j]){
                b[i]=0;
                break;}
            else if(a[i][j]>c[i][j]&&j==5)b[i]=1;
        }
    }
}
int one_or_zero() {
    string m;
    getline(cin, m);
    while (m.length() != 1 || (stoi(m) != 0 && stoi(m) != 1)) {
        cout << "!!!Error!!!\nInput 1 or 0" << endl;
        getline(cin, m);
    }
    int a = stoi(m);
    return a;
}
int natural(int n){
    float m;
    while (!(cin >> m) || (n=m)!=m){
        cout << "Error, try again:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return n;
    }
