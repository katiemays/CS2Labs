//JH:------------------------------------------------------
//JH: 95/100 - Excellent!
//JH: -5 operator<= evaluated 7/8 <= 6/8 true.
//JH:----------------------rational8.h---------------------------
/*   Author: katie mays
 * last mod: 4/24/18
 * Header file for lab8
 */
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <sstream>

using namespace std;

class rational
{
public:
   /* default constructor set the rational number to 0, (i.e., numerator is 0, denominator is 1) */
   rational (int p=0, int q=1);	
				
   /*returns the gcd of numbers a and b*/ 
   int gcd (int a, int b);

   /*overloads input operator to directly cin a rational from the main function
    *@param in: a reference of type istream
    *@param r: a reference of type rational 
    *@return in: now with all components of the rational in the istream
    *@precondition: to be used in main(), must cin a rational
    *@postcondition: rational's private member variables have been properly inputed and set for @param r
    */
   friend istream& operator >> (istream& in, rational& r);

   /*overloads ouput operator to directly cout a rational from the main function
    *@param out: a reference of type ostream
    *@param r: a reference of type rational 
    *@return out: now with all components of the rational in the ostream
    *@precondition: to be used in main(), must cout a rational
    *@postcondition: rational's private member variables have been properly outputed
    */
   friend ostream& operator << (ostream& out, const rational& r);

   /*overloads binary addition operator to directly add two rationals from the main function
    *@param a: a reference to one variable of type rational
    *@param b: a reference to a second variable of type rational 
    *@return sum: member variables (numerator and denominator) of both rational variables properly added
    *@precondition: to be used in main(), must add two rationals
    *@postcondition: both rationals are not modified to stay true to const declaration
    */
   friend rational operator + (const rational& a, const rational& b);

   /*overloads binary subtraction operator to directly subtract two rationals from the main function
    *@param a: a reference to one variable of type rational
    *@param b: a reference to a second variable of type rational 
    *@return sub: member variables (numerator and denominator) of both rational variables properly subtracted (b from a)
    *@precondition: to be used in main(), must sub two rationals
    *@postcondition: both rationals are not modified to stay true to const declaration
    */
   friend rational operator - (const rational& a, const rational& b);

   /*overloads binary multiplication operator to directly multiply two rationals from the main function
    *@param a: a reference to one variable of type rational
    *@param b: a reference to a second variable of type rational 
    *@return prod: member variables (numerator and denominator) of both rational variables properly multiplied
    *@precondition: to be used in main(), must multiply two rationals
    *@postcondition: both rationals are not modified to stay true to const declaration
    */
   friend rational operator * (const rational& a, const rational& b);

   /*overloads binary division operator to directly divide two rationals from the main function
    *@param a: a reference to one variable of type rational
    *@param b: a reference to a second variable of type rational 
    *@return sum: member variables (numerator and denominator) of both rational variables properly divided (a / b)
    *@precondition: to be used in main(), must divide two rationals
    *@postcondition: both rationals are not modified to stay true to const declaration
    */
   friend rational operator / (const rational& a, const rational& b);

   /*overloads unary addition operator to directly negate one rational from the main function
    *@param a: a reference to one operand of type rational
    *@return neg: member variables (numerator and denominator) of negated @param a
    *@precondition: to be used in main(), must negate a rational
    *@postcondition: rational is not modified to stay true to const declaration
    */
   friend rational operator - (const rational& a);

   /*overloads boolean isEquals operator to use two rationals in a conditional statement in main()
    *@param a: a reference to one operand of type rational
    *@param b: a reference to a second operand of type rational
    *@return isEquals: true or false if the rationals are equal to each other
    *@precondition: two rationals in a conditional statement
    *@postcondition: both rationals now have same denominator and are simplified 
    */
   friend bool operator == (rational& a, rational& b);

