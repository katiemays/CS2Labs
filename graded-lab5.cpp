// JH: 101/100
// JH: Excellent! InitArrayFromInput required to overwrite existing array or create
// JH: a new one if none exists. Missing function header comments. Small indentation
// JH: problems. 
/* Lab5: Practice using struct and dynamic arrays 
 * Author: Katie Mays 
 * Last modifed on: 14 March 2018
 * Known bug: none
 * Note: Please use assert to check for precondtition */

#include <iostream>
#include <assert.h>
using namespace std;

//Define a struct type, each struct type variable has three 
// member variables: array, capacity, and length. Together these
// three variables represent a partially filled array.
struct Array {
	int * array;  // point to the dynamically allocated array 
	int capacity; // the capacity of the array 
	int length;	// the number of elements in the array 
			// the array is filled from 0th, 1st, ... (length-1)-th
			// spots 
};

/* Initialize the array structure with the given numbers.
 * the array's capacity will be twice the length of numbers array 
 @param array: the array struct to be initialized
 @param numbers: the array of values to be stored in the array struct
 @param numbers_len: how many numbers are there in the array numbers
 precondition: "numbers" has been filled with "numbers_len" number of ints
 post condition: a.length == numbers_len
                 a.array[0]==numbers[0],..., 
		 a.capacity = 2*numbers_len
*/
void InitArray (Array & a, int numbers[], int numbers_len); 

/* Displays the content of an int array, both the array and 
   the length of array will be passed as parameters to the function 
   @param array: gives the array to be displayed
*/
void DisplayArray (const Array & a);

//Extra Credit Part: Implement this function, and test in main 
/* Read a sequence of int from input, and store them in the given Array 
 *  variable; we overwrite any existing content of the Array variable
 @param array: the Array variable that is used to store the numbers
 Note: you should allow the user to enter any many numbers as they want,
 the number sequence will be ended with a special value of -1 
 This means that you have to "grow" your array variable when needed 
*/
void InitArrayFromInput (Array & a); 

/* Merge the contents of two arrays into one
 @param array1: the target array
 @param array2: the source array
 @precondition: array1 and array2 have been set up 
 @postcondition: array1.length = array1.length+array2.length;
                 array1 contains its previous numbers, followed by numbers
		from array2 
 Note: if array1's capacity is not enough to hold all numbers, 
   you need to allocate a new int array, and copy old data over to the 
   new array... 
*/
void MergeArray (Array & a1, const Array & a2);

int main()
{
 int numbers1[5]={12, 23,34,56,78};
 int numbers2[11]={89, 7,14,22,98, 101, 112, 34, 11, 5, 99};

 Array NumArray1={NULL,0,0};	//Declare a Array variable, and initilize its member variables 
 Array NumArray2={NULL,0,0};	//Declare another Array variable, and initialize its member variables 
 Array InputArray={NULL,0,0};	//Declare another Array variable for InitArrayFromInput, and init. its member vars	

 cout <<"***** NumArray1:\n";
 DisplayArray(NumArray1);

 cout <<"***** NumArray2:\n";
 DisplayArray(NumArray2);

 InitArray (NumArray1, numbers1, 5);	//Now initialize the two Array variables with numbers from two static arrays
 InitArray (NumArray2, numbers2, 11);

 cout <<"***** NumArray1:\n";
 DisplayArray(NumArray1);
 cout <<"***** NumArray2:\n";
 DisplayArray(NumArray2);

 cout <<"***** After merge:\n";
 MergeArray (NumArray1, NumArray2);	//Now merge the two Arrays and put both contents into first array
 cout <<"***** NumArray1:\n";		
 DisplayArray(NumArray1);

 cout <<"***** EXTRA CREDIT:\n";
 InitArrayFromInput (InputArray);	//Reads in an integer sequence of any size and stores it in InputArray
 cout <<"***** InputArray:\n";
 DisplayArray(InputArray);

//free arrays
delete [] NumArray1.array;
delete [] NumArray2.array;
delete [] InputArray.array;
 
}

//ToDo: Please implement all functions declared above 
/* Displays the content of an int array, both the array and 
   the length of array will be passed as parameters to the function 
   @param array: gives the array to be displayed
*/
void DisplayArray (const Array & a)
{
	for (int i = 0; i < a.length; i++)
		cout << a.array[i] << " ";
	cout << endl;
	
}

