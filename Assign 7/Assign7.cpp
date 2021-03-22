#include<iostream>
#include<string>
#include<cstdlib>
#include "MySortableArray.h"
#include "MySortableArray.cpp"

using namespace std;


int main()
{
    //variable declarations
    MySortableArray<int> nums;
    int choice;
    int sortIndex;
    int lookup;
    int max_entry;
    int value;

    //user instruction for array construction
    cout << "Enter the amount of values you want in your entry: ";
    cin >> max_entry;


    //create the array
    for (int i = 0; i < max_entry; i++)
    {
        cout << "Enter the number you want to add: ";
        cin >> value;
        nums.addEntry(value);
    }

    //menu
    cout << endl;
    cout << "//-------------------------------------//" << endl;
    cout << "1. Output the number of values entered by the user" << endl;
    cout << "2. Output the unsorted list" << endl;
    cout << "3. Sort the value through certain indexes" << endl;
    cout << "4. Lookup the number within an index" << endl;
    cout << "5. Terminate the program" << endl;
    cout << "//-------------------------------------//" << endl;
    cout << endl;


    //menu loop
    do{
        cout << "Enter a number 1 to 4: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            cout << "The number of values in the array is: " << nums.getSize() << endl;
            break;
        case 2:
            cout << "Here is the unsorted list: " << endl;
            for (int i = 0; i < nums.getSize(); i++)
            cout << i << "=>" << nums.getEntry(i) << " ";
            cout << endl;
            break;
        case 3:
            cout << "Enter the index you would like to sort until: ";
            cin >> sortIndex;
            nums.sort(0, sortIndex);
            cout << "Here is the list that was sorted up to your certain index: " << endl;
            for (int i = 0; i < nums.getSize(); i++)
            cout << i << "=>" << nums.getEntry(i) << " ";
            cout << endl;
            break;
        case 4:
            while(lookup != -99)
            {
                cout << "Enter the index you want to look up (-99 to stop): ";
                cin>> lookup;
                if(lookup != -99)
                {
                    cout << "Here is the number on the index " << lookup << ": "
                    << nums.getEntry(lookup) << endl;
                }

            }
            break;
        }
    } while(choice != 5);



    cout << "Enter a character to exit." << endl;
    char wait;
    cin >> wait;
    return 0;
}
