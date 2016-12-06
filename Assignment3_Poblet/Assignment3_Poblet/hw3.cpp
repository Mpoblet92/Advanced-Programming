#include <iostream>
#include <iomanip>
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using namespace std;

int main ()
{
  // Three address records.

  EndPoint homer{"Homer Simpson", "742 Evergreen Terrace", "Springfield",
    "FL", "32401"};

  EndPoint donald{"Donald Duck", "1313 Webfoot Walk", "Duckburg",
    "CA", "95501"};

  EndPoint kermit{"Kermit Frog", "On the Swamp", "Leland", "MS", "38756"};

  // This calls the base class constructor (regular fee).

  Package regular{homer, donald, 25.0, 0.20};

  // Defines output precision for floating point numbers (iomanip).

  cout << fixed << setprecision(2);

  // Prints package parameters.

  cout << "Regular package processed." << endl;
  cout << regular.toString();
  cout << "Shipping Cost: $" << regular.calculateCost() << endl << endl;

  // First derived class (two-day fee added).

  TwoDayPackage twoday{donald, kermit, 17.5, 0.20, 2.0};

  cout << "Two-day package processed." << endl;
  cout << twoday.toString();
  cout << "Shipping Cost: $" << twoday.calculateCost() << endl << endl;

  // Second derived class (overnight fee added).

  OvernightPackage overnight{kermit, homer, 14.2, 0.20, 0.50};

  cout << "Overnight package processed." << endl;
  cout << overnight.toString();
  cout << "Shipping Cost: $" << overnight.calculateCost() << endl << endl;
}
