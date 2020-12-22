/* FILE NAME: Project2
* AUTHOR: Christobel
* See our syllabus for a good comment
*/

#include <iostream>

#include <stdlib.h>

#include <assert.h>

#include <ctime>

using namespace std;

/*

* Input: A_alive indicates Aaron is alive true for alive, false for dead

*   B_alive indicates Bob is alive

*   C_alive indicates Charlie is alive

* Return: true if at least two are alive otherwise return false

*/

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);




/*

* Call by reference

* Strategy 1: Everyone shoots to kill the highest accuracy player alive

* Input: B_alive indicates Bob is alive or dead

*   C_alive indicates Aaron is alive or dead

* Return: Change B_alive into false if Bob is killed

*   Change C_alive into false if Charlie is killed

*/

void Aaron_shoots1(bool& B_alive, bool& C_alive);





/*

* Call by reference

* Input: A_alive indicates Aaron is alive or dead

*   C_alive indicates Charlie is alive or dead

* Return: Change A_alive into false if Aaron is killed

*   Change C_alive into false if Charlie is killed

*/

void Bob_shoots(bool& A_alive, bool& C_alive);




/*

* Call by reference

* Input: A_alive indicates Aaron is alive or dead

*   B_alive indicates Bob is alive or dead

* Return: Change A_alive into false if Aaron is killed

*   Change B_alive into false if Bob is killed

*/

void Charlie_shoots(bool& A_alive, bool& B_alive);






/*

* Call by reference

* Strategy 2: Aaron intentionally misses if both are alive

* Input: B_alive indicates Bob is alive or dead

*   C_alive indicates Aaron is alive or dead

* Return: Change B_alive into false if Bob is killed

*   Change C_alive into false if Charlie is killed

*/

void Aaron_shoots2(bool& B_alive, bool& C_alive);




//Simple method to implement pause function in linux

void Press_any_key(void);

//TEST PROTOTYPES

void test_at_least_two_alive(void);

void test_Aaron_shoots1(void);

void test_Bob_shoots(void);

void test_Charlie_shoots(void);

void test_Aaron_shoots2(void);

//VARIABLES
const int TOTAL_RUNS = 10000;
bool aaronAlive;
bool bobAlive;
bool charlieAlive;
int aaronWins1;
int aaronWins2;
int bobWins;
int charlieWins;
double strategy1;
double strategy2;

int main() {

    //Initializes Random number generator's seed and calls test functions

    cout << "*** Welcome to Chris's Duel Simulator ***\n";

    srand(time(0));

    test_at_least_two_alive();

    Press_any_key();

    test_Aaron_shoots1();

    Press_any_key();

    test_Bob_shoots();

    Press_any_key();

    test_Charlie_shoots();

    Press_any_key();

    test_Aaron_shoots2();

    Press_any_key();

    //Starts strategy 1 and runs 10,000 times

    aaronWins1 = 0;
    bobWins = 0;
    charlieWins = 0;

    cout << "Ready to test strategy 1 (run 10000 times):\n";

    Press_any_key();


    for (int i = 0; i < TOTAL_RUNS; i++ ){

        aaronAlive = true;
        bobAlive = true;
        charlieAlive = true;

        while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
            if ( aaronAlive == true)
                Aaron_shoots1(bobAlive, charlieAlive);

            if (bobAlive == true)
                Bob_shoots(aaronAlive, charlieAlive);

            if (charlieAlive == true)
                Charlie_shoots(aaronAlive, bobAlive);
            

        }

        if (aaronAlive)

            aaronWins1 = aaronWins1 + 1;

        if (bobAlive)

            bobWins = bobWins + 1;

        if (charlieAlive)

            charlieWins = charlieWins + 1;

    }
    strategy1 = aaronWins1 / TOTAL_RUNS * 100;

    cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast<double>(aaronWins1) / TOTAL_RUNS * 100 << "%\n"

        << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS * 100 << "%\n"

        << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / TOTAL_RUNS * 100 << "%\n"

        << endl;

    //Reinitializes variables and starts strategy 2 to run 10,000 times

    aaronWins2 = 0;
    bobWins = 0;
    charlieWins = 0;

    cout << "Ready to test strategy 2 (run 10000 times):\n";

    Press_any_key();

    for (int i = 0; i < TOTAL_RUNS; i++ ){

        aaronAlive = true;
        bobAlive = true;
        charlieAlive = true;

        while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
            if ( aaronAlive == true)
                Aaron_shoots2(bobAlive, charlieAlive);
                
            if (bobAlive == true)
                Bob_shoots(aaronAlive, charlieAlive);

            if (charlieAlive == true)
                Charlie_shoots(aaronAlive, bobAlive);
        }

        if (aaronAlive)

            aaronWins2 = aaronWins2 + 1;

        if (bobAlive)
        
            bobWins = bobWins + 1;

        if (charlieAlive)
        
            charlieWins = charlieWins + 1;
    
    }
    strategy2 = aaronWins2 / TOTAL_RUNS * 100;

    cout << "Aaron won " << aaronWins2 << "/10000 duels or " << static_cast<double>(aaronWins2) / TOTAL_RUNS * 100 << "%\n"

        << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS * 100 << "%\n"

        << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / TOTAL_RUNS * 100 << "%\n"
        
        << endl;


    if (strategy1 > strategy2) {

        cout << "Strategy 1 is better than strategy 2.\n";

    }

    else {

            cout << "Strategy 2 is better than strategy 1.\n";

    }

    return 0;

}


