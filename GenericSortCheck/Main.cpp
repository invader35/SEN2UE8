///////////////////////////////////////
// Workfile    : Main.cpp
// Author      : Matthias Schett
// Date        : 19-05-2013
// Description : Generic Sort Checking
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <list>
#include <fstream>
#include "GenericSortCheck.h"

using namespace std;

bool testSortPredicate(const int a, const int b){
    if(a == b){
        return true;
    } else if(a < b){
        return true;
    } else if(a > b){
        return false;
    }
}

int main(){

    ofstream file("OutputA2.txt");

    SortType sortT;
    vector<int> v;

    file << "Test with vector" << endl << endl;

    file << "Test with empty container: ";
    file << getSortType(CheckSorting(v.begin(), v.end())) << endl;

    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }

    file << "Test with ascending ordered container: ";
    file << getSortType(CheckSorting(v.begin(), v.end())) << endl;

    file << "Test with custom predicate and ascending order container: ";
    file << getSortType(CheckSorting(v.begin(), v.end())) << endl;

    std::random_shuffle(v.begin(), v.end());

    file << "Test with random ordered container: ";
    file << getSortType(CheckSorting(v.begin(), v.end())) << endl;

    std::sort(v.begin(), v.end(), std::greater<int>());

    file << "Test with descending ordered container: ";
    file << getSortType(CheckSorting(v.begin(), v.end())) << endl;

    v.clear();
    for(int i = 0; i < 10; i++) {
        v.push_back(1);
    }

    file << "Test with equal entries container: ";
    file << getSortType(CheckSorting(v.begin(), v.end())) << endl;

    file << endl << endl << "Test with std::list" << endl << endl;

    list<int> l;

    file << "Test with empty container: ";
    file << getSortType(CheckSorting(l.begin(), l.end())) << endl;

    for(int i = 0; i < 10; i++){
        l.push_back(i);
    }

    file << "Test with ascending ordered container: ";
    file << getSortType(CheckSorting(l.begin(), l.end())) << endl;

    file << "Test with custom predicate and ascending order container: ";
    file << getSortType(CheckSorting(l.begin(), l.end())) << endl;

    l.clear();
    for(int i = 0; i < 10; i++){
        if(i % 2 == 0){
            l.push_back(i);
        } else {
            l.push_front(i);
        }
        
    }

    file << "Test with random ordered container: ";
    file << getSortType(CheckSorting(l.begin(), l.end())) << endl;

    l.sort(std::greater<int>());

    file << "Test with descending ordered container: ";
    file << getSortType(CheckSorting(l.begin(), l.end())) << endl;

    l.clear();
    for(int i = 0; i < 10; i++) {
        l.push_back(1);
    }

    file << "Test with equal entries container: ";
    file << getSortType(CheckSorting(l.begin(), l.end())) << endl;

    cin.get();
    return 0;
}