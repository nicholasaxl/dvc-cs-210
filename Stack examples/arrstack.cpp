#include <iostream>
#include <cstdio>
#include <cstdlib>

#define SIZE 100 //StackNode Maximum capacity

using namespace std;\

//Create a stack with capacity of 100 elements
int stack[SIZE];

//initial stack is empty
int top = -1;

//Function declaration to perform push and pop on stack
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
        cout <<"4. Print Stack\n";
        cout <<"5. Exit\n";
        cout <<"------------------------------------\n";
        cout <<"Enter your choice: ";

        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "Enter data to push into stack: ";
            cin >> data;

            //Push element to StackNode
            push(data);
            break;

        case 2:
            data = pop();

            //If stack is not empty
            if (data != INT_MIN)
                cout <<"Data => " << data << endl;
            break;

        case 3:
            cout << "Stack size: " << top + 1 << endl;
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


//Function to push a new element in stack.

void push(int element)
{
    //Check stack overflow
    if (top >= SIZE)
    {
        cout << "StackNode Overflow, can't add more element to stack.\n";
        return;
    }

    //Increase element count in stack
    top++;

    //Push element in stack
    stack[top] = element;

    cout << "Data pushed to stack.\n";
}

//Function to pop element from top of stack.

int pop()
{
    //Check stack underflow
    if (top < 0)
    {
        cout << "Stack is empty.\n";

        //Throw empty stack error/exception
        //Since C does not have concept of exception
        //Hence return minimum integer values as error value
        //Later in code check if return value is INT_MIN, then
        //stack is empty
        return INT_MIN;
    }

    //Return stack top and decrease element count in stack
    return stack[top--];

}

void display()
{
    if (top >= 0)
    {
        for(int i = 0; i <= top; i++)
            cout << stack[i] << " ";
        cout << endl;
    }
    else
        cout << "stack is empty \n\n";

}

