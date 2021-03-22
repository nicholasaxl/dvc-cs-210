#include "MySortableArray.h"

#include <iostream>
using namespace std;

//These are all functions
//They are also templated
//Most of these are copy pasted form assignment 3 so there are some unused functions
    template <class item>
    MySortableArray<item>::MySortableArray()
    {
        //constructor that sets the pointer to null and sizer to 0
        dynamicArray = nullptr;
        size = 0;
    }

    template <class item>
    MySortableArray<item>::MySortableArray(const MySortableArray& dsa)
    {
        //Creates a new array with size +1
        size = dsa.size;
        dynamicArray = new item[size]; //creates a new dynamic array with an item property
        for(int i = 0; i<size; i++)
        {
            //reassign values
            dynamicArray[i] = dsa.dynamicArray[i];
        }
    }

    template <class item>
    int MySortableArray<item>::getSize()
    {
        //returns the size of the array
        return size;
    }

    template <class item>
    void MySortableArray<item>::addEntry(item user)
    {
        //recreates a new dynamic array with an increased size
        item* newArray = new item[size+1]; //creates a new 'item' instead of the previous string
        size = size + 1;
        int i;
        for (i=0; i<size-1; i++)
        {
            //loop to assign the values to the new array
            newArray[i] = dynamicArray[i];
        }
        newArray[size-1] = user;
        delete[] dynamicArray;
        dynamicArray = newArray;
    }

    template <class item>
    bool MySortableArray<item>::deleteEntry(item input)
    {
        int j; //counter for the loop
        for(j = 0; j<size; j++)
        {
            if(dynamicArray[j] == input)
            {
                break;
                //breaks the loop when the input is found
            }
        }

        if(j==size)
        {
            //otherwise return false from the function
            return false;
        }

        //create a new dynamic array with a size that is 1 less
        item* newArray = new item[size-1];

        int l = 0;

        for(int k=0; k<size; k++)
        {
            if(dynamicArray[k]!=input)
            {
                //assigns every value that is not equal to the user input
                newArray[l++] = dynamicArray[k];
            }
        }
        //delete the dynamic array
        delete[] dynamicArray;
        //reduce the size
        size--;
        //reassign the new array to the dynamic array
        dynamicArray = newArray;
        //return true after recreating the arrays
        return true;

    }

    template <class item>
    item MySortableArray<item>::getEntry(int input)
    {
        //get entry and return the value when the input is considered valid
        if(input<size && input>=0)
        {
            return dynamicArray[input];
        }
        else
        {
            return NULL; //if invalid input, return nothing
        }
    }

    template <class item>
    MySortableArray<item> MySortableArray<item>::operator==(const MySortableArray& dsa)
    {
        //operator overloading for the == assignment operator
        size = dsa.size;
        dynamicArray = new item[size]; //now an "item" instead of string
        for(int i=0; i<size; i++)
        {
            dynamicArray[i] = dsa.dynamicArray[i];
        }
        return *this;
        //return the submitted input

    }

    //general swap function to swap 2 values
    template <class item>
    void MySortableArray<item>::swap(int* a, int* b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }

    //function to divide the array into two by its pivot for the desired indexes
    template <class item>
    int MySortableArray<item>::partition (int low, int high)
    {
        int pivot = dynamicArray[high];    // pivot
        int i = (low - 1);  // Index of smaller element

        for (int j = low; j <= high- 1; j++)
        {
            // If current element is smaller than or
            // equal to pivot
            if (dynamicArray[j] <= pivot)
            {
                i++;    // increment index of smaller element
                swap(&dynamicArray[i], &dynamicArray[j]);
            }
        }
        swap(&dynamicArray[i + 1], &dynamicArray[high]);
        return (i + 1);
    }

    //the sorting function which uses recursion to sort through a QuickSort
    template <class item>
    void MySortableArray<item>::sort(int startIdx, int endIdx)
    {
        if (startIdx < endIdx)
        {
            int pi = partition(startIdx, endIdx);

            sort(startIdx, pi - 1);
            sort(pi + 1, endIdx);
        }
    }

    template <class item>
    MySortableArray<item>::~MySortableArray()
    {
        //deconstructor that deletes the array
        delete[] dynamicArray;
    }

