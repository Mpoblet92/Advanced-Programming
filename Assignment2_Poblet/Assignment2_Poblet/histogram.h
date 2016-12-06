#include <iostream>
#include <string>
#include <iomanip>
#include <random>

#ifndef HISTOGRAM_H
#define HISTOGRAM_H
// set up typedef for unsigned int
typedef unsigned int u_int;


using namespace std;

// set up inline method rolldie() to roll two dice x number of times
inline u_int rollDie()
{
	return rand() % 6 + 1;
}
// Set up prototype function for printHistogram
void printHistogram(const u_int *);


#endif // !HISTOGRAM_H

