#include <iomanip>
#include <stdexcept>
#include <sstream>

#include "EndPoint.h"

EndPoint::EndPoint(const string& customerName, const string& customerAddress, const string& customerCity, const string& customerState, const string& customerZip)
{
	name = customerName;
	address = customerAddress;
	city = customerCity;
	state = customerState;
	zip = customerZip;
}

string EndPoint::toString() const
{
	ostringstream output;
	output << name << endl
		<< address << endl
		<< city << ", " << state << " "
		<< zip << endl;
	return output.str();
}

EndPoint::EndPoint(){}