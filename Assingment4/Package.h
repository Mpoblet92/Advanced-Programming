#ifndef _PACKAGE_H
#define _PACKAGE_H 3710201611

#include <string>

using namespace std;

class EndPoint
{
  public:
    EndPoint () {}
    EndPoint (const string&, const string&, const string&, const string&, const string&);

    string logString() const;

  private:
    char name[24];
    char address[24];
    char city[18];
    char state[3];
    char zipCode[11];
};

class Package
{
  public:
    Package () {}
    Package (const EndPoint&, const EndPoint&, double, double);

    string logString() const;
    double calculateCost() const;

  private:
    EndPoint sender;
    EndPoint recipient;
    double   weight;
    double   costPerOz;
};

#endif