   /*overloads boolean isNotEquals operator to use two rationals in a conditional statement in main()
    *@param a: a reference to one operand of type rational
    *@param b: a reference to a second operand of type rational
    *@return isNotEquals: true or false if the rationals are not equal to each other
    *@precondition: two rationals in a conditional statement
    *@postcondition: both rationals now have same denominator and are simplified 
    */
   friend bool operator != (rational& a, rational& b);

   /*overloads boolean isLessThan operator to use two rationals in a conditional statement in main()
    *@param a: a reference to one operand of type rational
    *@param b: a reference to a second operand of type rational
    *@return isLessThan: true or false if rational a < b
    *@precondition: two rationals in a conditional statement
    *@postcondition: both rationals now have same denominator and are simplified 
    */
   friend bool operator <  (rational& a, rational& b);

   /*overloads boolean isLessThanorEqual operator to use two rationals in a conditional statement in main()
    *@param a: a reference to one operand of type rational
    *@param b: a reference to a second operand of type rational
    *@return isLessThanorEqual: true or false if rational a <= b
    *@precondition: two rationals in a conditional statement
    *@postcondition: both rationals now have same denominator and are simplified 
    */
   friend bool operator <= (rational& a, rational& b);

   /*overloads boolean isGreaterThan operator to use two rationals in a conditional statement in main()
    *@param a: a reference to one operand of type rational
    *@param b: a reference to a second operand of type rational
    *@return isGreaterThan: true or false if rational a > b
    *@precondition: two rationals in a conditional statement
    *@postcondition: both rationals now have same denominator and are simplified 
    */
   friend bool operator >  (rational& a, rational& b);

   /*overloads boolean isGreaterThanorEqual operator to use two rationals in a conditional statement in main()
    *@param a: a reference to one operand of type rational
    *@param b: a reference to a second operand of type rational
    *@return isGreaterThanorEqual: true or false if rational a <= b
    *@precondition: two rationals in a conditional statement
    *@postcondition: both rationals now have same denominator and are simplified 
    */
   friend bool operator >= (rational& a, rational& b);

private:
   int numerator;
   int denominator;
   
   //Simplifies the invoking object
   const void Simplify ();
}; 
//JH:----------------------lab8.cpp---------------------------
/*  Author: Katie Mays
 *  Modified: 4/24/18
 *  This rational class practice basics of defining and using class.
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdlib.h>
#include "rational8.h"
#include <cctype>
#include <sstream>

using namespace std;

int evaluate_input(const string op);

int main ()
{
	string op; //used to evaluate inputted operator
	int op_no; //used for switch after input evaluated
	rational first, second, result;
	char answer;

	do {
 	  cout << "*************************************************************\n";
	  cout << "Enter an operator (+,-,*,/,==,!=,<,<=,>,>=,-1 for negation) : ";
	  cin  >> op;

	  op_no = evaluate_input(op);
	  
	  if (op_no != 5) //or all operators that take in two operands, binary operators
 	  {
	     cout << "                                     Enter the two operands : ";
	     cin  >> first >> second;
	  }
	  else
	  {
	     cout << "                                          Enter the operand : ";
	     cin  >> first;
	  }

	  switch (op_no) {
	     //op_no != 5: binary operators, take in 2 operands
	     //op_no == 5: unary operator, takes one operand
	     case 1:
		result = first + second;
		cout << "\t\t" << first << " + " << second << " = " << result << endl;
		break;	
	     case 2:
		result = first - second;
		cout << "\t\t" << first << " - " << second << " = " << result << endl;
		break;
	     case 3:
		result = first * second;
		cout << "\t\t" << first << " * " << second << " = " << result << endl;
		break;
	     case 4:
		result = first / second;
		cout << "\t\t" << first << " / " << second << " = " << result << endl;
		break;
	     case 5:
		result = -first;
		cout << "\t\t" << "The negation of " << first << " = " << result << endl;
		break;
	     case 6:
		cout << "\t\t" << "Is " << first << " equal to " << second << "? ";
		if (first == second)
		   cout << "Yes." << endl;
		else
		   cout << "No." << endl;
		break;
	     case 7:
		cout << "\t\t" << "Is " << first << " not equal to " << second << "? ";
		if (first != second)
		   cout << "Yes." << endl;
		else
		   cout << "No." << endl;
		break;
	     case 8:
		cout << "\t\t" << "Is " << first << " less than " << second << "? ";
		if (first < second)
		   cout << "Yes." << endl;
		else
		   cout << "No." << endl;
		break;
	     case 9:
		cout << "\t\t" << "Is " << first << " less than or equal to" << second << "? ";
		if (first <= second)
		   cout << "Yes." << endl;
		else
		   cout << "No." << endl;
		break;
	     case 10:
		cout << "\t\t" << "Is " << first << " greater than " << second << "? ";
		if (first > second)
		   cout << "Yes." << endl;
		else
		   cout << "No." << endl;
		break;
	     case 11:
		cout << "\t\t" << "Is " << first << " greater than or equal to " << second << "? ";
		if (first >= second)
		   cout << "Yes." << endl;
		else
		   cout << "No." << endl;
		break;
	  }

	  //engage user to ask if repeat needed
	  cout << "\t\t" << "Try again (Y/N)? ";
	  cin >> answer;

        } while (answer=='y' || answer=='Y');
	
	cout << "\t\t" << "Goodbye!" << endl;
 	cout << "*************************************************************\n";
}
//JH:----------------------rational8.cpp---------------------------
/*        Author: Katie Mays
 * last modified: 4/30/18
 * Definitions of all member functions, with updates!! newer addition with validation 
 */
