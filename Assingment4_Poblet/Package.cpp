#include <stdexcept>
#include <iomanip>
#include <sstream>
#include "Package.h"

EndPoint::EndPoint (const string& n, const string& a,
  const string& c, const string& s, const string& z)
{
	size_t length{ n.size() };
	length = (length < 24 ? length : 23);
	n.copy(name, length);
	name[length] = '\0';

	length = a.size();
	length = (length < 24 ? length : 23);
	a.copy(address, length);
	address[length] = '\0';

	length = c.size();
	length = (length < 18 ? length : 17);
	c.copy(city, length);
	city[length] = '\0';

	length = s.size();
	length = (length < 3 ? length : 2);
	s.copy(state, length);
	state[length] = '\0';

	length = z.size();
	length = (length < 11 ? length : 10);
	z.copy(zipCode, length);
	zipCode[length] = '\0';
}

string EndPoint::logString() const
{
	ostringstream output;
	output << left << setw(25) << name
		<< setw(25) << address
		<< setw(19) << city << ", " << setw(4) << state << " "
		<< setw(12) << zipCode << endl;
	return output.str();
}

Package::Package (const EndPoint& s, const EndPoint& r, double w, double c)
{
  sender = s;
  recipient = r;
  if (w <= 0.0) throw invalid_argument("Weight has to be > 0.0");
  weight = w;
  if (c <= 0.0) throw invalid_argument("Cost has to be > 0.00");
  costPerOz = c;
}

string Package::logString() const
{
	ostringstream out;
	out << "From: \n" << sender.logString()
		<< "\nTo: \n" << recipient.logString()
		<< setprecision(2) << right << fixed
		<< "\nWeight: " << weight << " Oz.\n";
	return out.str();
}

double Package::calculateCost() const
{
  return weight*costPerOz;
}
 
