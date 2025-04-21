
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
string binarytoASCII(string input);
string binaryInput(string userInput);
string XORencrypt(string userInput, string XORinput);
string XORdecrypt(string binaryUser, string binaryXOR);

int main()
{
	string userInput = "";
	string XORinput = "";
	string XORresult = "";

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
	cout << "\nASCII Decryption Result: " << binarytoASCII(decryption) << endl;
	return 0;
}

string ASCIItoBinary(char inputChar)
{
	string binaryString;
	binaryString = bitset<8>(inputChar).to_string(); // converting the output to a string to make it storable (ASCII is 7bit)
	return binaryString;
}

string binarytoASCII(string input) // https://www.geeksforgeeks.org/program-to-convert-given-binary-to-its-equivalent-ascii-character-string/
{ // FUNCTION USES SEGMENTS FROM WEBSITE ^^
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
			bitResult = ((binaryUser[j] - '0') ^ (binaryXOR[j] - '0')) + '0'; 
			XORencrypt = XORencrypt + bitResult;
		}

	}

	return XORencrypt;
}

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

string XORdecrypt(string binaryUser, string XORresult) // original representation of userInput
{
	string XORdecrypt = "";
	char bitResult;

	for (int j = 0; j < binaryUser.length(); j++) // iterates through each bit
	{
		bitResult = ((binaryUser[j] - '0') ^ (XORresult[j] - '0')) + '0';
		XORdecrypt +=bitResult; // storage
	}
	return XORdecrypt;
}

