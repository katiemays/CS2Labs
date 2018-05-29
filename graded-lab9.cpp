//JH:------------------------------------------------------
//JH: 103/100 - Excellent!
//JH: +18 :BONUS: operator- and operator%, operator==
//JH: -5 operator= needs to set max_sequence to avoid core dump
//JH: -5 operator== does substr not equality
//JH: -5 BONUS test didn't follow main program requirements
//JH:----------------------lab9.cpp----------------------------
/* Katie Mays
 * 5/7/2018
 * Main program for dna strand
 */

#include "dnasequence.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () 
{
    char answer, num; //for do-while loop
    int max_seq; //more like max bases
    int num_seq; //num of DNA sequence strings
    DNASequence a, b, big_strand, *ptrToSeq; //objects

    //welcome message
    cout << "Welcome to CRISPR" << endl;

    do {
	cout << "  Enter the number of DNASequences to be entered : ";
	cin  >>	num_seq;

	ptrToSeq = new DNASequence[num_seq];

	for (int i=0; i<num_seq; i++)
	{
	   cout << "Enter the DNASequence : ";
	   cin  >> ptrToSeq[i];
	   big_strand = big_strand + ptrToSeq[i]; 
	}
	
	cout << "big_strand = " << big_strand << endl;
	cout << "Would you like to process another big_strand (Y/N) ";
	cin  >> answer;
    } while (answer == 'Y' || answer == 'y');
    //program separated into two parts, big strand and sequence editing
    do { 
	cout << "                             Enter first sequence: ";
	cin  >> a;

	cout << "                            Enter second sequence: ";
	cin  >> b;
   	
	cout << "             ************" << endl;
        cout << "	     * 	==  : 1 *" << endl;
  	cout << "	     *	!=  : 2 *" << endl;
 	cout << " 	     *	 -  : 3 *" << endl;
	cout << " 	     *	 %  : 4 *" << endl;
	cout << "             ************" << endl;
	cout << " Enter the corresponding # for the desired action: ";
	cin  >> num;

	switch (num)
	{
	   case '1':
		if (a==b)
		  cout << b << " was found in " << a << endl;
		break;
	   case '2':
		if (a!=b)
		  cout << b << " was not found in " << a << endl;
		break;
	   case '3':
		a = a-b;
		cout << "Cleaned sequence : " << a << endl;
		break;
	   case '4':
		a = a%b;
		cout << "Cleaned sequence : " << a << endl;
		break;
	}

	cout << "Would you like to compare another set of sequences? (Y/N) : ";
	cin  >> answer;
    } while (answer == 'Y' || answer == 'y');

    cout << "Thank you for using CRISPR, goodbye!" << endl;
}
//JH:----------------------dnasequence.h---------------------------
//author : katie mays
//last mod: 5/7/18

#include <iostream>
#include <string>

#ifndef _DNASEQUENCE_
#define _DNASEQUENCE_

// class DNASequence 
//
// A class that contains a sequence of nucleotides in the dna_sequence.
// The max_sequence represents the capacity of the dna_sequence.
// A dna_sequence is a c-string of characters that consist only of
// 'A', 'T', 'G', 'C' standing for the 4 nucleotides and ending in a '\0'
// character. Input into the DNASequence is case-insensitive meaning that
// lower or upper case is acceptable, but it should be converted to uppercase
// internally.
//
using namespace std;

class DNASequence {
	public:
		DNASequence(); 
		// Assume that the strand is initialized to a max_length of 20 nucleotides.
		// Add an extra character for '\0'.

		DNASequence(const string nucleotides);
		// Assume that the sequence is initialized to the nucleotides string.
		// Add an extra character for '\0'.

		DNASequence(const DNASequence& arg);
		// Copy constructor makes a deep copy
		// Add an extra character for '\0'.

		~DNASequence();
		// Destructor

