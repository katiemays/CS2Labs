// JH: 57/50
// JH: BONUS: Loop +5, Running Avg +5
// JH: Please indent code in blocks (between {}) [2 or more spaces]. It helps readability.
// JH: Please comment function headers and prototypes
/* Katie Mays
 * 1/17/18
 * Lab 1: This program calculates the inflation rate given two Consumer Price Index values and prints it to the monitor.
 */

#include <iostream>
using namespace std;

// prototypes
double InflationRate(float old_cpi, float new_cpi);
/* calculates the inflation rate given the old and new consumer price index
 * @param old_cpi: is the consumer price index that it was a year ago
 * @param new_cpi: is the consumer price index that it is currently 
 */
void average(float storeRates[], float& av, int counter);
/* calculates the average inflation rates taken from the InflationRate() calculations
 */

int main()   //C++ programs start by executing the function main
{
   // TODO #1: declare two float variables for the old consumer price index (cpi) and the new cpi
   //variables
   float storeRates[10] = {0};
   float oldcpi, newcpi, temp, av, index=0;
   char more;
   int counter, i = 0;

// JH: Please indent code in blocks (between {}) [2 or more spaces]. It helps readability.
// -1
   // BONUS #1: Put the logic in TODO #2-4 in a loop that asks the user to enter 'y' if there's more data
   do {
	// TODO #2: Read in two float values for the cpi and store them in the variables
	cout << "Old cpi : ";
	cin  >> oldcpi;
	cout << "New cpi : ";
	cin  >> newcpi;

	// TODO #3: call the function InflationRate with the two cpis
	InflationRate (oldcpi, newcpi);

	// make current found inflation rate equal temp so later it can be stored in the array
	temp = InflationRate(oldcpi, newcpi);

// JH: Running total would be adding in the new rate to the total, keeping the number of successful runs
// -1
	// BONUS #2: Keep a running total of the inflation rates and the number of cpi's
	storeRates[i] = temp;
	i++;
	counter = i; // no need to make the counter i+1 because it is incremented directly before counter is set equal to i

	// TODO #4: print the results
	cout << "Inflation rate is : " << InflationRate(oldcpi, newcpi) << "%" << endl;
	
	//ask if the user has more data
	cout << "Is there more data? : ";
	cin  >> more;

   } while (more == 'y');

   // BONUS #2 (cont.) : Calculate the average rate.
   // call function to find average unless one rate is returned invalid
         for (int i = 0; i < counter; i++)
         {
// JH: A better choice would be to skip the invalid rate and reduce the count by 1.
// -1
            if (storeRates[i] == -1.0)
            {
                 cout << "One or more rates invalid. Please try again." << endl;
                 return 0;
            }
            else
                 average(storeRates, av, counter);
         }

   cout << "The average of the rates is : " << av << "%" << endl;

   return 0;
}

// double InflationRate(float old_cpi, float new_cpi)
// precondition:   both prices must be greater than 0.0
// postcondition:  the inflation rate is returned or -1.0 for invalid inputs
double InflationRate(float old_cpi, float new_cpi)
{
   // TODO: Implement InflationRate to calculate the percentage increase or decrease
   if (old_cpi > 0 && new_cpi > 0)
	return ((new_cpi - old_cpi) / old_cpi * 100);
   else
	return (-1.0);
}
// JH: Please comment function headers and prototypes
void average(float storeRates[], float& av, int counter)
{
   float sum = 0;

   for (int i = 0; i < counter; i++)
   {
	sum += storeRates[i];	
   } 

   av = (sum / counter);
}