/* Initialize the array structure with the given numbers.
 * the array's capacity will be twice the length of numbers array 
*/
void InitArray (Array & a, int numbers[], int numbers_len)
{
   // 1. Dynamically allocate an int array of size given by numbers_len*2
   //    and stores its address in a.array
   //    Set a.capacity 
	a.capacity = 2*numbers_len;
	a.array = new int [a.capacity]; //remember that @param array is a pointer

   // 2. Copy the int numbers from array numbers to a.array
   	for (int i = 0; i < numbers_len; i++)
		a.array[i] = numbers[i];
 
   // 3. set a.length
	a.length = numbers_len;
}

// JH: Missing function header comments
// -2

void MergeArray (Array & a1, const Array & a2) //KM: why is one const and not the other?
{
    if (a1.length + a2.length > a1.capacity)
    { //If a1.array is not big enough to hold all data 
     
// JH: Please indent to the block-level for readability.
// -2
	//1. Allocate a new dynamic int array that is big enough
	//  you can make its size be a1.length+a2.length+10 
	int bigger_capacity = a1.length+a2.length+10;
	int * biggerArray = new int [bigger_capacity];

	// 2. copy numebrs from a1.array to this new array 
	for (int i = 0; i < a1.length; i++)
		biggerArray[i] = a1.array[i];
	
	// 3. free the current a1.array 
	delete [] a1.array;

	//4. make a1.array points to the new array 
	a1.array = biggerArray;

	//5. set a1.capacity to the new array's capacity
	a1.capacity = bigger_capacity;

    }

    //Todo: append a2.array's data into a1.array
    int j = 0; // holds the position of appended value in a2  
    for (int i = a1.length; i < a1.length+a2.length; i++)
    { 
	a1.array[i] = a2.array[j];
	j++;
    }
    //Todo: update a1.length
    a1.length = a1.length+a2.length; 
}
/* Reads in a series of integers from user ended with special value of -1
 * stores value in temp variable then checks for special value,
 * if found, breaks and ends sequence of input
 * if not found, checks if current length of array is over capacity
 * if over capacity, creates a tempArray of capacity double old capacity
 * 	copies all of old array into tempArray, only to copy back into original array
 * 	now with new larger capacity
 * if length < capacity, simply inputs value into index.
 * Frees tempArray at the end.
 */
void InitArrayFromInput (Array & a)
{
// JH: BONUS:
// +10
    a.capacity = 5;			// sets
    a.array = new int [a.capacity];	// dynamically allocate space in memory
    int temp = 0, i = 0;
    Array tempArray = {NULL,0,0};	// initialize

    cout << "Enter a sequence of integers separated by a space, or -1 to end it: ";
    
    	do
    	{
   
	    cin >> temp;

// JH: Test temp != -1 and do the else portion
	    if (temp == -1)	// checks for special value, breaks if found
	    	break;
	    else
	    {
	    	a.length = i+1;
		if (a.length >= a.capacity)
		{
			tempArray.capacity = 2*a.capacity;		//declares a temp array of bigger capacity
			tempArray.array = new int [tempArray.capacity];

			for (int j = 0; j < a.capacity; j++)
				tempArray.array[j] = a.array[j];	//copies all int values from original array into tempArray

			delete [] a.array;				// frees original array
			a.capacity = tempArray.capacity;		// now a.capacity is doubled
// JH: Requirement to overwrite array or allocate a new one.
// JH: This should test for a.array != NULL and delete [] a.array,
// JH: then in either case, set a.array = tempArray.
// -2
// JH: Unnecessary dynamic allocation and copy since it was already done.
// -2
			a.array = new int [a.capacity];			// re-allocates memory of new amount of space

			for (int j = 0; j < a.length; j++)
				a.array[j] = tempArray.array[j];	//copies all values back into original array, now with larger capacity
					
		}
		a.array[i] = temp;	//inputs the value into the position i
	    }
	    i++;	//increment index
// JH: Better to test while temp != -1? 
// -1
	}while (1 == 1); //always true, only breaks loop when -1 is found
//free tempArray
delete [] tempArray.array;   
}
