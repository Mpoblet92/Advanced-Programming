#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H 

#include "Package.h"

using namespace std;
class TwoDayPackage : public Package
{
private:
	double twoDayFee;

public:
	TwoDayPackage(const EndPoint&, const EndPoint&, double, double, double);
	// Override calculateCost method to add two day fee.
	double calculateCost();
};

#endif