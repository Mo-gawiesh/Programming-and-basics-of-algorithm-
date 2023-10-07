#include "myfuncs.h"
#include <windows.h>
using namespace std;

int main(){
    setlocale(LC_ALL,"ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    list l;
    ifstream file("input.txt");
    while(!file.eof()){
        string pbfio,pbpost,pbcity;
        getline(file,pbfio,';');
        getline(file,pbpost,';');
        getline(file,pbcity);
        l.push_back(pbfio,pbpost,pbcity);;}
    bool cycle=true;
    while(cycle){
        cout<<"-------------------------------------------------------------\n";
        cout<<"Select an action:\n";
        cout << "1) Printing all elements;\n";
        cout << "2) Resetting all values of all elements;\n";
        cout << "3) Add an item to the end of the list;\n";
        cout << "4) Save the list;\n";
        cout << "5) Count the number of list items;\n";
        cout << "0) Exit\n";
        cout<<"-------------------------------------------------------------\n";
        int act=natural(act);
        switch (act){
        case 0:{
            cycle=!cycle;
            l.save();
            l.del();
            cout<<"The list is unloaded from RAM\n";
            break;}
        case 1:{
            l.print();
            break;}
        case 2:{
            l.reset();
            l.print();
            break;}
        case 3:{
            string pbfio,pbage,pbstat;
            cout<<"Enter the data in the format \"Full name;Post;City\"\n";
            cin.ignore(100,'\n');
            getline(cin,pbfio,';');
            getline(cin,pbage,';');
            getline(cin,pbstat);
            l.push_back(pbfio,pbage,pbstat);}
        case 4:{
        l.save();
        break;}
        case 5:{
        cout<<"The number of items in the list is "<<l.counts()<<endl;}
            }}
    return 0;
}