//Implementation of functions. Look above for documentation of them.

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
    if( A_alive == true) {

        return (A_alive && ((B_alive || C_alive) || (B_alive && C_alive)));

    }

    else if ( B_alive == true) {

        return (B_alive && ((A_alive || C_alive) || (A_alive && C_alive)));

    }

    else {
        return false;
    }

}

void test_at_least_two_alive(void) {

        cout << "Unit Testing 1: Function - at_least_two_alive()\n";

        cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
        assert(true == at_least_two_alive(true,true,true));
        cout << "\tCase passed ...\n";

        cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
        assert(true == at_least_two_alive(false,true,true));
        cout << "\tCase passed ...\n";

        cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
        assert(true == at_least_two_alive(true,false,true));
        cout << "\tCase passed ...\n";

        cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
        assert(true == at_least_two_alive(true,true,false));
        cout << "\tCase passed ...\n";

        /*
        cout << "\tCase 5: Aaron dead, Bob alive, Charlie alive\n";
        assert(true == at_least_two_alive(false,false,true));
        cout << "\tCase passed ...\n";

        cout << "\tCase 6: Aaron dead, Bob alive, Charlie alive\n";
        assert(true == at_least_two_alive(false,true,false));
        cout << "\tCase passed ...\n";

        cout << "\tCase 7: Aaron dead, Bob alive, Charlie alive\n";
        assert(true == at_least_two_alive(true,false,false));
        cout << "\tCase passed ...\n";

        cout << "\tCase 7: Aaron dead, Bob alive, Charlie alive\n";
        assert(true == at_least_two_alive(false,false,false));
        cout << "\tCase passed ...\n";
        
        */

}

void Aaron_shoots1(bool& B_alive, bool& C_alive) {

        assert(true == (B_alive || C_alive));

        int shootResult = rand() % 100;

        if (C_alive) {
                if ( shootResult <= 33 ) {
                    
                    C_alive = false;
                }
                else {
                    C_alive = true;
                }

        }

        else {
            if ( shootResult <=33) {
                
                B_alive = false;
            }
            else {
                B_alive = true;
            }

        }

}

void test_Aaron_shoots1(void) {

        cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";

        bool Bob_alive = true;
        bool Charlie_alive = true;

        cout << "\tCase 1: Bob alive, Charlie alive\n";
        Aaron_shoots1(Bob_alive, Charlie_alive);
        cout << "\t\tAaron is shooting at Charlie\n";

        Bob_alive = false;
        Charlie_alive = true;   
        cout << "\tCase 2: Bob dead, Charlie alive\n";
        Aaron_shoots1(Bob_alive, Charlie_alive);
        cout << "\t\tAaron is shooting at Charlie\n";

        Bob_alive = true;
        Charlie_alive = false; 
        cout << "\tCase 3: Bob alive, Charlie dead\n";
        Aaron_shoots1(Bob_alive,Charlie_alive);
        cout << "\t\tAaron is shooting at Bob\n";

}

