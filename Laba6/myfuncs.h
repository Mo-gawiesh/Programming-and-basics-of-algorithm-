#pragma once
#include <iostream>
#include <limits>
#include <fstream>
using namespace std;
int natural(int n){
    float m;
    while (!(cin >> m) || m<0 || m>5 || (n=m)!=m){
        cout << "Input error, repeat the input:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');}
    return n;}
struct Node {
    string fio;
    string post;
    string city;
    Node* next;

    Node(string _fio,string _post,string _city) : fio(_fio),post(_post),city(_city), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(string _fio,string _post, string _city) {
        Node* p = new Node(_fio, _post, _city);
        if (is_empty()) {
            first = p;
            last = p;
            return;}
        last->next = p;
        last = p;
    }

    void print() {
        if (is_empty()) return;
        Node* p = first;
        int count=1;
        while (p) {
            cout <<count<<")"<< p->fio<<";"<<p->post<<";"<<p->city<<endl;
            p=p->next;
            count++;}}

    void reset(){
    Node* res=first;
    while(res){
        res->fio="Full name";
        res->post="Post";
        res->city="Place of residence";
        res=res->next;}}

    int counts(){
    if (is_empty()) return 0;
    Node* p = first;
    int k=1;
    while (p){
        k++;
        p=p->next;
    }
    return k-1;
    }

    void save() {
        if (is_empty()) return;
        ofstream file("input.txt");
        Node* p = first;
        while (p->next) {
            file<< p->fio<<";"<<p->post<<";"<<p->city<<endl;
            p=p->next;}
            file<< p->fio<<";"<<p->post<<";"<<p->city;}
    void del() {
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            first=p->next;
            delete p;
            p=first;
            }}
};
