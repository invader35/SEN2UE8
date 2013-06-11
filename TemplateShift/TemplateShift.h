///////////////////////////////////////
// Workfile    : TemplateShift.h
// Author      : Matthias Schett
// Date        : 19-05-2013
// Description : Shift function template
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#ifndef TEMPLATE_SHIFT
#define TEMPLATE_SHIFT

#include <algorithm>

//************************************
// Method:    Shift
// FullName:  Shift
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: TItor begin
// Parameter: TItor end
// Parameter: size_t count
// Parameter: TValue val
// Shift elements in container count places to the front
//************************************
template <typename TItor, typename TValue>
void Shift(TItor begin, TItor end, size_t count, TValue val){
    
    TItor middle = begin;

    std::advance(middle, count);

    std::rotate(begin, middle , end);

    TItor it = end;
    int countInt = 0 - count;
    std::advance(it, countInt);
    while(it != end){
        *it = val;
        std::advance(it, 1);
    }

}


#endif