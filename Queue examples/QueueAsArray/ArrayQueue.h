#ifndef ARRAYQUEUE_H_INCLUDED
#define ARRAYQUEUE_H_INCLUDED
///---------------------------------------------------------------
/// File: ArrayQueue.h
/// Purpose: Header file for a demonstration of a queue implemented
///        as an array.  Data type: Character
/// Programming Language: C++
//---------------------------------------------------------------

#define MAX_SIZE    25        /// Define maximum length of the queue

class ArrayQueue
{
    private:
        int head, tail;           /// Index to top of the queue
        char theQueue[MAX_SIZE];  /// The queue

    public:
        ArrayQueue();            /// Class constructor
        ~ArrayQueue();           /// Class destuctor
        void ClearQueue();       /// Remove all items from the queue
        bool Enqueue(char ch);   /// Enter an item in the queue
        char Dequeue();          /// Remove an item from the queue
        bool isEmpty();          /// Return true if queue is empty
        bool isFull();           /// Return true if queue is full
};



#endif /// ARRAYQUEUE_H_INCLUDED
