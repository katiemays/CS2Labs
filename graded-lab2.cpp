// JH: 92/100
// JH: Great job! Please provide comments for functions headers and prototypes
/* Katie Mays
 * Jan 31 2018
 * Lab 2: Working with arrays and functions 
 */

#include <iostream>

using namespace std;

// JH: Please provide comments for function defintions and prototypes
// -2

// PROTOTYPES
void CurrentArray (int a[], int a_size); 
int Search (int a[], int a_size, int val);
int InsertValue (int a[], int& a_size, int val, int index); 
int DeleteValue (int a[], int& a_size, int index);
void SwapValues (int a[], int& i, int& j);
void ReverseArray (int a[], int a_size, int& i, int& j);

// GLOBAL VARIABLE
const int CAPACITY = 20;

int main()
{
	// VARIABLES
	// As the NumArray can be partially filled, we use variable NumArraySize to keep track of how many numbers
  	// have been stored in the array. 
  	int NumArray[CAPACITY];	// a int array with a given capacity
  	int NumArraySize=0;  // the array is initially empty, i.e., contains 0 elements
	int temp; // variable to store temporary values, i.e. checks for -1
	int value, index; // used when inserting and deleting in an array
	int i, j;

  	//1. Prompt the user to enter a sequence of integer values, separated by space, and ended with -1,
  	//         and store the values in the array 
  	// 	   and display the array afterwards 
  	cout << "1. Enter a sequence of integer values \n" 
	     << "2. No more than 20 \n"
	     << "3. Separated each with a space \n"
	     << "4. Denote the end of your sequence with '-1'" << endl;

	for (int i = 0; i < CAPACITY; i++)
	{
	   cin >> temp;

	   if (temp >= 0)
	   {
	      	NumArray[i] = temp;
		NumArraySize++;
	   }
	   else
	   	break;   
	}
	cout << "You entered : " << endl;	
	CurrentArray(NumArray, NumArraySize);

  	// 2. Call your function to search for value 50. 
	cout << "The value 50 was found at position " << Search (NumArray, NumArraySize, 50) << " in the array.\n";
 
  	// 3. Call your function to append a value (entered by the user) to the array 
  	//    and display the content of the array afterwards 
	cout << "Enter a value to be appended into the array : ";
	cin  >> value;
	cout << "The value " << value << " was appended at position " << InsertValue(NumArray, NumArraySize, value, NumArraySize) << " in the array.\n"; 

	CurrentArray(NumArray, NumArraySize);

  	// 4. Call your function to insert a value (entered by the user) to a given position (entered by the user) 
  	//    of the array and display the content of the array afterwards 
	cout << "Enter the position where you would like to insert a value : ";
	cin  >> index;
	cout << "Enter the value you would like to insert here : ";
	cin  >> value;
 	cout << "The value " << value << " was inserted at position " << InsertValue(NumArray, NumArraySize, value, index) << " in the array.\n";

	CurrentArray(NumArray, NumArraySize);


 	// 5. Call your function to delete the values stored in position 0 and 2
  	//    and display the content of the array after the deletion. 
	cout << "The value at position " << DeleteValue(NumArray, NumArraySize, 0) << " in the array was deleted.\n";
	CurrentArray(NumArray, NumArraySize);

	cout << "The value at position " << DeleteValue(NumArray, NumArraySize, 2) << " in the array was deleted.\n";
	CurrentArray(NumArray, NumArraySize);

  	// 6. Call your function to reverse the array.
	ReverseArray (NumArray, NumArraySize, i, j);
	CurrentArray(NumArray, NumArraySize);

	return 0;
}

//TODO: Implement all functions 
void CurrentArray (int a[], int a_size) 
{
         for (int i = 0; i < a_size; i++)
         {
            cout << a[i] << " ";
         }
         cout << endl;
	 cout << endl;
}
int Search (int a[], int a_size, int val)
{
	for (int i = 0; i < a_size; i++)
	{
	   if (a[i] == val)
		return i;
	}
	
	return -1;	
}
int InsertValue (int a[], int& a_size, int val, int index) 
{
	// check if array is already full and no more values can be inserted
	// index must be less than the size of the array
	if (a_size >= 20)
		return -1;
	else
	{
// JH: Test index >= 0 && index < size for delete.
// -2
	   for (int i = a_size-1; i >= index; i--)
	   {
		a[i+1] = a[i];
	   }
	
	   a[index] = val;
	   a_size++;
	}
	
	return index;
}
int DeleteValue (int a[], int& a_size, int index)
{
	// check if index value is valid

// JH: Did not require bounds checking because no user input of index
// JH: Test both bounds index >= 0 && index < a_size

	if (index > a_size)
		return -1;
	else
	{
	   for (int i = index; i < a_size; i++)
	   {
		a[i] = a[i+1];
	   }
	   
	   a_size--;
	}
	
	return index;
}
// JH: Requirement to implement swap function with two integer parameters using call-by-reference
// -4
void SwapValues (int a[], int& i, int& j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	j--;
}
void ReverseArray (int a[], int a_size, int& i, int& j)
{
	int middle;
	j = a_size-1;

	if (a_size % 2 == 0)
		middle = a_size/2;
	else
		middle = a_size/2+1;
		
	for (i = 0; i < middle; i++)
		SwapValues(a, i, j);
}
