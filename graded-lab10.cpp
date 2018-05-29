//JH:------------------------------------------------------
//JH: 50/50 - Excellent!
//JH:----------------------../Employees/simple_test.cpp----------------------------
//DISPLAY 15.7 Using Derived Classes
#include <iostream>
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "Administrator.h"
using namespace std;

int main( )
{
   Employee * employees[3];
   Employee  employeeArray[3];
    string name, ssn;
    double rate;
    int hour;
    double salary;
    string title;

    for (int i=0;i<3;i++)
    {
	cout <<"Enter employee #"<<i<<":\n";
	string type; 
        cout <<"Enter the type of employee (hourly, salaried, admin):";
        cin >> type;

        //common information for all kinds of employees
        cout <<"Name:";
        cin >> name; 

        cout <<"SSN: ";
        cin >> ssn; 

	if (type=="hourly")
	{
		HourlyEmployee * employee = new HourlyEmployee;
    		employee->set_name(name);
    		employee->set_ssn(ssn); 

		HourlyEmployee anotherOne (*employee);

		cout <<"Hourly rate:";
		cin >> rate;
    		employee->set_rate(rate);
		
		cout <<"How many hours:";
		cin >> hour;

    		employee->set_hours(hour);
    		cout << "Check for " << employee->get_name( )
         		<< " for " << employee->get_hours( ) << " hours.\n";
    		employee->print_check( );
    		cout << endl;

		employees[i] = employee;
	} else if (type=="salaried")
	{
		cout <<"Salary:";
		cin >> salary;
    		SalariedEmployee * boss = new SalariedEmployee(name,ssn, salary);
    		cout << "Check for " << boss->get_name( ) << endl;
    		boss->print_check( ); 

		cout <<"calling the Employee's print_check\n";
		boss->Employee::print_check();

		//cout <<"Trying to access private member\n";
		//cout <<"Name of boss" << boss->name << endl;


		employees[i] = boss;
	} else if (type=="admin")
	{
   		//Test your Administrator class here... 
   		cout <<"Enter title:";
		string t;
		cin >> t;
	
		cout <<"Enter salary:";
		cin >> salary;

		Administrator * admin = new Administrator (name,ssn,salary,t);
		
		cout <<"Print check for administrator employee\n";
		admin->print_check();
		//(*admin).print_check();

		employees[i] = admin;
   	}
   }


   //Payday! 
   
   cout <<"***********************************************\n";
   cout <<"Payday! Print all checks in a batch!\n";
   for (int i=0;i<3;i++)
   {
	  employees[i]->print_check ();
   }

    //free up dynamically allocated memory
    for (int i=0;i<3;i++)
          delete employees[i];
    return 0;
}
//JH:----------------------Administrator.h---------------------------
/* This is the header file for Administrator class */
/* Please finish the definition of the class to provide the following additional members:
 *  1. a string type member variable to store the title (director, Vice President, ... )
 *  3. Constructor functions: one default one, another taking necessary info. about the administrator: name, SSN, salary, title
 *  4. redefine print_check() so that the title is printed on the check. Start with the version from SalariedEmployee
 *
 *  from email:
 *  1. In Administrator.h, please declare a new data member of type string that is called title. Provide accessor and mutator functions for this new data member.
 *  2. Three member functions are declared in Administrator.h that will need to be implemented in Administrator.cpp.
 *  3. In Administrator.cpp, all three functions are stubbed out with no implementation, just a function shell.
 *  4. Finish the parameterized constructor and print_check using SalariedEmployee as a model.
 */
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "SalariedEmployee.h"

class Administrator : public SalariedEmployee
{
  public:
	Administrator();
	Administrator(string the_name, string the_number, double the_salary, string the_title); 

	string get_title() const { return title; };
	//accessor function to retrieve private data member title.
	
	void set_title(string temp) { title = temp; };
	//mutator function to set private data member title.
	
	void print_check();

  private: 
	string title;
};

#endif
//JH:----------------------Administrator.cpp---------------------------
/* Implement Administrator class */
#include <iostream>
#include "Administrator.h"
#include <string>

using namespace std;

Administrator::Administrator() : SalariedEmployee(), title(" ") 
{
   //deliberately empty
   cout << "Administrator() called.\n";
}

Administrator::Administrator(string the_name, string the_number, double the_salary, string the_title)
	: SalariedEmployee(the_name, the_number, the_salary), title(the_title)
{
  cout << "Administrator (" << the_name << ", " << the_number << ", " << the_salary << ", " << the_title << ") called.\n";
}

void Administrator::print_check() 
{
         set_net_pay(get_salary());
         cout << "\n__________________________________________________\n";
         cout << "Pay to the order of " << get_title() << " " << get_name( ) << endl;
         cout << "The sum of " << get_net_pay( ) << " Dollars\n";
         cout << "_________________________________________________\n";
         cout << "Check Stub NOT NEGOTIABLE \n";
         cout << "Employee Number: " << get_ssn( ) << endl;
         cout << "Salaried Employee. Regular Pay: " << get_salary() << endl;
         cout << "_________________________________________________\n";
 
}

