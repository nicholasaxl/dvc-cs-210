#include <iostream>
#include <cstdio>
#include <cstdlib>

#define CAPACITY 10000 //StackNode Maximum capacity

using namespace std;

struct StackNode
{
    int data;
    struct StackNode* next;
};

//Stack Size
StackNode *top =  NULL;
int size = 0;

//Function declarations to perform push and pop on StackNode

void push(int element);

int pop();

void display();



int main()
{
    int choice, data;
    while(1)
    {
        //Menu
        cout <<"------------------------------------\n";
        cout << "STACK IMPLEMENTATION PROGRAM \n";
        cout <<"------------------------------------\n";
        cout << "1. Push\n";
        cout <<"2. Pop\n";
        cout <<"3. Size\n";
        cout <<"4. Print the StackNode\n";
        cout <<"5. Exit\n";
        cout <<"------------------------------------\n";
        cout <<"Enter your choice: " << endl << endl;

        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "Enter data to push into StackNode: ";
            cin >> data;

            //Push element to StackNode
            push(data);
            break;

        case 2:
            data = pop();
            //if StackNode is not empty
            if (data != INT_MIN)
                cout << "Data pushed = > " << data << endl;
            break;

        case 3:
            cout << "Stack size:" << size << endl;
            break;

        case 4:
            display();
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


//Function to push a new element in StackNode.

void push(int element)
{
    //Check StackNode overflow
    if (size >= CAPACITY)
    {
        cout << "StackNode Overflow, can't add more element to StackNode.\n";
        return;
    }

    //Create a new node and push to StackNode
    StackNode* newNode = new StackNode;

    //Assign data to new node in StackNode
    newNode->data = element;

    //Next element after new node should be current top element
    newNode->next = top;

    //Make sure new node is always at top
    top = newNode;

    //Increase element count in StackNode
    size++;

    cout << "Data pushed to StackNode.\n";
}

//Function to pop element from top of StackNode.

int pop()
{
    int data = 0;
    StackNode* topNode;

    //Check StackNode underflow
    if (size <= 0 || !top)
    {
        cout << "StackNode is empty. \n";

        //Throw empty StackNode error/exception
        //Since C does not have concept of exception
        //Hence return minimum integer values as error value
        //Later in code check if return value is INT_MIN, then
        //StackNode is empty

        return INT_MIN;
    }

    //Copy refernce of StackNode top to some temp variable
    //Since we need to delete current StackNode top and make
    //StackNOde top its next element
    topNode = top;

    //Copy data from StackNode's top element
    data = top -> data;

    //Move top to its next element
    top = top->next;

    //Delete the previous top most StackNode element from memory
    free(topNode);

    //Decrement StackNode size
    size--;

    return data;
}

void display()
{

    StackNode* temp;
    for(temp = top; temp!= NULL; temp = temp->next)
        cout << temp->data << " ";
    cout << endl;
}

