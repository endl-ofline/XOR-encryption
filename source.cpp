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

// FUNCTION DECLARATIONS
string ASCIItoBinary(char inputChar);
string XORencrypt(string userInput, string XORinput);
string XORdecrypt(string binaryUser, string binaryXOR);

int main()
{
	string userInput = "";
	string XORinput = "";

	// string userSentence[50] = {};
	// string XORsentence[50] = {};

	int inputSize = 0;
	int check = 0;
	int userDecrypt = 0;
	int decryptCheck = 0;

	cout << "Welcome! What would you like to XORder today?\n" << endl;

	do {
			cout << "Enter a sentence, without spaces: ";
			cin >> userInput;
			inputSize = userInput.length();

			cout << "Enter a sentence " << inputSize << " characters long (without spaces): ";
			cin >> XORinput;
			cout << endl;

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
	
	cout << "Encryption Result: " << XORencrypt(userInput, XORinput); // function call
	string XORresult = XORencrypt(userInput, XORinput); // storing result for decryption

	do
	{
		cout << "\nType '1' to decrypt your sentence: ";
		cin >> userDecrypt;

	} while
		(userDecrypt != 1);

	cout << "\nDecryption Result: " << XORdecrypt(userInput, XORresult) << endl;
	

return 0;
}

string ASCIItoBinary(char inputChar)
{
	string binaryString;
	binaryString = bitset<7>(inputChar).to_string(); // converting the output to a string to make it storable (ASCII is 7bit)
	return binaryString;
}


string XORencrypt(string userInput, string XORinput)
{
	string binaryUser = "";
	string binaryXOR = "";

	string XORencrypt = "";
	char bitResult;

	int spaceCounter = 0;

	for (int i = 0; i < userInput.length(); i++) // for every character
	{
		binaryUser = ASCIItoBinary(userInput[i]); // use the function to convert to the binary
		binaryXOR = ASCIItoBinary(XORinput[i]); // stores working character in these strings


		for (int j = 0; j < binaryUser.length(); j++) // works through each binary bit in the byte
		{
			if (spaceCounter == 7) // every full byte
			{
				XORencrypt += " "; // append a space
				j--; // correct what would be a missing value
				spaceCounter = 0; // reset
				
			}
			else
			{
				bitResult = ((binaryUser[j] - '0') ^ (binaryXOR[j] - '0')) + '0'; // https://www.geeksforgeeks.org/xor-of-two-binary-strings/ // converts each character to its integer equivalent before XORing - then converting back and storing
				XORencrypt = XORencrypt + bitResult; // appended to the string
				spaceCounter++;
			}
		}

	}

	return XORencrypt; // return full string
}

string XORdecrypt(string binaryUser, string XORresult) // original representation of userInput
{
	string XORdecrypt = "";
	char bitResult;

	int spaceCounter = 0;

	for (int j = 0; j < binaryUser.length(); j++) // iterates through each bit
	{
		if (spaceCounter == 7) //  space handling
		{
			XORdecrypt += " "; // append a space
			j--; // correct what would be a missing value
			spaceCounter = 0; // reset

		}
		else // to remove the XOR line:
		{
			bitResult = ((binaryUser[j] - '0') ^ (XORresult[j] - '0')) + '0'; // https://www.geeksforgeeks.org/xor-of-two-binary-strings/ // conversion
			XORdecrypt = XORdecrypt + bitResult; // storage
			spaceCounter++;
		}
	}

	return XORdecrypt;
}

