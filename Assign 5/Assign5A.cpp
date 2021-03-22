//Comments were inherited form the sample code
//I essentially just changed it into a templated format
//Template doesn't work for things such as strings and chars

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits> // For INT_MIN

using namespace std;

template <typename item> //template
class linkedlist
{

public:

    struct stack
    {
        item data;
        struct stack* next;
    };

    int size = 0;

    //Function to push a new element in stack.
    void push(item element)
    {
        //Check stack overflow
        if (size >= CAPACITY)
        {
            cout << "Stack Overflow, can't add more element to stack.\n";
            return;
        }

        //Create a new node and push to stack
        stack* newNode = new stack;

        //Assign data to new node in stack
        newNode->data = element;

        //Next element after new node should be current top element
        newNode->next = top;

        //Make sure new node is always at top
        top = newNode;

        //Increase element count in stack
        size++;

        cout << "Data pushed to stack.\n";

    }

    //Function to pop element from top of stack.

    item pop()
    {
        item data = 0;
        stack* topNode;

        //Check stack underflow
        if (size <= 0 || !top)
        {
            cout << "Stack is empty. \n";

            //Throw empty stack error/exception
            //Since C does not have concept of exception
            //Hence return minimum integer values as error value
            //Later in code check if return value is INT_MIN, then
            //stack is empty

            return INT_MIN;
        }

        //Copy reference of stack top to some temp variable
        //Since we need to delete current stack top and make
        //stack top its next element
        topNode = top;

        //Copy data from stack's top element
        data = top->data;

        //Move top to its next element
        top = top->next;

        //Delete the previous top most stack element from memory
        free(topNode);

        //Decrement stack size
        size--;

        return data;
    }

    void display()
    {

        stack* temp;
        for(temp = top; temp != NULL; temp = temp->next)
            cout << temp->data << " ";
        cout << endl;

    }

private:
    //private definitions
    stack *top =  NULL;
    int CAPACITY = 1000;

};



int main()
{
    //Type definition can only work with definitions such as
    //int, float, double, long, short
    linkedlist<int> item;
    int choice, data;

    while(1)
    {
        //Menu
        cout << "------------------------------------\n";
        cout << "STACK IMPLEMENTATION PROGRAM\n";
        cout << "------------------------------------\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Size\n";
        cout << "4. Print the stack\n";
        cout << "5. Exit\n";
        cout << "------------------------------------\n";
        cout << "Enter your choice: ";

        cin >> choice;
        cout << endl;

        switch(choice) //Added overall template definitions (as seen from the item.)
        {
        case 1:
            cout << "Enter data to push into stack: ";
            cin >> data;

            //Push element to stack
            item.push(data);
            break;

        case 2:
            data = item.pop();
            //if stack is not empty
            if (data != INT_MIN)
                cout << "Data pushed = > " << data << endl;
            break;

        case 3:
            cout << "Stack size:" << item.size << endl;
            break;

        case 4:
            item.display();
            break;

        case 5:
            cout << "Exiting from app.\n" << endl;
            exit(0);
            break;

        default:
            cout << "Invalid choice, please try again.\n";

        }
        cout << "\n\n";
    }
    return 0;

}