#include "rational8.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <cctype>

using namespace std;


/*default constructor*/
rational::rational (int p, int q)
{
   if (q==0)
	exit(1);
   numerator = p;
   denominator = q;
}

/*return the gcd of numbers a and b*/
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
const void rational::Simplify()
{
   int their_gcd = gcd(numerator, denominator);
   numerator = numerator / their_gcd;
   denominator = denominator / their_gcd;
}

/*overloads input operator to directly cin a rational from the main function
    *@param in: a reference of type istream
    *@param r: a reference of type rational 
    *@return in: now with all components of the rational in the istream
    *@precondition: to be used in main(), must cin a rational
    *@postcondition: rational's private member variables have been properly inputed and set for @param r
    */
istream& operator >> (istream& in, rational& r)
{
   char c;
   string str;
   bool valid=true;
   bool found_slash=false;

   ins >> str;

   for (int i=0; i<str.length() && valid; i++)
   {
      if(str[i] == '-')
      {
	 if(i != 0)
	    valid=false;
      }
      else if(str[i] == '/')
      {
	 if((str[0] == '-' && str[1] == '/') || (str[0] == '/') || (i == str.length()-1))
	    valid=false;
	 else
	    found_slash=true;
      }
      else if(!isdigit(str[i]))
	 valid=false;
   }

   if (!valid)
   {
      cout << "Invalid rational format." << endl;
      exit(1);
   }

   istringstream isstr(str);

   if(found_slash)
   {
      isstr >> r.numerator >> c >> r.denominator;
      if(r.denominator==0)
      {
	 cout << "Invalid Rational format." << endl;
      	 exit(1);
      }
   }
   else
   {
      isstr >> r.numerator;
      r.denominator = 1;
   }
      
   return in;
}

/*overloads ouput operator to directly cout a rational from the main function
    *@param out: a reference of type ostream
    *@param r: a reference of type rational 
    *@return out: now with all components of the rational in the ostream
    *@precondition: to be used in main(), must cout a rational
    *@postcondition: rational's private member variables have been properly outputed
    */
ostream& operator << (ostream& out, const rational& r)
{
   out << r.numerator << "/" << r.denominator;
   return out;
}

/* evaluate input*/
int evaluate_input (const string op)
{
   vector <string> ops = {"+","-","*","/","-1","==","!=","<","<=",">",">="};

   for (int i=0; i<ops.size(); i++)
   {
      if (ops[i] == op)
        return i+1;
   }
   return 0;
}

