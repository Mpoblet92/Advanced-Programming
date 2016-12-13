#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H 

#include "Package.h"

class OvernightPackage : public Package
{
private:
	double overnightFee;

public:
	OvernightPackage(const EndPoint&, const EndPoint&, double, double, double);
	// Override calculateCost method to add two day fee.
	double calculateCost();
};

#endif