#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>

#include "Morse.h"

using namespace std;

MorseCode coder;
string words;

string morseEncoding(string morseWord) 
{	
	// Set array to be size of words inputed
	char *letters = new char[morseWord.length()];
	// Transform input into charactarter array
	strcpy(letters, morseWord.c_str());
	// Start ostream out
	ostringstream out;
	// Loop through each element in 
	for (int i = 0; i < morseWord.length(); i++)
	{
		// Input encoding into ostream for return.
		out << coder.enCode(toupper(letters[i])) << " ";
	}
	// Return string creating with ostream
	return out.str();
	delete[] letters;
};

string morseDecoding(string word)
{
	// Index of char array starting at 0.
	int i = 0;
	// Index of characters seperated by delimiters
	size_t pos = 0;
	// String built to send to decode method.
	string token;
	// Delimiters to find single space, and triple space.
	string delimiter = " ";
	string delimiter2 = "   ";

	// Start ostream
	ostringstream out;

	// Set char array to a size that is arbitrarily large. 
	char *letters = new char[word.length()+ 1];

	// Check if input contains idividual words.
	if (word.find(delimiter2) != string::npos)
	{
		// Seperate individual words of input when triple spaces are found.
		while ((pos = word.find(delimiter2)) != string::npos)
		{
			// Store word in a variable to seperate characters.
			string wordsplit = word.substr(0, pos);
			// Erase word from original input.
			word.erase(0, pos + delimiter2.length());
			// Check for individual characters through single spaces.
			while ((pos = wordsplit.find(delimiter)) != string::npos)
			{
				// Store single morse character string
				token = wordsplit.substr(0, pos);
				// Decode token and store in array.
				letters[i] = coder.deCode(token);
				// Print current letter.
				out << letters[i];
				// Erase already decode morse string.
				wordsplit.erase(0, pos + delimiter.length());
				// Increment array index.
				i++;
			}
			// seperate words with a space, coder.decode("  ") would also work.
			out << coder.deCode(wordsplit) << " ";
		}
	}
	// Check if original input contains morse strings
	while ((pos = word.find(delimiter)) != string::npos)
	{
		// Store in variable.
		token = word.substr(0, pos);
		// Store decoded morse in char array.
		letters[i] = coder.deCode(token);
		// Print stored char.
		out << letters[i];
		// Erase decoded string
		word.erase(0, pos + delimiter.length());
		// Increment array index.
		i++;
	}
	if ((word.find(delimiter) != string::npos) || word.length() >= 2)
	{
		// Print remaining morse string.
		out << coder.deCode(word) << endl;
	}
	out << endl;
	// ostream
	return out.str();
	// Delete array
	delete[] letters;
};

void morseFileEncoding()
{
	// String for user input
	string input;
	// Instructions to user
	cout << "Enter a file name to encode!" << endl;
    // Get user file.
	cin >> input;
	// Start fstream
	ifstream encodeFile;
	ofstream morseFile;

	// Open file for read.
	encodeFile.open(input, std::ifstream::in );
	// Open file for write.
	morseFile.open("morseEncoded.txt", std::ofstream::out);
	// Catch invalid file name.
	if (!encodeFile) throw runtime_error("Unable to open read file!");
	// Reserve space for char to be use to read from file.
	char c;
	// Loop through file till c becomes EOF.
	while (encodeFile.get(c)) {		
		// Start stream
		stringstream ss;
		// Check for newline characters.
		if (c != '\n')
		{
			// Rebuild char into stream to convert to string.
			ss << std::noskipws << c;
			// Write to morseFile after encoding.
			morseFile << std::noskipws << morseEncoding(ss.str());
		}
		else
			morseFile << '\n';
	}
	// Close files.
	encodeFile.close();
	morseFile.close();
};

void morseFileDecoding()
{
	// String for user input
	string input;
	// Instructions to user
	cout << "Enter a file name to decode!" << endl;
	// Get user file.
	cin >> input;
	// Start fstream
	ifstream decodeFile;
	ofstream regFile;

	// Open file for read.
	decodeFile.open(input, std::ifstream::in);
	// Open file for write.
	regFile.open("morseDecoded.txt", std::ofstream::out);
	// Catch invalid file name.
	if (!decodeFile) throw runtime_error("Unable to open read file!");
	// Reserve space for char to be use to read from file.
	char c;
	// Start stream
	ostringstream de;
	// Loop through file till c is EOF.
	while (decodeFile.get(c)) {
		// Check for newline characters.
		if (c != '\n')
		{
			// Rebuild char into stream to convert to string.
			de << std::noskipws << c;
		}
		else
		{
			regFile << std::noskipws << morseDecoding(de.str());
			de.str(std::string());
		}
	}
	// Write to morseFile after encoding.
	regFile << std::noskipws << morseDecoding(de.str());
	// Close files.
	decodeFile.close();
	regFile.close();
};

int main()
{
	// Set boolean for exit.
	bool exit = false;
	// Set option for switch.
	int option = 10;


	cout << "Welcome to Morse Coder!\n" << endl;
	// Continue until exit becomes true with case 0.
	while (!exit)
	{
		cout << "1: Real-time morse encoding." << endl;
		cout << "2: Real-time morse decoding." << endl;
		cout << "3: File morse encoding." << endl;
		cout << "4: File morse decoding." << endl;
		cout << "0: Exit!\n" << endl;
		cout << "Enter an option: ";
		cin >> option;
		if (option < 0 || option > 4 || !cin)
		{
			cout << endl << "Must be a value between 0 and 4!\n" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			switch (option)
			{
			case 1:
				cout << "Enter morse to encode!" << endl;
				cin.ignore();
				getline(cin, words);
				cout << morseEncoding(words);
				cout << endl << endl;
				break;
			case 2:
				cout << "Enter morse to decode!" << endl;
				cin.ignore();
				getline(cin, words);
				cout << morseDecoding(words) << endl;
				break;
			case 3:
				morseFileEncoding();
				cout << endl;
				break;
			case 4:
				morseFileDecoding();
				cout << endl;
				break;
			case 0:
				cout << "Bye!\n" << endl;
				exit = true;
				break;
			}
		}
	}
	return 0;
};