#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Package.h"


int main ()
{
  fstream logFile{ "logfile.dat", ios::out | ios::binary };

  if (!logFile) throw runtime_error("Unable to open log file");

  // Three address records.

  EndPoint homer{"Homer Simpson", "742 Evergreen Terrace", "Springfield",
    "FL", "32401"};

  EndPoint donald{"Donald Duck", "1313 Webfoot Walk", "Duckburg",
    "CA", "95501"};

  EndPoint kermit{"Kermit Frog", "On the Swamp", "Leland", "MS", "38756"};

  // Create a few packages

  Package P1{homer, donald, 25.0, 0.20};

  cout << "First package processed." << endl;
  logFile.seekp((0) * sizeof(Package));
  logFile.write(reinterpret_cast<const char*>(&P1), sizeof(Package));
  cout << "Logged, " << "Shipping Cost: $" << P1.calculateCost() << endl << endl;

  Package P2{donald, kermit, 17.5, 0.20};

  cout << "Second package processed." << endl;
  logFile.seekp((1) * sizeof(Package));
  logFile.write(reinterpret_cast<const char*>(&P2), sizeof(Package));
  cout << "Logged, " << "Shipping Cost: $" << P2.calculateCost() << endl << endl;

  Package P3{kermit, homer, 14.2, 0.20};

  cout << "Third package processed." << endl;
  logFile.seekp((2) * sizeof(Package));
  logFile.write(reinterpret_cast<const char*>(&P3), sizeof(Package));
  cout << "Logged, " << "Shipping Cost: $" << P3.calculateCost() << endl << endl;

  logFile.close();
}