		DNASequence& operator=(const DNASequence& arg);
		// Assignment operator makes a deep copy

		bool operator==(const DNASequence& arg);
		// Equals operator compares the given sequence with the invoking (lhs) object.

		bool operator!=(const DNASequence& arg);
		// Not equals operator compares the given sequence with the invoking (lhs) object.

		friend DNASequence operator+(const DNASequence& arg1, const DNASequence& arg2);
		// Return a DNASequence with the second operand appended to the first operand.

		friend DNASequence operator-(const DNASequence& arg1, const DNASequence& arg2);
		// Return a DNASequence with the first occurance of the second operand removed
		// from the first operand. If the given sequence is not found, return a copy of
		// first operand.

		// EXTRA CREDIT: +5
		friend DNASequence operator%(const DNASequence& arg1, const DNASequence& arg2);
		// Return a DNASequence with every occurance of the second operand removed from
		// the first. If the given sequence is not found, return a copy of the first operand. 

		friend istream& operator>>(istream& ins, DNASequence& arg);
		// Implement the friend function to read in a nucleotide sequence made up
		// of only the following characters: adenine (A), thymine (T), guanine (G)
		// and cytosine (C). Assume case insensitive but convert to upper internally.
		
		friend ostream& operator<<(ostream& out, const DNASequence& arg);
		// Implement the friend function to write out a nucleotide sequence. No blanks.

		int get_max_sequence() const { return max_sequence; };
		// Accessor for max_sequence.

		char* get_dna_sequence() const { return dna_sequence; };
		// Accessor for dna_sequence.

		void set_max_sequence(const int num) { max_sequence=num; };
		// Mutator for max_sequence.
		
	private:
		char		*dna_sequence;				// Dynamic array of char
		int 		max_sequence;				// Number of sequences.
		bool		validate(string& str);	// a helper function to validate the nucleotide string.
};

#endif
//JH:----------------------dnasequence.cpp---------------------------
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include "dnasequence.h"

using namespace std;

// default constructor
DNASequence::DNASequence() : max_sequence(20) 
{
   dna_sequence = new char[max_sequence+1]; //+1 for null char '\0'
   dna_sequence[0] = '\0';  
}

// constructor which sets member variable dna_sequence to a string
// but first must convert string to c-string
// Assume that the sequence is initialized to the nucleotides string.
DNASequence::DNASequence(string nucleotides) : max_sequence(nucleotides.length())
{
   //VALIDATION NEEDED FIRST BEFORE COPYING
   validate(nucleotides); //if program continues, string validated
   dna_sequence = new char[max_sequence+1]; //+1 for null char '\0'
   strcpy(dna_sequence, nucleotides.c_str());
}

// Copy constructor, no validation needed
DNASequence::DNASequence(const DNASequence& arg) : max_sequence(arg.get_max_sequence())
{
   dna_sequence = new char[max_sequence+1]; //+1 is for null char '\0'
   strcpy(dna_sequence, arg.dna_sequence);
}

// Destructor
DNASequence::~DNASequence()
{
   delete [] dna_sequence;
}

// Assignment operator
// @param arg: must be object of DNASequence type, right hand of equal sign 
//		set equal to *this invoking object
// post-condition: right hand of = now is same as left hand side
DNASequence& DNASequence::operator=(const DNASequence& arg)
{

   if (this == &arg)
      return *this;

   if (strlen(dna_sequence) < strlen(arg.dna_sequence))
   {
      delete [] dna_sequence;
      dna_sequence = new char[strlen(arg.dna_sequence)+1];
//JH: Need to set max_sequence to strlen(arg.dna_sequence)+1
   }
   strcpy(dna_sequence, arg.dna_sequence);
   return *this; 
}

// Equals operator compares the given sequence with the invoking object.
// TODO DO NOT COMPARE MAX LENGTHS 
// returns true if given sequence is found within the invoking.
// false if not found
bool DNASequence::operator==(const DNASequence& arg)
{
   string a = get_dna_sequence();
   string b = arg.get_dna_sequence();

   if (a.find(b) == string::npos) 
	return false;
   else
	return true;
}

