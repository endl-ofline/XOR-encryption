/*
Rana Mitchell - 2403597
CMP111 Personal Project (April 2025)
XOR Encryption | Digital Forensics
*/

#include <iostream>
#include <bitset>
#include <string>
using namespace std;

/*
XOR -> true if only one input is true, else false.
-------------------------
0 XOR 0 = 0
1 XOR 1 = 0

0 XOR 1 = 1
1 XOR 0 = 1
-------------------------
*/

void ASCIItoBinary(char inputChar)
{

	cout << "ASCII Character: " << inputChar << endl; // normal alphabetic (ASCII) character
	cout << "Binary Representation: " << bitset<8>(inputChar) << endl; // the '8' indicates the number of bits - converts the char to the binary equivalent
	cout << endl;
}

int main()
{
	// ----------------------------------------------------------------------------
	// TESTING THE BASICS OF THE XOR FUNCTION:

	int a = 0; // 0000 (0) - false
	int b = 1; // 0001 (1) - true

	int c = a ^ b; // a XOR b

	cout << "A: " << a << endl;
	cout << "B: " << b << endl;
	cout << "Result: " << c << endl; // one input is true - so the output must be true (it is)
	cout << "-----------------------------------------------------\n"; // visual seperation between tests

	// ----------------------------------------------------------------------------
	// TESTNG ALPHABETIC CHARACTERS:

	int d = 6; // 0110 (6)
	int e = 11; // 1011 (11)

	int f = d ^ e; // d XOR e

	cout << "D: " << d << endl;
	cout << "E: " << e << endl;
	cout << "Result: " << f << endl; // 1101 (13)
	cout << "-----------------------------------------------------\n"; // visual seperation between tests

	// ----------------------------------------------------------------------------
	// USING A FOR LOOP TO ITERATE THROUGH THE STRING / TESTING THE FUNCTION:

	string userInput = "Hello There\n"; // string (will be the input sentence)
	cout << "userInput: " << userInput << endl;
	
	for (size_t i = 0; i < userInput.length(); i++) // "size_t is an unsigned integer data type...used to represent the size of objects in bytes..." (geeksforgeeks, 2025) https://www.geeksforgeeks.org/size_t-data-type-c-language/
	{ // for the length of the inputted string...
		ASCIItoBinary(userInput[i]); // run the ASCIItoBinary function on the current userInput value
	}
	cout << "-----------------------------------------------------\n"; // visual seperation between tests

	return 0;
}
