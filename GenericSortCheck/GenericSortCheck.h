///////////////////////////////////////
// Workfile    : GenericSortCheck.h
// Author      : Matthias Schett
// Date        : 19-05-2013
// Description : Generic Sort Checking
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include <algorithm>
#include <iterator>
#include <string>

enum SortType{

    Ascending,
    Descending,
    UnSorted,
    EmptyOrEqual,

};

//************************************
// Method:    getDayName
// FullName:  getDayName
// Access:    public 
// Returns:   const string &
// Qualifier:
// Parameter: enum SortType sortT
// Prints the value of the enum
//************************************
const char* getSortType(enum SortType sortT) {
    switch (sortT) {
        case Ascending: return "Ascending";
        case Descending: return "Descending";
        case UnSorted: return "UnSorted";
        case EmptyOrEqual: return "EmptyOrEqual";
    }
}

//************************************
// Method:    CheckSorting
// FullName:  CheckSorting
// Access:    public 
// Returns:   SortType
// Qualifier:
// Parameter: TItor begin
// Parameter: TItor end
// Checks the sorting for a container
//************************************
template <typename TItor>
SortType CheckSorting(TItor begin, TItor end){

    if(begin == end){
        return EmptyOrEqual;
    }

    int distance = std::distance(begin, end) - 1;
    int ascCount = 0;
    int descCount = 0;
    int eqCount = 0;
    for(TItor it = begin; it != end; ++it){
        TItor it2 = it;
        std::advance(it2, 1);
        if( (it2 != end) && (*it < *it2) ){
            ascCount++;
        }else if( (it2 != end) && (*it > *it2) ){
            descCount++;
        } else if( (it2 != end) && (*it == *it2) ){
            eqCount++;
        }
    }

    if(ascCount == distance){
        return Ascending;
    } else if(descCount == distance){
        return Descending;
    } else if(eqCount == distance){
        return EmptyOrEqual;
    } else {
        return UnSorted;
    }

}

template <typename TItor, typename BinaryFunction>
SortType CheckSorting(TItor begin, TItor end, BinaryFunction f){

    if(begin == end){
        return EmptyOrEqual;
    }
    
    int distance = std::distance(begin, end) - 1;
    int ascCount = 0;
    int descCount = 0;
    for(TItor it = begin; it != end; ++it){
        TItor it2 = it;
        std::advance(it2, 1);
        if( (it2 != end) ) {
            bool order = f(it, it2);
            if(order){
                ascCount++
            } else{
                descCount++;
            }
        }
    }

    if(ascCount == distance){
        return Ascending;
    } else if(descCount == distance){
        return Descending;
    } else {
        return UnSorted;
    }
}