// Not equals operator compares the given sequence with the invoking object.
// returns true if given sequence is NOT found within invoking
bool DNASequence::operator!=(const DNASequence& arg)
{
   string a = get_dna_sequence();
   string b = arg.get_dna_sequence();

   if (a == b)
	return false;
   else
	return true;
}


// Append the given sequence onto the end of the invoking object sequence.
DNASequence operator+(const DNASequence& arg1, const DNASequence& arg2)
{
    DNASequence result;  
    result.max_sequence = arg1.max_sequence + arg2.max_sequence;
    result.dna_sequence = new char[result.max_sequence]; //dynamically allocate new memory for result
    result = arg1; //call copy constructor
    strcat(result.dna_sequence, arg2.dna_sequence);  
    return result;
}

// Remove the given sequence from the invoking object if it exists. Return
// the modified sequence with only the first instance of the string deleted.
// If the given sequence is not found, return the
// first argument sequence unaltered.
DNASequence operator-(const DNASequence& arg1, const DNASequence& arg2)
{
   DNASequence result;
   string a = arg1.dna_sequence;
   string b = arg2.dna_sequence;
   int found_at;
  
   if (b.length() > a.length()) //cannot continue if second arg is more char than first
   {
	cout << "Error, second seq longer than first." << endl;
	exit(1);  
   }
      
   found_at = a.find(b); //sets the location b is found in a at param@ found_at

   if (found_at == string::npos)
      return arg1;

   else if (found_at != string::npos)
      a.erase(found_at, b.length());

   result = DNASequence(a);
   
   return result;
}

//removes all instances of given sequence from the first. returns 
//modified sequence without the instances, otherwise returns unmodified
//first arg.
DNASequence operator%(const DNASequence& arg1, const DNASequence& arg2)
{
   DNASequence result;
   string a = arg1.dna_sequence;
   string b = arg2.dna_sequence;
   int found_at;
   do{
      if (b.length() > a.length()) //cannot continue if second arg is more char than first
      {
// JH: Don't exit
	cout << "Error, second seq longer than first." << endl;
	exit(1);  
      }
      
      found_at = a.find(b); //sets the location b is found in a at param@ found_at

      if (found_at == string::npos)
      {
         result = DNASequence(a);
         return result;
      }

      else if (found_at != string::npos)
         a.erase(found_at, b.length());
   }while(found_at != string::npos);
}

// To make the code compile, a function that validates the input string
// is made up purely of nucleotides.
bool DNASequence::validate(string& str) {
  
   string bases = {"ATGC"};

   for (int i=0; i<str.length(); i++)
   { 
      str[i] = toupper(str[i]); //convert current char to uppercase
				//so as to only check against 4 chars 
				//for efficiency purposes
      for (int j=0; j<bases.length(); j++)
      {
	if (str[i] == bases[j])
	    break;
  	else if (j == bases.length()-1)
        {
            cout << "Invalid DNA sequence." << endl;
	    exit(1); //it has reached the end and not found a valid char
        }    
      }
   }
  
   return true;
}

// Implement the friend function to read in a nucleotide sequence made up
// of only the following characters: adenine (A), thymine (T), guanine (G)
// and cytosine (C). Assume case insensitive but convert to upper internally.
istream& operator>>(istream& ins, DNASequence& arg)
{
    // Read in a string and use the validate function above to ensure that
    // the string has only nucleotides and convert them all to upper case.
    string str;
    ins >> str;
    arg = DNASequence(str);
    return ins;
}

// Implement the friend function to write out a nucleotide sequence. No blanks.
ostream& operator<<(ostream& out, const DNASequence& arg)
{
   out << arg.dna_sequence;
   return out;
}
