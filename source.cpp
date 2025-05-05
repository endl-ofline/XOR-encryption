
/*
Rana Mitchell - 2403597
CMP111 Personal Project (April 2025)
XOR Encryption | Digital Forensics
*/

/*
XOR -> true if only one input is true, else false.
-------------------------
0 XOR 0 = 0
1 XOR 1 = 0

0 XOR 1 = 1
1 XOR 0 = 1
-------------------------
*/

#include <iostream>
#include <bitset>
#include <string>
#include <fstream>
using namespace std;

// FUNCTION DECLARATIONS
string ASCIItoBinary(char inputChar);
string binarytoASCII(string input);
string binaryInput(string userInput);
string providedXOR(string baseXORinput, int length);
string XORencrypt(string userInput, string XORinput);
string XORdecrypt(string binaryUser, string binaryXOR);

int main()
{
	string userInput = "";
	string baseXORinput = "supercalifragilisticexpialidocioussupercalifragilisticexpialidocioussupercalifragilisticexpialidocious";
	string XORinput = "";
	string XORresult = "";
	string userXOR = "";
	string lines[300] = { "" };
	string line = "";
	string binaryXORinput = "";

	int lineCount = 0;
	int inputSize = 0;
	int XORsize = 0;
	int check = 0;
	int userDecrypt = 0;
	int decryptCheck = 0;
	int query = 0;
	int innerQuery = 0;

	cout << "Welcome! What would you like to XORder today?\n";
	do
	{
		cout << "\n1 - XOR with a provided key.\n2 - XOR with an inputted key.\n3 - read in a file\n4 - decrypt an existing XOR.\n5 - to exit.\n" ;
		cout << "Please enter your choice: ";
		cin >> query;
		cout << endl;

		if (query == 1)
		{
			do
			{
				cout << "Enter a phrase: ";
				cin.ignore();
				getline(cin, userInput); // takes in entire sentence
				inputSize = userInput.length();

				if (inputSize > 102)
				{
					cout << "\nPlease keep your input less than 100..." << endl;
					innerQuery = 1;
				}
				else
				{
					innerQuery = 2;
				}
			} while (innerQuery != 2);

			XORinput = providedXOR(baseXORinput, inputSize);

			cout << "Length of userInput: " << inputSize << endl;
			cout << "Length of XORinput: " << XORinput.length() << endl;

			cout << "Binary User Input: " << binaryInput(userInput) << endl;
			cout << "Binary XOR Key: " << binaryInput(XORinput) << endl;


			XORresult = XORencrypt(userInput, XORinput);
			cout << "Encryption Result: " << XORresult << endl;

		}
		else if (query == 2)
		{
			do {
				cout << "Enter a phrase: ";
				cin.ignore();
				getline(cin, userInput); // takes in entire sentence
				inputSize = userInput.length();

				cout << "Enter a phrase " << inputSize << " characters long: ";
				// cin.ignore();
				getline(cin, XORinput); 

				cout << endl; // magic buffer-flushing endl DO NOT REMOVE!!!!!! >:(( (it will break and i will cry)

				if (userInput.length() != XORinput.length())
				{
					cout << "Please enter sentences that are the same length!\n" << endl;
					check = 0;
				}
				else if (userInput.length() == XORinput.length())
				{
					check = 1;
				}

			} while (check != 1);

			XORresult = XORencrypt(userInput, XORinput);
			cout << "Encryption Result: " << XORresult;

			binaryInput(userInput);

			do
			{
				cout << "\nType '1' to decrypt your sentence: ";
				cin >> userDecrypt;
			} while (userDecrypt != 1);

			string decryption = XORdecrypt(binaryInput(XORinput), XORresult);

			cout << "\nBinary Decryption Result: " << decryption;
			cout << "\nASCII Decryption Result: " << binarytoASCII(decryption) << endl << endl;
		}
		else if (query == 3)
		{
			// the following function modified is from GeeksforGeeks(2024) How to Read File into String in C++?. Available at: https://www.geeksforgeeks.org/how-to-read-file-into-string-in-cpp/ [Accessed: 30-04-25]

			string filePath = "hellothere.txt"; // only opens the file - no processing
			ifstream file(filePath); // filestream = input file stream, file = an object

			if (!file.is_open()) // returns 'true' if the file has not opened
			{
				cerr << "Failed to open file: " << filePath << endl; // cerr = standard error stream, unbuffered (outputs errors immediately to console)
				return 1;
			}
		
			while (getline(file, line)) // reads a single line from the file stream 'file', loop continues until getline() can no longer read from the file
			{
				cout << "Line " << lineCount << ": " << line << endl;
				lines[lineCount] = line;
				
				inputSize = lines[lineCount].length();
				// cout << "Length of lines[lineCount].length(): " << inputSize << endl;

				XORinput = providedXOR(baseXORinput, inputSize);
				XORresult = XORencrypt(lines[lineCount], XORinput);
				cout << "Encryption Result: " << XORresult << endl << endl;

				lineCount++;
			}

			file.close();

			// end of function from (GeeksforGeeks, 2024)
		}
		else if (query == 4)
		{
			cout << "Enter the encrypted sentence: ";
			cin.ignore();
			getline(cin, userInput); // takes in entire sentence
			inputSize = userInput.length();
			cout << "userInput: " << userInput << endl;

			cout << endl;

			cout << "Enter the XOR key: ";
			getline(cin, XORinput); // takes in entire sentence
			cout << "XORinput:" << XORinput << endl;

			binaryXORinput = binaryInput(XORinput);
			cout << "Binary v. XORinput: " << binaryXORinput << endl;

			XORsize = binaryXORinput.length();

			cout << "Length of userInput: " << inputSize << endl;
			cout << "Length of XORinput: " << XORsize << endl;

			cout << "Binary User Input: " << userInput << endl;
			cout << "Binary XOR Key: " << binaryXORinput << endl;


			XORresult = XORdecrypt(userInput, binaryInput(XORinput));
			cout << "Binary Decryption Result: " << XORresult << endl;

			cout << "Decryption Result: " << binarytoASCII(XORresult) << endl;

			
		}
		else if (query == 5)
		{
			break;
		}
		else
		{
			cout << "Invalid. Please try again.\n" << endl;
			query = 0;
		}
	} while (query != 5);

	return 0;
}

