#include<iostream>
#include<string>
using namespace std;

//declaration for the employee structure
struct employee
{
    //declaring the datas that can be held within the structure
    string name;
    double hours[5]; //array in a structure that can hold up to 5 values
    double rate;
    double payment;
};


//function prototypes
void initialize(employee *e,int size);
void compute(employee &e);
void result(employee e);


int main()
{
    employee e[4]; //array of the amount of employee data that will be initialized from the structure
    initialize(e,4); //initializing the data
    for (int i = 0; i < 4; i++) //general for loop
    {
       compute(e[i]); //calling the compute function
    }

    for (int i = 0; i < 4; i++)
    {
       result(e[i]); //calling the result function
    }
    return 0;
}


void initialize(employee *e, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the last name of the employee: ";
        cin >> e[i].name; //user input for the employee name
        for (int j = 0; j < 5; j++) //for loop to get the 5 days' data
        {
            cout << "Enter " << e[i].name << "'s working hour for day "<<(j+1)<<": ";
            cin >> e[i].hours[j]; //user input for the hours worked for the days
        }
        cout << "Enter " << e[i].name << "'s pay rate per hour: ";
        cin >> e[i].rate; //user input for the pay rate
    }
}


void compute(employee &e)
{
    e.payment = 0; //initial declaration for the addition
    double workhours = 0;;
    for (int i = 0; i < 5; i++)
    {
        workhours += e.hours[i];
    }
    //if function for when the hours are above 40
    if (workhours <= 40)
    {
        e.payment += workhours* e.rate;
    }
    //everything else
    else
    {
        e.payment += (40 * e.rate) + ((workhours - 40) * (1.5 * e.rate));
    }
}

//function to display the result
void result(employee e)
{

    cout << "Last Name: " << e.name
    << "    Paycheck: $" << e.payment << endl;
}
