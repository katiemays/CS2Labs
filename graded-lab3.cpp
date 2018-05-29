// JH: 94/100
// JH: Extra delete of static array labs. Expected search dialog in function.
/*********************************************************************
 Lab3.cpp

   This program uses dynamic arrays to store login information for
four labs.  Each of the four labs is referenced by the labs[] array
which is indexed from 0-3.  A pointer in the labs[] array then
references a dynamic array that is of size for however many computers
are in that lab.

Written by: Katie Mays 
Last modified on: 15 Feb 2018
Known bugs: core dump when user inputs '0' to quit, unknown if error is in free array function 
// JH:
// JH: Due to extra delete of static array labs
*********************************************************************/

#include <iostream>

using namespace std;

// Type definition
typedef int* IntPtr;

// Constants
const int NUMLABS = 4;

// Function prototypes

/*
 Creates the dynamic arrays for the labs.
 @param labs: the array of labs,
 @param labsizes: contains the size (or number of computers) of each lab
  This dictates the size of the dynamic array.
 @precondition: labsize[0] is the # of computers in lab1,
                labsize[1] is the # of computers in lab2, ...
 @postcondition: labs[0] points to lab1's array (of size given by labsize[0])
      labs[1] points to lab2's array (of size given by labsize[1])
        ...
*/
void createArrays(IntPtr labs[], int labsizes[]);


/* 
freeArrays:
Releases memory we allocated with "new".
*/
void freeArrays(IntPtr labs[]);


/*
showLabs:
Displays the status of all labs (who is logged into which computer).
*/
void showLabs(IntPtr labs[], int labsizes[]);


// ======================
// login:
// Simulates a user login by asking for the login info from
// the console.
// ======================
void login(IntPtr labs[], int labsizes[]);


// ======================
// logout:
// Searches through the arrays for the input user ID and if found
// logs that user out.
// ======================
void logout(IntPtr labs[], int labsizes[]);


// ======================
// search:
// Searches through the arrays for the input user ID and if found
// outputs the station number.
// ======================
void search(IntPtr labs[], int labsizes[], int value);


// ======================
//     main function
// ======================
int main()
{
	// automatic variables
	IntPtr labs[NUMLABS]; 	// store the pointers to the dynamic array for each lab
	int labsizes[NUMLABS];	// Number of computers in each lab
	int choice = -1;
	int value; // used in search function, stores the user-inputed value of ID number user is searching for 
	
	// welcome message
	cout <<"Welcome to the LabMonitorProgram!\n";

	// Prompt the user to enter labsizes 
	cout <<"Please enter the number of computer stations in each lab:\n"; 
	for (int i=0; i< NUMLABS; i++)
	{
		do
		{
			cout <<"How many computers in Lab "<< i+1<<"? : ";
			cin >> labsizes[i]; 
		} while (labsizes[i]<0); 
	}

	// Create ragged array structure
	createArrays(labs, labsizes);

	// Main Menu
	do
	{
		cout << endl;
		showLabs(labs, labsizes);

		cout << "MAIN MENU" << endl;
		cout << "0) Quit" << endl;
		cout << "1) Simulate login" << endl;
		cout << "2) Simulate logout" << endl;
		cout << "3) Search" << endl;
	
		cin  >> choice; // read in user choice from main menu
		if (choice == 0)
		{
			freeArrays(labs);
		}
		else if (choice == 1)
		{
			login(labs, labsizes);
		}
		else if (choice == 2)
		{
			logout(labs, labsizes);
		}
		else if (choice == 3)
		{
// JH: See logoff code for dialog, should be very similar.
// -2
			cout << "Please enter an ID # you'd like to search for : ";
			cin  >> value;
			search(labs, labsizes, value);
		}
	
	} while (cin >> choice);
	
	return 0;
}


/* createArrays: for each of the pointers in lab array, allocates dynamic memory
 * 	adjusts needed size based on the user-inputed size for each array lab[i] points to
 * 	also initializes all computer station ID numbers to -1, as they are not in use (empty)  
 */
void createArrays(IntPtr labs[], int labsizes[])
{
	for (int i=0; i < NUMLABS; i++)
	{
		int size = labsizes[i];
		labs[i] = new int [size];
		
		for (int j=0; j < size; j++)
			labs[i][j] = -1;
	}

}
/* freeArrays: deletes the dynamic memory created in creatArrays() by new operator with delete operator
 * 	first deletes the arrays that the pointers in labs array points to, then deletes labs array
 */
