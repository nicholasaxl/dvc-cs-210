#include <iostream>

#include <string>

#include <fstream>

using namespace std;

struct NodeType;

typedef NodeType * NodePtr;

struct RecType

{

        long id;

        string fname;

        string lname;

        double amount;

};

struct NodeType

{

        long id;

        string fname;

        string lname;

        double amount;

        NodePtr flink;

        NodePtr blink;

};

class AccountList

{

private:

        NodePtr head;

        NodePtr cursor;

public:

        AccountList ( );

        void addAccountSorted (RecType rec);

        void updateAccount (RecType rec);

        void display(ofstream &lfstream);

};

AccountList::AccountList ( )

{

        head = new NodeType;

        head->id = -1;

        head->fname = "";

        head->lname = "";

        head->amount= -999.999;

        head->flink=head;

        head->blink=head;

        cursor = head;

}

void AccountList::addAccountSorted(RecType rec)

{

        //Create the new node and fill it in.

        NodePtr newPtr = new NodeType;

        newPtr->id = rec.id;

        newPtr->fname = rec.fname;

        newPtr->lname = rec.lname;

        newPtr->amount = rec.amount;

        newPtr->flink = NULL;

        newPtr->blink = NULL;

        //find the Node of point of insertion

        NodePtr cur, prev;

        for (cur=head->flink; cur!=head; cur=cur->flink)

        {

                if (rec.id < cur->id)

                        break;

        }

        //set prev

        prev = cur->blink;

        //update the two forward links

        newPtr->flink=prev->flink;

        prev->flink = newPtr;

        //update the two backward links

        newPtr->blink = cur->blink;

        cur->blink = newPtr;

}

void AccountList::updateAccount(RecType rec)

{

        //move the cursor forward if at dummy node

        if (cursor == head)

                cursor = cursor->flink;

        //cursor is at the target node. do not move it

        if (cursor->id == rec.id)

        {

                //update the account

                              cursor->fname = rec.fname;

                              cursor->lname = rec.lname;

                              if(rec.amount > 0)

                              {

                                             cursor->amount += rec.amount;

                              }

                              else

                              {

                                             cursor->amount += rec.amount;

                              }

                //if the account became zero or negative

                //delete the node and move the cursor forward

                              if(cursor->amount <=0)

                              {

                                             NodePtr temp = cursor;

                                             cursor->blink->flink = cursor->flink;

                                             cursor->flink->blink = cursor->blink;

                                             cursor = cursor->flink;

                                             delete(temp);

                              }

        }

        else if (cursor->id < rec.id)

        {

                while (cursor != head)

                {

                        if (cursor->id >= rec.id)

                                break;

                        cursor = cursor->flink;

                }

                if (cursor->id == rec.id)

                {

                       //update the account

                              cursor->fname = rec.fname;

                              cursor->lname = rec.lname;

                              if(rec.amount > 0)

                              {

                                             cursor->amount += rec.amount;

                              }

                              else

                              {

                                             cursor->amount += rec.amount;

                              }

                              //if the account became zero or negative

                              //delete the node and move the cursor forward

                              if(cursor->amount <=0)

                              {

                                             NodePtr temp = cursor;

                                             cursor->blink->flink = cursor->flink;

                                             cursor->flink->blink = cursor->blink;

                                             cursor = cursor->flink;

                                             delete(temp);

                              }

                }

                else

                {

                              //insert the node prior to where cursor is.

                              NodePtr newPtr = new NodeType;

                              newPtr->id = rec.id;

                              newPtr->fname = rec.fname;

                              newPtr->lname = rec.lname;

                              newPtr->amount = rec.amount;

                              newPtr->flink = NULL;

                              newPtr->blink = NULL;

                              newPtr->blink = cursor->blink;

                              newPtr->flink = cursor;

                              cursor->blink->flink = newPtr;

                              cursor->flink->blink = newPtr;

                }

        }

        else

        {

                while (cursor != head )

                {

                        if (cursor->id <= rec.id)

                                break;

                        cursor = cursor->blink;

                }

                if (cursor->id == rec.id)

                {

                        //update the account

                              cursor->fname = rec.fname;

                              cursor->lname = rec.lname;

                              if(rec.amount > 0){

                                             cursor->amount += rec.amount;

                              }

                              else{

                                             cursor->amount += rec.amount;

                              }

                              //if the account became zero or negative

                              //delete the node and move the cursor forward

                              if(cursor->amount <=0)

                              {

                                             NodePtr temp = cursor;

                                             cursor->blink->flink = cursor->flink;

                                             cursor->flink->blink = cursor->blink;

                                             cursor = cursor->flink;

                                             delete(temp);

                              }

                }

                else

                {

                              NodePtr newPtr = new NodeType;

                              newPtr->id = rec.id;

                              newPtr->fname = rec.fname;

                              newPtr->lname = rec.lname;

                              newPtr->amount = rec.amount;

                              newPtr->flink = NULL;

                              newPtr->blink = NULL;

                              //first move the cursor forward by one

                              cursor = cursor->flink;

                              //This will make it point to the point of insertion node.

                              //Then insert the node prior to where cursor is.

                              newPtr->blink = cursor->blink;

                              newPtr->flink = cursor;

                              cursor->blink->flink = newPtr;

                              cursor->flink->blink = newPtr;

                }

        }

}

//This method receives an ofstream opened for the log file

//as a reference parameter and uses it to write the contents

//of the doubly linked list to the log file.

//This method can be used while performing updates.

void AccountList::display(ofstream & lfout)

{

        for(NodePtr cur = head->flink; cur!=head; cur=cur->flink)

              lfout << cur->id << " " << cur->fname << " " << " " << cur->lname << " "

                      << cur->amount << endl;

}

int main() {

               RecType recType;

               AccountList accounts;

               ofstream lfout ("log.txt");

               string master_file,transaction_file;

               cout<<" Enter the master file :";

               cin>>master_file;

               cout<<" Enter the transaction file :";

               cin>>transaction_file;

               ifstream master_fin(master_file.c_str());

               ifstream transaction_fin(transaction_file.c_str());

               if(master_fin.is_open())

               {

                              while(!master_fin.eof())

                              {

                                             master_fin>>recType.id;

                                             master_fin>>recType.fname;

                                             master_fin>>recType.lname;

                                             master_fin>>recType.amount;

                                             accounts.addAccountSorted(recType);

                              }

                              accounts.display(lfout);

                              if(transaction_fin.is_open())

                              {

                                             while(!transaction_fin.eof())

                                             {

                                                            transaction_fin>>recType.id;

                                                            transaction_fin>>recType.fname;

                                                            transaction_fin>>recType.lname;

                                                            transaction_fin>>recType.amount;

                                                            accounts.updateAccount(recType);

                                             }

                                             accounts.display(lfout);

                              }

                              else{

                                             cout<<" Unable to open "<<transaction_file;

                              }

               }else

                              cout<<" Unable to open "<<master_file;

               master_fin.close();

               transaction_fin.close();

               lfout.close();

}
