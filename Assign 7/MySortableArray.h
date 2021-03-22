#ifndef MYSORTABLEARRAY_H
#define MYSORTABLEARRAY_H

#include <iostream>
using namespace std;

//Templated class and function declarations
//Alot of these are copy pasted from Assignment 3 and 2 so not all of them are used in this assignment

template <class item>
class MySortableArray //string dynamicarray has been changed to class dynamic array to allow for general usage
{

public:
    MySortableArray();

    MySortableArray(const MySortableArray& dsa);

    int getSize();

    void addEntry(item user);

    bool deleteEntry(item input);

    item getEntry(int input);

    MySortableArray operator==(const MySortableArray& dsa);

    void swap(int* a, int* b);

    int partition (int low, int high);

    void sort(int, int);

    ~MySortableArray();


private:
    item *dynamicArray;
    int size;

};

#endif // DYNAMICARRAY_H
