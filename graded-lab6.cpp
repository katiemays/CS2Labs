// JH: 93/100 - Excellent!
// JH: See inline comments
/*  Author: Katie Mays
 *  Last modified: 21 March 2018
 *  Bug:
 *
 *  class Rational to practice basics of defining and using classes.
 */
#include <iostream>
#include <sys/time.h>

using namespace std;

/*
 * class Rational
 *    represents a Rational number. Remember rational means ratio-nal
 *    which means there is a numerator and denominator implemented using
 *    integer values. Using good ADT techniques, we have made member
 *    variable private (also known as instance variables) and made member
 *    functions public.
 */
class Rational
{
public:
    Rational ();     
    // default constructor 

    Rational(int i);
    // constructor that takes a single int as paramter. Implies that the
    // denominator is 1.

    Rational (int p, int q);
    //constructor that takes two ints as parameter. Verify q is not zero

    void input();
    // read value for the object from standard input 

    void output();
    // display the value of the object to standard output 


    //Todo: declare an accessor (getter function) that returns the numerator
 	int get_num();   

    //Todo: declare an accessor (getter function) that returns the denominator
    	int get_den();

    void Sum (Rational op1, Rational op2);
    // set current object's value to be the sum of num1 and num2 

    bool isEqual(const Rational& op);
    // test if two rational numbers are equal.

private:
    int numerator;
    int denominator;

}; 


/*
 * main program
 * 		Unit Test code for class Rational uses all defined methods
 */
int main ()
{
    Rational a(1,2);	 	// a is 1/2 
    cout << "a = ";
	a.output ();

    Rational b(2); 		 // b is 2/1
    cout << "b = ";
	b.output ();

    Rational c;			 // what does the default constructor do? KM: assigns private data members values for this case, here defined it to set numerator to 0 and denominator to equal 1;
    cout << "c = ";
	c.output ();

    cout << "Input ratio for c:" << endl;
    	c.input (); 		 // read value for c from input
    cout << "c = ";
	c.output (); 

    cout << "Set c ratio equal to the sum of a and b:" << endl;
    c.Sum (a,b); 		// c will be set to 1/2+2/1 = 5/2
    cout << "c = ";
	c.output (); 		//this should display 5/2
    
    //Todo: display the numerator of c
    	cout << "Numerator of c is : ";
 	cout << c.get_num() << endl;
    //Todo: display the denominator of c
    	cout << "Denominator of c is : ";
	cout << c.get_den() << endl;

    //Todo: read in two rational numbers and test if they are equal using isEqual
    Rational d;
    Rational e;

	// Todo: get the values using the input member function
	cout << "Input first ratio to compare for equality: " << endl;
		d.input();
	cout << "Input second ratio: " << endl;
		e.input();

	// Todo: compare using isEquals and write out the result.
	if (d.isEqual(e)==true)
		cout<<"Rationals are Equal"<<endl;
	else
		cout<<"Rationals are Not Equal"<<endl;

	return 0;
}

// JH: Please comment all function headers
// -4

//Definitions of all member functions 
Rational::Rational():	numerator(0),
			denominator(1)
{}
Rational::Rational(int i)
{
	numerator = i;
	denominator = 1;
}
Rational::Rational(int p, int q)
{
	numerator = p;
	if (q != 0)
		denominator = q;
	else
		cout << "Error! Invalid entry." << endl;
}
void Rational::input()
{
	char temp;
	cout << "Enter ratio like this 'X/Y' : ";
// JH: Should test denominator == 0
// -3
	cin >> numerator >> temp >> denominator;
}
void Rational::output()
{
	cout << numerator << "/" << denominator << endl;
}
int Rational::get_num()
{
	return numerator;
}
int Rational::get_den()
{
	return denominator;
}
void Rational::Sum (Rational op1, Rational op2)
{
	if (op1.denominator == op2.denominator)//adding when denominators are the same
	{
		numerator = op1.numerator + op2.numerator;
		denominator = op1.denominator;
	}
	else //adding two unlike denominators
	{
		int tempNum1, tempDen1;
		int tempNum2, tempDen2;
		
		tempNum1 = op1.numerator*op2.denominator;	//multiply top and bottom by other fraction's denominator
		tempDen1 = op1.denominator*op2.denominator;
		tempNum2 = op2.numerator*op1.denominator;	//and again
		tempDen2 = op2.denominator*op1.denominator;

		numerator = tempNum1 + tempNum2;	//set invoking object equal to new summed fraction
		denominator = tempDen1;
	}
}
bool Rational::isEqual (const Rational& op)
{
	if((numerator==op.numerator)&&(denominator==op.denominator))//check if both objects have equal numerator and denominator
		return true;//Rationals are equal
	int tempDen = op.numerator*denominator;
	int tempNum = op.denominator*numerator;
	if(tempDen == tempNum)//cross multiply to check if two unlike fractions are equal
		return true;
	return false;//Rationals are not equal
}
