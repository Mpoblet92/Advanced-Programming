#include "histogram.h"

void printHistogram(const u_int *freq)
{
	for (u_int i = 2; i < 13; i++)
	{
		cout << setw(2) << i << " | ";
		for (u_int j = 0; j < freq[i]; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
