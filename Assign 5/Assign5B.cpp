/**
Much like the previous case form Assignment 5a, alot of the comments are kept form the actual and sample code as
what I did was merely modification of certain aspects
**/

#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>


#define CAPACITY 100 ///Queue max capacity

using namespace std;

/** Queue structure definition */
template<class item> ///templated structure definition
struct QueueType
{
public:
    item data;
    struct QueueType * next;
};

/** Queue size */
unsigned int size = 0;
template<class item>

///Class definition
class QType
{
    QueueType<item> *front, *rear; ///definition for the front and rear pointers
    public:

        QType() ///constructor that appoints the pointers to a null value
        {
            rear = NULL;
            front = NULL;
        }

        int enqueue(int data)
        {
            QueueType<item> * newNode = NULL;
            if (isFull())
            {
                return 0;
            }
            newNode = new QueueType<item>;
            newNode->data = data;
            newNode->next = NULL;
            if ( (rear) )
            {
                rear->next = newNode;
            }
            rear = newNode;
            if ( !( front) )
            {
                front = rear;
            }
            size++;
            return 1;
        }


        int dequeue()
        {
            QueueType<item> *toDequque = NULL;
            int data = INT_MIN;
            if (isEmpty())
            {
                return INT_MIN;
            }
            toDequque = front;
            data = toDequque->data;
            front = (front)->next;
            size--;
            free(toDequque);
            return data;
        }

        int getRear()
        {
        return (isEmpty())
            ? INT_MIN
            : rear->data;
        }

        int getFront()
        {
        // Return INT_MIN if queue is empty otherwise front.
        return (isEmpty())
            ? INT_MIN
            : front->data;
        }


        /**
        * Checks, if queue is empty or not.
        */
        int isEmpty()
        {
            return (size <= 0);
        }


        /**
        * Checks, if queue is within the maximum queue capacity.
        */
        int isFull()
        {
            return (size > CAPACITY);
        }
        string prepMenu()
        {
            string menu = "";

            menu+= " \n-------------------------------------------------------------------\n";
            menu+= "1.Enqueue 2.Dequeue 3.Size 4.Get Rear 5.Get Front 6.Display 7.Exit\n";
            menu+= "----------------------------------------------------------------------\n";
            menu+= "Select an option: ";
            return menu;
        }
        void display()
        {
            for ( QueueType<item> *t = front; t !=NULL; t = t->next)
            cout <<t->data << " ";
            cout << endl << endl;
        }
};

/**
The only changes to the main function between the sample code and this one is that
I have removed the pointer definition for rear and front and moved them to the class
The functions containing rear and front have also had the two removed as it is now part of the class up there
hence not needing any reason to be called again from main.
Functions are also now added with the header call of item. to ensure that they are being called from the class
**/
int main()
{
    int option, data;

    QType<int> item;

    string menu = item.prepMenu();
    cout << menu << endl;
    cin >> option;
    while (option !=7)
    {

        switch (option)
        {
            case 1:
            cout << "\nEnter data to enqueue (-99 to stop): ";
            cin >> data;
            while (data != -99)
            {
                /// Enqueue function returns 1 on success
                /// otherwise 0
                if (item.enqueue(data))
                cout << "Element added to queue.";
                else
                cout << "Queue is full." << endl;
                cout << "\nEnter data to enqueue (-99 to stop): ";
                cin >> data;
            }


            break;

            case 2:
            data = item.dequeue();

            /// on success dequeue returns element removed
            /// otherwise returns INT_MIN
            if (data == INT_MIN)
            cout << "Queue is empty."<< endl;
            else
            cout << "Data => " << data << endl;

            break;

            case 3:

            /// isEmpty() function returns 1 if queue is emtpy
            /// otherwise returns 0
            if (item.isEmpty())
            cout << "Queue is empty."<< endl;
            else
            cout << "Queue size => "<< size << endl;

            break;

            case 4:
            data = item.getRear();

            if (data == INT_MIN)
            cout << "Queue is empty." << endl;
            else
            cout << "Rear => " << data << endl;

            break;

            case 5:

            data = item.getFront();

            if (data == INT_MIN)
            cout <<"Queue is empty."<< endl;
            else
            cout <<"Front => " << data << endl;

            break;

            case 6:
            item.display();
            break;

            default:
            cout <<"Invalid choice, please input number between (0-5).\n";
            break;
        }

        cout <<"\n\n";
        cout << menu<< endl;
        cin >> option;
    }
}

