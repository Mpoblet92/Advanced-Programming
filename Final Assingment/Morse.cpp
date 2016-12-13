#include "Morse.h"
#include <array>
#include <iostream>

MorseCode::MorseCode() 
{
	char characters[] {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.', ',', ':', '-', '\'', '/', '-', '?', ' ', '\n'};
	string codes[] {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", ".-.-.-", "--..--", "---...", "-...-", ".----.", "-..-.", "-...-", "..--..", " ", "\n"};
	
	for (int i = 0; i < sizeof(characters)/sizeof(characters[0]); i++)
	{
		encodeMap[characters[i]] = codes[i];
		decodeMap[codes[i]] = characters[i];
	}
}

string MorseCode::enCode(const char& letter) const
{
	return encodeMap.at(letter);
}

char MorseCode::deCode(const string& morse) const
{
	return decodeMap.at(morse);
}


