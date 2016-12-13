#ifndef ENDPOINT_H
#define ENDPOINT_H 

#include <string>

using namespace std;
class EndPoint
{
private:
	string name, address, city, state, zip;

public:
	EndPoint();
	EndPoint(const string& name, const string& address, const string& city, const string& state, const string& zip);
	string toString() const;
};

#endif