/*overloads binary addition operator to directly add two rationals from the main function
    *@param a: a reference to one variable of type rational
    *@param b: a reference to a second variable of type rational 
    *@return sum: member variables (numerator and denominator) of both rational variables properly added
    *@precondition: to be used in main(), must add two rationals
    *@postcondition: both rationals are not modified to stay true to const declaration
    */
rational operator + (const rational& a, const rational& b)
{
   rational sum;
   sum.numerator = (a.numerator * b.denominator + b.numerator*a.denominator);
   sum.denominator = a.denominator*b.denominator;
   sum.Simplify ();
   return sum;
}

/*overloads binary subtraction operator to directly subtract two rationals from the main function
    *@param a: a reference to one variable of type rational
    *@param b: a reference to a second variable of type rational 
    *@return sub: member variables (numerator and denominator) of both rational variables properly subtracted (b from a)
    *@precondition: to be used in main(), must sub two rationals
    *@postcondition: both rationals are not modified to stay true to const declaration
    */
rational operator - (const rational& a, const rational& b)
{
   rational sub;
   sub.numerator = (a.numerator * b.denominator - b.numerator*a.denominator);
   sub.denominator = a.denominator*b.denominator;
   sub.Simplify ();
   return sub;
}

/*overloads binary multiplication operator to directly multiply two rationals from the main function
    *@param a: a reference to one variable of type rational
    *@param b: a reference to a second variable of type rational 
    *@return prod: member variables (numerator and denominator) of both rational variables properly multiplied
    *@precondition: to be used in main(), must multiply two rationals
    *@postcondition: both rationals are not modified to stay true to const declaration
    */
rational operator * (const rational& a, const rational& b)
{
   rational prod;
   prod.numerator = a.numerator * b.numerator;
   prod.denominator = a.denominator * b.denominator;
   prod.Simplify ();
   return prod;
}

/*overloads binary division operator to directly divide two rationals from the main function
    *@param a: a reference to one variable of type rational
    *@param b: a reference to a second variable of type rational 
    *@return sum: member variables (numerator and denominator) of both rational variables properly divided (a / b)
    *@precondition: to be used in main(), must divide two rationals
    *@postcondition: both rationals are not modified to stay true to const declaration
    */
rational operator / (const rational& a, const rational& b)
{
   rational div;
   div.numerator = a.numerator * b.denominator;
   div.denominator = a.denominator * b.numerator;
   div.Simplify ();
   return div;
}

/*overloads unary addition operator to directly negate one rational from the main function
    *@param a: a reference to one operand of type rational
    *@return neg: member variables (numerator and denominator) of negated @param a
    *@precondition: to be used in main(), must negate a rational
    *@postcondition: rational is not modified to stay true to const declaration
    */
rational operator - (const rational& a)
{
   rational neg;
   neg.numerator = -1 * a.numerator;
   neg.denominator = a.denominator;
   return neg;
}

/*overloads boolean isEquals operator to use two rationals in a conditional statement in main()
    *@param a: a reference to one operand of type rational
    *@param b: a reference to a second operand of type rational
    *@return isEquals: true or false if the rationals are equal to each other
    *@precondition: two rationals in a conditional statement
    *@postcondition: both rationals now have same denominator and are simplified 
    */
bool operator == (rational& a, rational& b)
{
   bool isEqual = true;
   a.Simplify();
   b.Simplify();

   if (a.denominator != b.denominator || a.numerator != b.numerator)
	isEqual = false;

   return isEqual;
}

/*overloads boolean isNotEquals operator to use two rationals in a conditional statement in main()
    *@param a: a reference to one operand of type rational
    *@param b: a reference to a second operand of type rational
    *@return isNotEquals: true or false if the rationals are not equal to each other
    *@precondition: two rationals in a conditional statement
    *@postcondition: both rationals now have same denominator and are simplified 
    */