string ASCIItoBinary(char inputChar)
{
	string binaryString;
	binaryString = bitset<8>(inputChar).to_string(); // converting the output to a string to make it storable (ASCII is 7bit)
	return binaryString;
}

string binarytoASCII(string input)
{ 
	// the following function modified is from GeeksforGeeks(2024) Program to convert given Binary to its equivalent ASCII character string. Available at: https://www.geeksforgeeks.org/program-to-convert-given-binary-to-its-equivalent-ascii-character-string/ [Accessed: 20-04-25]
	string binaryString = input;
	string ASCII = "";

	int byte = 8;
	int currentValue = 0;

	for (int i = 0; i < input.length(); i += 8) // for every character
	{
		for (int j = 0; j < 8; j++)
		{
			currentValue <<= 1;
			currentValue |= (binaryString[i + j] - '0');
		}
		ASCII += static_cast<char>(currentValue);
	}
	return ASCII; // moved out of loop to catch all values

} // end of function from (GeeksforGeeks, 2024)

string binaryInput(string userInput)
{
	string binaryUser = "";
	string binaryResult = "";

	for (int i = 0; i < userInput.length(); i++)
	{
		binaryUser = ASCIItoBinary(userInput[i]);
		binaryResult += binaryUser; // append rather than add the whole string on again (do NOT do that...)
	}

	return binaryResult;
}

string providedXOR(string baseXORinput, int length)
{
	string adjustedKey = "";

	for (int i = 0; i < length; i++)
	{
		adjustedKey += baseXORinput[i];
	}
	// cout << "Adjusted Key: " << adjustedKey << endl;
	return adjustedKey;
}


string XORencrypt(string userInput, string XORinput)
{
	string binaryUser = "";
	string binaryXOR = "";

	string XORencrypt = "";
	char bitResult;

	for (int i = 0; i < userInput.length(); i++)
	{
		binaryUser = ASCIItoBinary(userInput[i]);
		binaryXOR = ASCIItoBinary(XORinput[i]);

		for (int j = 0; j < binaryUser.length(); j++)
		{
			bitResult = ((binaryUser[j] - '0') ^ (binaryXOR[j] - '0') + '0'); // << Copilot used to aid here
			XORencrypt += bitResult; // storage
		}

	}
	return XORencrypt;
}

string XORdecrypt(string binaryUser, string XORresult) // original representation of userInput
{
	string XORdecrypt = "";
	char bitResult;

	for (int j = 0; j < binaryUser.length(); j++) // iterates through each bit
	{
		bitResult = ((binaryUser[j] - '0') ^ (XORresult[j] - '0')) + '0'; // << Copilot used to aid here
		XORdecrypt += bitResult; // storage
	}
	return XORdecrypt;
}