void freeArrays(IntPtr labs[])
{
	for (int i=0; i < NUMLABS; i++)
		delete [] labs [i];

// JH: Extra delete of static array.
// -4
	delete [] labs; 
}

/* showLabs: displays the current users logged on to the available computer stations
 * 	if an available computer is not in use, displays 'empty'
 * 	if an available computer is in use, displays the User ID # occupying it
 * 	displays the stations with two nested for loops, displaying first the columns (stations)
 * 	by incrementing 'j', then increments the rows (labs) with 'i' and repeats
 */
void showLabs(IntPtr labs[], int labsizes[])
{

	int i;
	int j;

	cout << "LAB STATUS" << endl;
	cout << "Lab #     Computer Stations" << endl;
	for (i=0; i < NUMLABS; i++)
	{
		cout << i+1 << "         ";
		for (j=0; j < labsizes[i]; j++)
		{
			cout << (j+1) << ": ";
			if (labs[i][j] == -1)
			{
				cout << "empty ";
			}
			else
			{
				cout << labs[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
	return;
}

/* login: extracts user ID, lab, and station number and if computer is available
 * 	changes value from -1 (empty) to the user id number at labs[lab][station]
 * 	if computer is unavailable, prompts user with error message and reads in again
 */
void login(IntPtr labs[], int labsizes[])
{
	int id, lab, num = -1;

	// read user id 
	do
	{
  		cout << "Enter the 5 digit ID number of the user logging in:" << endl;
		cin >> id;
	} while ((id < 0) || (id > 99999));

	// read the lab number 
	do 
	{
		cout << "Enter the lab number the user is logging in from (1-" <<
			NUMLABS << "):" << endl;
		cin >> lab;
	} while ((lab <= 0) || (lab > NUMLABS));

	//read computer number 
	do
	{
		cout << "Enter computer station number the user is logging in to " <<
			"(1-" << labsizes[lab-1] << "):" << endl;
		cin >> num;
	} while ((num <= 0) || (num > labsizes[lab-1]));

	// Check to see if this station is free
	if (labs[lab-1][num-1]!=-1)
	{
		cout << "ERROR, user " << labs[lab-1][num-1] <<
			" is already logged into that station." << endl;
		return;
	}
	// Assign this station to the user
	labs[lab-1][num-1] = id;
	return;
}

/* logout: checks for valid id number, then moves through labs to match user id number to value
 * 	if iteration finds value, user id is switched to -1 (empty) and user is now logged off
 * 	if iteration does not find the value, outputs a message and returns	
 */
void logout(IntPtr labs[], int labsizes[])
{
	int id, i,j;

	// Get input from the keyboard, validating data ranges
	do
	{
  		cout << "Enter the 5 digit ID number of the user to find:" << endl;
		cin >> id;
	} while ((id < 0) || (id > 99999));

	
	for (i=0; i<NUMLABS; i++) // check for each lab 
	{
		for (j=0; j<labsizes[i]; j++) //if the user is using any computer in the lab
		{
			if (labs[i][j]==id) //if so, log the user off... 
			{
				// Log the user off by setting the entry to -1
				labs[i][j] = -1;
				cout << "User " << id << " is logged off." << endl;
				return;
			}
		}
	}
	cout << "That user is not logged in." << endl;
	return;
}

/* search: initial boolean expression set to false
 * 	iteration to find if extracted value is in the 2D array
 * 	if found, boolean expression becomes true and location of user id # is ouputted
 * 	and function breaks, if not found, outputs message
 */
void search(IntPtr labs[], int labsizes[], int value)
{
	bool found = false; // initialize to false until value is found 

// JH: Expecting similar code to logout function
	for (int i=0; i < NUMLABS; i++)
	{
		int size = labsizes[i]; 

		for (int j=0; j < size; j++)
		{	
			if (labs[i][j] == value)
			{
				found = true; // value has been found
				cout << "User currently at Lab " << i+1 << ", Station " << j+1 << endl;
				break;
			}
		}
	}
	if (found == false)	
		cout << "User not found" << endl;
}

