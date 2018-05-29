// JH: 94/100
// JH: Excellent! Incorrect bounds checking in Delete. Missing return statement with index in InsertByValue.
// JH: Requirement to implement BinarySearch not Linear or Sequential search. See inline comments.
// JH: BONUS: +5 iterator, +5 sort. 
//
/* Lab3: working with sorted array
 * Author: Katie Mays 
 * Last modifed on: 27 Feb 2018
 * Known bug: none
 * Note: Please use assert to check for precondtition */
#include <iostream>
#include <assert.h>
#include <vector>
#include <string>
using namespace std;

const int CAPACITY=20;

/* Displays the content of a vector<string>,
   @param vector<string>: gives the vector<string> to be displayed
*/
void DisplayVector (vector<string> vstrings);

/*
  Binary search a vector of string for a given value, return true if found, false if not found 
  the index or would-be index of the value will be set to param index
   @param vstrings: gives the vector<string> to be displayed
   @param value: the value we are looking for 
   @param index: upon return, store the index of the occurence of the value (if found),
		or the would-be index of the value (if it's not found) 
   @precondition: vector contains vector.size() number of values in asceoding order 
   @postcondition: if value appeared in the array, its index is returned; otherwise -1 is returned 
*/
bool BinarySearch (vector<string> vstrings, string value, int & index);

/* 
 Deletes (i.e., removes) the element stored in the specified position from the SORTED vector, the 
 vector should be sorted afterwards
   @param vector: gives the vector to be deleted from
   @param index: we want to delete the {index}-th position in the vector 
   @precondition: vector contains vector.size() number of values in asceoding order 
        index < vector.size()
   @postcondition: if value stored in {index}-th position will be removed, the vector is still sorted. 
           vector.size() is decreased by 1
*/
void Delete (vector<string> & vstrings, int index);

/*
 * Deletes (i.e., removes) the element value by first searching for it and then deleting
 * if found. Uses BinarySearch(vector<string> vstrings, string value, int &index) to get
 * the index to pass into Delete(vector<string>, int index).
 * @param vector: gives the vector to be deleted from
 * @param string: we want to delete this value from the vector.
 * @precondition: vector contains vector.size() number of values in ascending order
 * @postcondition: if value is stored in vector, it will be removed, the vector will still be sorted.
 * 		vector.size() is decreased by 1.
 */
void Delete (vector<string>& vstrings, string value, int & index);

/* 
  inserts a value into an sorted vector so that the vector remains sorted,
  i.e., the value should be inserted before the first value that is 
  larger than it.  If the vector's content is "ann" "becky" "charlotte" "karen",
  and the value to be inserted into the vector is "julie", it should be put right
  before "karen", and the resulting vector should be "ann" "becky" "charolette"
  "julie" "karen" (assume all input is converted to lower case)
  @param vstrings: the vector that the value is to be inserted into
  @param value: the value to be inserted 
  @return: the index of the value in the vector 
  @precondition: vector.size() < vector.capacity() grow the vector 
  @postcondition: value is inserted into the vector, and the vector is sorted 
             vector.size() is incremented by 1.
 */ 
int InsertByValue (vector<string>& vstrings, string value);

/*
 * BONUS:
 * Void function that sorts a string vector of any size into ascending order in ascii.
 * Does not change the size, only orders the string elements alphabetically.
 * Assumes all input is in lower case.
 * @param another_vector: another vector that is unsorted and needs to be sorted
 * @precondition:  vector elements passing through are string values
 * @postcondition: vector is sorted in ascending order, no elements are added or removed
 */
void Sort (vector<string>& another_vector);

int main()
{
 	// As the NumArray can be partially filled, we use variable NumArraySize to keep track of how many numbers
	// have been stored in the array. 
	vector<string> vstrings;	// a string vector, initially empty, containts 0 strings
	string value;
	int index;

	//1. Fill vector<string> with data in sorted order 
	//       Display the array afterwards 
	// Create an sorted array 
	string temp_str;
	do {
		cout << "Enter another name or -1 to end input: ";
		cin >> temp_str;
	
		if (temp_str != "-1") {
			InsertByValue(vstrings, temp_str);
		}
 	} while (temp_str != "-1");

	DisplayVector(vstrings);

  //2. TODO: Prompt the user to enter a value to search for, search for the value, and 
  // report the result 
	cout << "Please enter a value to search for : ";
	cin  >> value; 
// JH: Missing if-statement for BinarySearch result to say if found or not found.
// -2
	BinarySearch(vstrings, value, index);
	cout << "The value " << value << " was found at position " << index << endl;

  // 3. ToDo: Call your function to insert a value (entered by the user) into the vector
  //
  // Display the content of the vector afterwards 
	cout << "Please enter a value to insert into the vector : ";
	cin  >> value;
	InsertByValue(vstrings, value);
	DisplayVector(vstrings);

  // 4. ToDo: Prompt the user to enter an index (for the value to be deleted), and then delete the elements 
  //   stored there. 
  // Display the content of the vector after the deletion. 
	cout << "Please enter position of value to be deleted : ";
	cin  >> index;
	Delete(vstrings, index);
	DisplayVector(vstrings);

  // 5. ToDo: Prompt the user to enter an value in the vector (to be deleted), and then delete the element 
  // Display the contents of the vector after the deletion.
	cout << "Please enter a value to be deleted : ";
	cin  >> value;
	Delete(vstrings, value, index);
	DisplayVector(vstrings);

  // BONUS: implement sorting vector.
	cout << endl;
	cout << "*****BONUS*****\n";
 	vector<string> another_vector={"becky","ann","karen","julie", "frances"};
 
  //6. ToDo: call you sorting function to sort another_vector into ascending order 
	cout << "Sorted another_vector : \n";
	Sort (another_vector);
	DisplayVector(another_vector);
}


