#include "OvernightPackage.h"

OvernightPackage::OvernightPackage(const EndPoint& cSender, const EndPoint& cReciever, double cWeight, double cCostPerOunce, double cOvernightFee)
	: Package(cSender, cReciever, cWeight, cCostPerOunce)
{
	if (cOvernightFee <= 0)
	{
		throw invalid_argument("Fee must be > 0");
	}
	overnightFee = cOvernightFee;
}

double OvernightPackage::calculateCost()
{
	return weight * (costPerOunce + overnightFee);
}