/*
Rana Mitchell - 2403597
CMP111 Personal Project (April 2025)
XOR Encryption | Digital Forensics
*/

#include <iostream>
#include <bitset>
#include <string>
#include <fstream>
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
	
	for (int i = 0; i < userInput.length(); i++)
	{ // for the length of the inputted string...
		ASCIItoBinary(userInput[i]); // run the ASCIItoBinary function on the current userInput value
	}
	cout << "-----------------------------------------------------\n"; // visual seperation between tests

	// ----------------------------------------------------------------------------
	// OPENING A FILE - FUNCTION FROM https://www.geeksforgeeks.org/how-to-open-and-close-file-in-cpp/ [Accessed: 20th April].

	ofstream fio("hellothere.txt", ios::app); // output file stream - object name (fio) - file (hellothere.txt) - file mode (ios::app) = append

	if (fio.is_open()) // if the file object is open
	{
		cout << "File opened successfully!" << endl;

		fio << "General Kenobi!" << endl; // append "General Kenobi" to the file

		fio.close(); // close object
		cout << "File closed." << endl;
	}
	else
	{
		cout << "Error opening file :((" << endl;
	}

	// ----------------------------------------------------------------------------
	// FILE HANDLING - FUNCTION FROM https://www.geeksforgeeks.org/how-to-read-file-into-string-in-cpp/ [Accessed 20th April].

		// get the filepath
		string filePath = "hellothere.txt";

		// Open the file using ifstream
		ifstream file(filePath);

		// confirm file opening
		if (!file.is_open()) {
			// print error message and return
			cerr << "Failed to open file: " << filePath << endl;

			return 1;
		}

		// Read the file line by line into a string
		string line;
		while (getline(file, line)) {
			cout << line << endl;
		}

		// Close the file
		file.close();

	return 0;
}
