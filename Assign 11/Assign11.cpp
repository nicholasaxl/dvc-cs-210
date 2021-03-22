#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

//structure definition
struct RecType
{
	int id;
	string first_name;
	string last_name;
};

//class StudentHT declaration
class StudentHT
{
public:
	struct NodeType
	{
		int id;
		string fname;
		string lname;
		NodeType *nextNode;
	}
	struct NodeType **hashPtr;
}

//Hash table size declarations
int table_Size;
int num_node_Search;
int num_id_Search;
double avg_searches;

//Constructor to initialize the hash table
StudentHT(int htSize)
{
	table_Size = htSize;
	//create array for initialization
	hashPtr = new NodeType*[table_Size];
	//initialize the pointers
	for (int i = 0; i < table_Size; i++)
	{
		hashPtr[i] = NULL;
	}
}

//compute hash value for the ID
int hashfunction(int studentID)
{
	//hashing function
	int hashValue = studentID % table_Size;
	return hashValue;
}

//insert node into hash table
void insert(RecType item)
{
    //calculate hash and store it into the table
    int hashValue = hashFunction(item.id);
    struct NodeType * newItem = new struct NodeType;
    //Copy the item into NodeType
    newItem->id = item.id;
    newItem->fname = item.first_name;
    newItem->lname = item.last_name;
    newItem->nextNode = NULL;

	//if it is the first entry in the hash table
	if (hashPtr[hashValue] == NULL)
    {
        hashPtr[hashValue] = newItem;
    }
	else
	{
		//reinsert the node into the linkedlist
		struct NodeType *temp = hashPtr[hashValue];
		while(temp->nextNode != NULL)
		{
			temp = temp->nextNode;
		}
		temp->nextNode = newItem;
	}
}

//implement search function
RecType search(RecType item)
{
	num_id_Search++;
    int hashValue = hashFunction(item.id);

    // search the item
    RecType *itemSearch = new RecType;
    if (hashPtr[hashValue] != NULL)
    {
        struct NodeType *temp = hashPtr[hashValue];

        temp = hashPtr[hashValue];
        while (temp != NULL)
        {
            //Increment number of node searches
            num_node_Search++;
            if (temp->id == item.id)
            {
                itemSearch->id = temp->id;
                itemSearch->first_name = temp->fname;
                itemSearch->last_name = temp->lname;
                return *itemSearch;
            }
            temp = temp->nextNode;
        }
    }

    // return item with id -1   
    itemSearch->id = -1;
    return *itemSearch;
}

//implement startStatistics
//to set variables to 0
void startStatistics()
{
    // Initialisation
    num_id_Search = 0;
    num_node_Search = 0;
    avg_searches = 0;
}

//implement method to end the statistics
//compute average
void endStatistics()
{
    // calculate avg searches
    avg_searches = (double)num_node_Search / num_id_Search;
}

//display statistics
void displayStatistics()
{
    cout << "=============================================================" << endl;
    cout << "Total number if id's searched : " << num_id_Search << endl;
    cout << "Total number of nodes searched : " << num_node_Search << endl;
    cout << "Average number of nodes search per id searched : " << avg_searches << endl;
    cout << "=============================================================" << endl;
   }
};


