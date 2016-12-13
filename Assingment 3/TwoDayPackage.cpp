#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(const EndPoint& cSender, const EndPoint& cReciever, double cWeight, double cCostPerOunce, double cTwoDayFee)
	: Package(cSender, cReciever, cWeight, cCostPerOunce)
{
	if (cTwoDayFee <= 0)
	{
		throw invalid_argument("Fee must be > 0");
	}
	twoDayFee = cTwoDayFee;
}

double TwoDayPackage::calculateCost()
{
	return (weight * costPerOunce) + twoDayFee;
}