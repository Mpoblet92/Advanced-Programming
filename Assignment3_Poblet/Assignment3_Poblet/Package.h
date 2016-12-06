#ifndef PACKAGE_H
#define PACKAGE_H 

#include "EndPoint.h"

class Package
{
protected:
	EndPoint sender, reciever;
	double weight, costPerOunce;
public:
	Package(const EndPoint&, const EndPoint&, double = 0.1, double = 0.1);
	double calculateCost();
	string toString() const;
};

#endif
