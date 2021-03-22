#include <iostream>
using namespace std;

/** Disclaimer, I found that the solution in the sample output resolves with all the disks
being placed in the 2nd tower. I wrote this assuming that the sample code was wrong and what
you really wanted was to have all the disks be moved to the 3rd tower rather than the 2nd.

If you actually wanted to move all the disks to the 2nd tower, simply swap all the 'post2' with 'post3'
within the void play function.
**/

//function prototype
void Play(int diskNum, char A, char B, char C);


int main()
{
    //declaration of variables
    int diskNum;
    char A = 'A';
    char B = 'B';
    char C = 'C';

    //output to declare the user input
    cout << "Enter a number of disks to play. I'll give necessary moves." << endl;
    cout << "Number of disks: ";
    //user input for the amount of disks to be played
    cin >> diskNum;

    //recursive function call
    Play(diskNum, A, B, C);

    return  0;
}

void Play(int diskNum, char post1, char post2, char post3)
{
    //base case
    if(diskNum == 0)
        return;

    //the real function
    if(diskNum > 0)
    {
        //function call that involves using the statement form the first hint
        /**
        If you could move n-1 of the disks from the first post to the third post using the
        second post as a spare, the last disk could be moved from the first post to the second post.
        **/
        Play(diskNum-1, post1, post3, post2);

        //output for instruction
        cout << "Move a disk from post " << post1 << " to post " << post3 << endl;

        //function call that involves the statement form the 2nd part of the hint
        /**
        Then by using the same technique (whatever that may be) you can move then-1 disks
        from the third post to the second post, using the first disk as a spare.
        **/
        Play(diskNum-1, post2, post1, post3);

        /**
        Basically, the it is in the formula of (number, move, using, to)
        where number is the amount of disks in the first post left, move is where you
        are moving the disk, using is the spare tower being used and to is the final destination of the movement.
        **/

    }
}


