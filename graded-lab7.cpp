//JH:------------------------------------------------------
//JH: 105/100 - Excellent!
//JH: +5 :BONUS:simplify
//JH:----------------------rational7.cpp---------------------------
/*        Author: Katie Mays
 * last modified: 4/16/18
 */
#include "rational7.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

//Definitions of all member functions 

rational::rational (int p, int q)
{
   if (q==0)
	exit(1);
   numerator = p;
   denominator = q;
   counter++;
   cout <<"So far " <<counter <<" rational objects created\n";
}


 /* Set the invoking object's value from user input */
void rational::input()
{
   char c;
   int top, bottom;
   bool valid = true; 

   // keep reading until valid input is entered 
   do {
     cin >> top >> c >> bottom;
     if (c!='/' || bottom==0)
     {
        cout <<"wrong input. Enter a rational (p/q):";
        valid = false;
     } 
    else
 	valid = true;
   } while (!valid);

   // set the invoking object's numerator, denominator 
   numerator = top;
   denominator = bottom;
}

 /* Display invoking object's value in the standard output, in the form of numerator/denominator */
void rational::output()
{
   cout << numerator << "/" << denominator; 
}

 //return the invoking object's numerator 
int rational::get_numerator()
{
   return numerator; 
}
   
 //return the invoking object's denominator
int rational::get_denominator()
{
   return denominator;
}
   
// Set invoking object to be the sum of op1 and op2
const void rational::Sum (rational& op1, rational& op2)
{
   numerator = (op1.numerator * op2.denominator + op2.numerator*op1.denominator);
   denominator = op1.denominator*op2.denominator;
   Simplify ();
}

// set invoking object to be the product of op1 and op2
const void rational::Product (rational& op1, rational& op2)
{
   numerator = op1.numerator * op2.numerator;
   denominator = op1.denominator * op2.denominator;
   Simplify ();
}

/* set invoking object's private data members (numerator and denominator) to some int type values when two integers are provided */
void rational::set (int top, int bottom)
{
   numerator = top;

   if (bottom != 0)
      denominator = bottom;
}

/* set invoking object's private data members to some int type values when only one is given, assume numerator and set denominator to 1 */ 
void rational::set (int top)
{
   numerator = top;
   denominator = 1;
}

//EZ: return the gcd of numbers a and b 
int rational::gcd (int a, int b)
{
   while (a!=0 && b!=0)
   {
      a = a % b;
      if (a!=0)
         b = b % a;
   }
   if (a==0)
      return b;
   if (b==0)
      return a; 
}

/* private member function that simplifies invoking object*/
void rational::Simplify()
{
   int their_gcd = gcd(numerator, denominator);

   numerator = numerator / their_gcd;
   denominator = denominator / their_gcd;   
} 
//JH:----------------------rational7.h---------------------------
/*   Author: katie mays
 * last mod: 4/16/18
 */
class rational
{
public:
   /* default constructor set the rational number to 0, (i.e., numerator is 0, denominator is 1) */
   rational (int p=0, int q=1);	
				
   /* Set the invoking object's value from user input */
   void input();	

   /* Display invoking object's value in the standard output, in the form of numerator/denominator */
   void output();	

   //return the invoking object's numerator 
   int get_numerator();
   
   //return the invoking object's denominator
   int get_denominator(); 
   
   // Set invoking object to be the sum of op1 and op2
   const void Sum (rational& op1, rational& op2); 

   // Set invoking object to be the product of op1 and op2
   const void Product (rational& op1, rational& op2);
 
   // set numerator and demoninator private data members  
   void set (int top, int bottom);	//when both are provided
   void set (int top);			//when only one is provided, assume numerator

   //EZ: return the gcd of numbers a and b 
   int gcd (int a, int b);

   static int counter;

private:
   int numerator;
   int denominator;
   
   //Simplifies the invoking object
   void Simplify ();
}; 
//JH:----------------------lab7.cpp----------------------------
/*  Author: Katie Mays
 *  Modified: 4/16/18
 *  This rational class practice basics of defining and using class.
 */

#include <iostream>
#include <stdlib.h>
#include "rational7.h"

using namespace std;

int rational::counter=0; 

int main ()
{
	char answer;
	int num_elements;

	// Test the three constructors ... 
	rational  a(1,2); // a is 1/2 
	cout << "      Rational object initialized with parameter 1,2: ";
	a.output ();
        cout <<endl;

	rational b(2); // b is 2/1
	cout << "        Rational object initialized with parameter 2: ";
	b.output ();
        cout <<endl;

	rational c;
	cout << "Rational object initialized with default constructor: ";
	c.output ();
        cout <<endl;

	//Test input member function 
	cout << "                              Enter a rational value: ";
	c.input (); //read value for c from input
	cout << "                               What you just entered: ";
	c.output (); 
        cout <<endl;

	//Test Sum member function 
	do {
	  cout << "                    Enter op1 (in the format of p/q): ";
          a.input();

          cout << "                    Enter op2 (in the format of p/q): ";
	  b.input();

	  c.Sum (a,b);  
	  cout << "                           The sum of op1 and op2 is: ";
          c.output (); 
          cout <<endl;
	
	  c.Product (a,b);
	  cout << "                       The product of op1 and op2 is: ";
	  c.output ();
	  cout <<endl;
	  
	  cout << "Try again (Y/N)? ";
	  cin >> answer;

        } while (answer=='y' || answer=='Y');
	
	//test getters 
	cout << "                                    C's numerator is: " << c.get_numerator() << endl;
	cout << "                                  C's denominator is: " << c.get_denominator() << endl;

	//start of lab 7 ToDos
	a.set (1,100); //sets numerator to 1, denom to 100, testing set function
	
	cout << "****************************************************************************" << endl;
	cout << "                            Enter number of elements: ";
	cin >> num_elements;
	
	//dynamically allocate an array of rational objects of size @num_elements
	rational * fractions = new rational[num_elements];
	
	//set each rational element equal to 1/1, 1/2, 1/3, 1/4, ...
	for (int i=0; i < num_elements; i++)
	   fractions[i].set (1,i+1);	  

	//summing all rationals in array
	rational r_sum; //declare new variable of type rational
	for (int i=0; i < num_elements; i++)
	  r_sum.Sum(r_sum, fractions[i]);  //repetively call the func to add onto the pre-existing object and sum
	cout << "                 The sum of all rational elements is: ";
	r_sum.output ();
	cout << endl;

	//multiplying all rationals in array
	rational r_prod; //declare new variable for product
	r_prod.set (1,1); //must be set to 1 for product not to equal 0
	for (int i=0; i < num_elements; i++)
	   r_prod.Product(r_prod, fractions[i]);  //repeatively call the function multiply to the pre-existing object and product
	cout << "             The product of all rational elements is: ";
	r_prod.output ();
	cout << endl;
}

