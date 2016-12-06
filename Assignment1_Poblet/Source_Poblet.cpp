#include <iostream>
#include <string>

using namespace std;

int main()
{
	// unsigned int "input" to a positive number other than 0.
	unsigned int input = 1;

	// Start loop to continue till input becomes 0.
	while (input != 0)
	{
		// Ask user to enter a positive integer or 0 to quite.
		cout << "Enter a positive integer [0 to quit]: ";

		// Assing value to input.
		cin >> input;
		
		// Check to see if input is zero to exit.
		if (input != 0)
		{
			// Output the value entered
			cout << "\n" << input << " ";

			// Loop through the equations till input becomes 1.
			while (input != 1)
			{
				// Check to see if value is even.
				if (input % 2 == 0)
					input = input / 2; // If even then devide by 2.
				else
					input = (input * 3) + 1; // If odd then multiply by 3 and add 1.

				// Display calculated value and put a space between the numbers.
				cout << input << " ";
			}
			// Provide proper spacing for output.
			cout << "\n\n";
		}
	}
	// Farewell the user.
	cout << "Bye.\n\n" << endl;
	return 0;

}