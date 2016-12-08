#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Package.h"


int main ()
{
  ifstream logFile{ "logfile.dat", ios::in | ios::binary};

  if (!logFile) throw runtime_error("Unable to open log file");

  Package Pack;

  logFile.seekg(0);
  logFile.read(reinterpret_cast<char*>(&Pack), sizeof(Package));
  
  int record = 1;

  while (logFile)
  {
	  cout << "Record: " << record << endl;
	  cout << Pack.logString();
	  logFile.read(reinterpret_cast<char*>(&Pack), sizeof(Package));
	  record++;
  }
  logFile.close();
}