void Bob_shoots(bool& A_alive, bool& C_alive) {

    assert(true == (A_alive || C_alive));

    int shootResult = rand() % 100;

    if (C_alive) {
            if ( shootResult <= 50 ) {
                
                C_alive = false;
            }
            else {
                C_alive = true;
            }

    }

    else {
        if ( shootResult <=50) {
            
            A_alive = false;
        }
        else {
            A_alive = true;
        }

    }

}

void test_Bob_shoots(void) {
        cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";

        bool Aaron_alive = true;
        bool Charlie_alive = true;

        /*
        cout << "\tCase 1: Bob alive, Charlie alive\n";
        assert( true == Aaron_shoots1(Bob_alive, Charlie_alive));
        cout << "\t\tAaron is shooting at Charlie\n";

        */
        cout << "\tCase 1: Aaron alive, Charlie alive\n";
        Bob_shoots(Aaron_alive, Charlie_alive);
        cout << "\t\tBob is shooting at Charlie\n";


        Aaron_alive = false;
        Charlie_alive = true;
        cout << "\tCase 2: Aaron dead, Charlie alive\n";
        Bob_shoots(Aaron_alive, Charlie_alive);
        cout << "\t\tBob is shooting at Charlie\n";

        Aaron_alive = true;
        Charlie_alive = false;
        cout << "\tCase 3: Aaron alive, Charlie dead\n";
        Bob_shoots(Aaron_alive,Charlie_alive);
        cout << "\t\tBob is shooting at Aaron\n";


}

void Charlie_shoots(bool& A_alive, bool& B_alive) {

    
    assert(A_alive || B_alive);

    int shootResult = rand() % 100;

    if (B_alive) {
            if ( shootResult <= 100 ) {
                
                B_alive = false;
            }

    }

    else {
        if ( shootResult <=100) {
            
            A_alive = false;
        }

    }

}

void test_Charlie_shoots(void) {
        cout << "Unit Testing 4: Function Charlie_shoots1(Aaron_alive, Bob_alive)\n";


        bool Aaron_alive = true;
        bool Bob_alive = true;

        cout << "\tCase 1: Aaron alive, Bob alive\n";
        Charlie_shoots(Aaron_alive, Bob_alive);
        cout << "\t\tCharlie is shooting at Bob\n";

        Aaron_alive = false;
        Bob_alive = true;
        cout << "\tCase 2: Aaron dead, Bob alive\n";
        Charlie_shoots(Aaron_alive, Bob_alive);
        cout << "\t\tCharlie is shooting at Bob\n";

        Aaron_alive = true;
        Bob_alive = false; 
        cout << "\tCase 3: Aaron alive, Bob dead\n";
        Charlie_shoots(Aaron_alive,Bob_alive);
        cout << "\t\tCharlie is shooting at Aaron\n";


}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {

        assert(true == (B_alive || C_alive));

        //int shootResult = rand() % 100;

        if (B_alive && C_alive == true) {
            return;
        }
        
        else {
            Aaron_shoots1(B_alive,C_alive);

        }

}

void test_Aaron_shoots2(void) {
        cout << "Unit Testing 5: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";

        bool Bob_alive = true;
        bool Charlie_alive = true;
        
        cout << "\tCase 1: Bob alive, Charlie alive\n";
        Aaron_shoots2(Bob_alive, Charlie_alive);
        cout << "\t\tAaron intentionally misses his first shot\n";

        Bob_alive = false;
        Charlie_alive = true;
        cout << "\tCase 2: Bob dead, Charlie alive\n";
        Aaron_shoots2(Bob_alive, Charlie_alive);
        cout << "\t\tAaron is shooting at Charlie\n";

        Bob_alive = true;
        Charlie_alive = false;
        cout << "\tCase 3: Bob alive, Charlie dead\n";
        Aaron_shoots2(Bob_alive,Charlie_alive);
        cout << "\t\tAaron is shooting at bob\n";

}

void Press_any_key() {

        cout << "Press any key to continue...";

        cin.ignore().get();

}