#include "histogram.h"

int main()
{
	// set up variables
	u_int input = 1;

	// start while loop till 0 is entered
	while (input != 0)
	{
		// set up frequency array
		u_int frequency[13] = { 0 };

		cout << "Enter a number [0 to quite]: ";
		// store input value
		cin >> input;
		// check if input is 0
		if(input == 0)
			cout << "Have a nice day.";
		// check if input too large for window size
		else if (input > 430)
			cout << "Your number is too large (200-430 is ideal). Try again\n" << endl;
		else
		{
			for (u_int i = 0; i <= input; i++)
			{
				frequency[rollDie()+rollDie()]++;
			}
			//cout << freq[2];
			// pass results to histogram building method for display.
			printHistogram(frequency);
		}
	};
	return 1;
}