///////////////////////////////////////
// Workfile    : Main.cpp
// Author      : Matthias Schett
// Date        : 19-05-2013
// Description : Shift function template
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <fstream>
#include "TemplateShift.h"

using namespace std;

int main(){

    ofstream oFile("OutputA1.txt");

    std::ostream_iterator<int> out_it (oFile, ", ");

    oFile << "Template Test with vector" << endl;

    vector<int> myVec;

    for (int i=0; i<10; i++) {
        myVec.push_back (i);
    }

    size_t count = 3;
    int val = 5;
    oFile << "Shift is done " << count << " times and filled up with " << val << endl;
    Shift(myVec.begin(), myVec.end(), count, val);

    std::copy ( myVec.begin(), myVec.end(), out_it );

    oFile << endl << "Test ende" << endl;

    oFile << "Template Test with list" << endl;

    list<int> myList;

    for (int i=0; i<10; i++) {
        myList.push_back (i);
    }

    count = 4;
    val = 6;
    oFile << "Shift is done " << count << " times and filled up with " << val << endl;
    Shift(myList.begin(), myList.end(), count, val);

    std::copy ( myList.begin(), myList.end(), out_it );
    
    oFile << endl << "Test ende" << endl;

    cin.get();
    return 0;
}