bool operator != (rational& a, rational& b)
{
   bool isNotEqual = true;
   a.Simplify();
   b.Simplify();

   if (a.denominator == b.denominator && a.numerator == b.numerator)
	isNotEqual = false; //or a and b are equal

   return isNotEqual;
}

/*overloads boolean isLessThan operator to use two rationals in a conditional statement in main()
    *@param a: a reference to one operand of type rational
    *@param b: a reference to a second operand of type rational
    *@return isLessThan: true or false if rational a < b
    *@precondition: two rationals in a conditional statement
    *@postcondition: both rationals now have same denominator and are simplified 
    */
bool operator < (rational& a, rational& b)
{
   bool isLessThan = true;
   a.Simplify();
   b.Simplify();

   if (a.denominator != b.denominator)
   {
	a.numerator = a.numerator * b.denominator;
	a.denominator = a.denominator * b.denominator;
	b.numerator = b.numerator * a.denominator;
	b.denominator = b.denominator * a.denominator;
   }

   if (a.denominator == b.denominator && a.numerator >= b.numerator)
	isLessThan = false;

   return isLessThan;
}

/*overloads boolean isLessThanorEqual operator to use two rationals in a conditional statement in main()
    *@param a: a reference to one operand of type rational
    *@param b: a reference to a second operand of type rational
    *@return isLessThanorEqual: true or false if rational a <= b
    *@precondition: two rationals in a conditional statement
    *@postcondition: both rationals now have same denominator and are simplified 
    */
bool operator <= (rational& a, rational& b)
{
   bool isLessThanorEqual = true;
   a.Simplify();
   b.Simplify();

   if (a.denominator != b.denominator)
   {
	a.numerator = a.numerator * b.denominator;
	a.denominator = a.denominator * b.denominator;
	b.numerator = b.numerator * a.denominator;
	b.denominator = b.denominator * a.denominator;
   }

   if (a.denominator == b.denominator && a.numerator > b.numerator)
	isLessThanorEqual = false;

   return isLessThanorEqual;
}

/*overloads boolean isGreaterThan operator to use two rationals in a conditional statement in main()
    *@param a: a reference to one operand of type rational
    *@param b: a reference to a second operand of type rational
    *@return isGreaterThan: true or false if rational a > b
    *@precondition: two rationals in a conditional statement
    *@postcondition: both rationals now have same denominator and are simplified 
    */
bool operator > (rational& a, rational& b)
{
   bool isGreaterThan = true;
   a.Simplify();
   b.Simplify();

   if (a.denominator != b.denominator)
   {
	a.numerator = a.numerator * b.denominator;
	a.denominator = a.denominator * b.denominator;
	b.numerator = b.numerator * a.denominator;
	b.denominator = b.denominator * a.denominator;
   }

   if (a.denominator == b.denominator && a.numerator <= b.numerator)
	isGreaterThan = false;

   return isGreaterThan;
}

/*overloads boolean isGreaterThanorEqual operator to use two rationals in a conditional statement in main()
    *@param a: a reference to one operand of type rational
    *@param b: a reference to a second operand of type rational
    *@return isGreaterThanorEqual: true or false if rational a <= b
    *@precondition: two rationals in a conditional statement
    *@postcondition: both rationals now have same denominator and are simplified 
    */
bool operator >= (rational& a, rational& b)
{
   bool isGreaterThanorEqual = true;
   a.Simplify();
   b.Simplify();

   if (a.denominator != b.denominator)
   {
	a.numerator = a.numerator * b.denominator;
	a.denominator = a.denominator * b.denominator;
	b.numerator = b.numerator * a.denominator;
	b.denominator = b.denominator * a.denominator;
   }

   if (a.denominator == b.denominator && a.numerator > b.numerator)
	isGreaterThanorEqual = false;

   return isGreaterThanorEqual;
}
//JH:----------------------graded-lab8.cpp----------------------------
//JH:----------------------graded-lab8.cpp----------------------------
