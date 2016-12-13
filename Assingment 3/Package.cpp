#include <iomanip>
#include <stdexcept>
#include <sstream>

#include "Package.h"
#include "EndPoint.h"

Package::Package(const EndPoint& mainSender, const EndPoint& mainReciever, double currentWeight, double currentCostPerOunce)
{	
	if (currentWeight <= 0.0 || currentCostPerOunce <= 0.0)
	{
		throw invalid_argument("Package weight must be > 0.0");
	}
	sender = mainSender;
	reciever = mainReciever;
	costPerOunce = currentCostPerOunce;
	weight = currentWeight;
}

double Package::calculateCost()
{
	return weight * costPerOunce;
}

string Package::toString() const
{
	ostringstream output;
	output << fixed << setprecision(2);
	output << "From: \n" << sender.toString() 
		<< "\nTo: \n" << reciever.toString()
		<< endl << "\nWeight: " << weight << " Oz.\n";
	return output.str();

}