//TODO: Implement all functions, i.e., write the function definitions here ... 

/* Displays the content of a vector<string>,
   @param vector<string>: gives the vector<string> to be displayed
*/
void DisplayVector (vector<string> vstrings)
{
// JH: BONUS
// +5
	// uses for-loop to iterate and display. BONUS: Use iterator vstrings.begin and vstrings.end
	for (vector<string>::iterator i=vstrings.begin(); i != vstrings.end(); i++)
		cout << *i << " ";
	cout << endl;
}


/*
  Binary search a vector of string for a given value, return true if found, false if not found 
  the index or would-be index of the value will be set to param index
   @param vstrings: gives the vector<string> to be displayed
   @param value: the value we are looking for 
   @param index: upon return, store the index of the occurence of the value (if found),
		or the would-be index of the value (if it's not found) 
   @precondition: vector contains vector.size() number of values in asceoding order 
   @postcondition: if value appeared in the array, its index is returned; otherwise -1 is returned 
*/
bool BinarySearch (vector<string> vstrings, string value, int & index)
{
	int i;
	bool found = false;
// JH: Requirement is for a BinarySearch. Not a Linear or Sequential search.
// -6

	for (i=0; i<vstrings.size(); i++)
	{
		if (value == vstrings[i])
		{
			found = true;
			break;
		}
	} 

	if (found == true)
		index = i;
	else
		index = -1;
}

/* 
 Deletes (i.e., removes) the element stored in the specified position from the SORTED vector, the 
 vector should be sorted afterwards
   @param vector: gives the vector to be deleted from
   @param index: we want to delete the {index}-th position in the vector 
   @precondition: vector contains vector.size() number of values in asceoding order 
        index < vector.size()
   @postcondition: if value stored in {index}-th position will be removed, the vector is still sorted. 
           vector.size() is decreased by 1
*/
void Delete (vector<string>& vstrings, int index)
{
	// uses vector.erase(index)	
// JH: Bounds checking should be: index >= 0 && index < vstrings.size()
// -4
	if (index < vstrings.size()+1)
		vstrings.erase(vstrings.begin()+index);
}

/*
 * Deletes (i.e., removes) the element value by first searching for it and then deleting
 * if found. Uses BinarySearch(vector<string> vstrings, string value, int &index) to get
 * the index to pass into Delete(vector<string>, int index).
 * @param vector: gives the vector to be deleted from
 * @param string: we want to delete this value from the vector.
 * @precondition: vector contains vector.size() number of values in ascending order
 * @postcondition: if value is stored in vector, it will be removed, the vector will still be sorted.
 * 		vector.size() is decreased by 1.
 */
void Delete (vector<string>& vstrings, string value, int & index)
{
	// BinarySearch to get index and vector.erase(index) to delete
	BinarySearch(vstrings, value, index);
	if (index != -1)
		Delete(vstrings, index);
}

/* 
  inserts a value into an sorted vector so that the vector remains sorted,
  i.e., the value should be inserted before the first value that is 
  larger than it.  If the vector's content is "ann" "becky" "charlotte" "karen",
  and the value to be inserted into the vector is "julie", it should be put right
  before "karen", and the resulting vector should be "ann" "becky" "charolette"
  "julie" "karen" (assume all input is converted to lower case)
  @param vstrings: the vector that the value is to be inserted into
  @param value: the value to be inserted 
  @return: the index of the value in the vector 
  @precondition: vector.size() < vector.capacity() grow the vector 
  @postcondition: value is inserted into the vector, and the vector is sorted 
             vector.size() is incremented by 1.
 */ 
int InsertByValue (vector<string>& vstrings, string value)
{
	// Uses for-loop to find the vector enter that is greater than value
	// if we get to the end, do vector.push_back(value) otherwise use
	// vector.insert(vector.begin()+index, value);

	int i=0;
	
	for (i=0; i < vstrings.size(); i++)
	{
		if (value < vstrings[i])
		{	
			vstrings.insert(vstrings.begin()+i, value);
// JH: Missing return i;
// -2
			break;
		}
	}

	if (i == vstrings.size())
		vstrings.push_back(value);
// JH: Missing return i;
// -2
}

/*
 * BONUS:
 * Void function that sorts a string vector of any size into ascending order in ascii.
 * Does not change the size, only orders the string elements alphabetically.
 * Assumes all input is in lower case.
 * @param another_vector: another vector that is unsorted and needs to be sorted
 * @precondition:  vector elements passing through are string values
 * @postcondition: vector is sorted in ascending order, no elements are added or removed
 */
void Sort (vector<string>& another_vector)
{
	int i, j;
// JH: BONUS
// +5
	for (i=0; i < another_vector.size(); i++)
	{
		string alpha = another_vector[i]; //begin by assuming first value is smallest value in ascii, set as alpha

		for (j=i+1; j < another_vector.size(); j++) //test next position against previous, if found smaller than previous, swap values
		{
			if (another_vector[j] < alpha)
			{
				string temp_str;

				temp_str = another_vector[i];
				another_vector[i] = another_vector[j];
				another_vector[j] = temp_str;

				alpha = another_vector[i]; //now set minimum again as newly swapped smallest value
			}
		}
	}
}
