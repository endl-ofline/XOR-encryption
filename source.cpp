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

	string userSentence[50] = {};
	string XORsentence[50] = {};

	int inputSize = 0;
	int check = 0;

	cout << "Welcome! What would you like to XORder today?\n";

	do {
			cout << "Enter a sentence, without spaces: ";
			cin >> userInput;
			inputSize = userInput.length();

			cout << "Enter a sentence " << inputSize << " characters long: ";
			cin >> XORinput;
			cout << endl;

		if (userInput.length() != XORinput.length())
		{
			cout << "Please enter sentences that are the same length!" << endl;
			check = 0;
		}
		else if (userInput.length() == XORinput.length())
		{
			check = 1;
		}

	} while (check != 1);
	
	for (size_t i = 0; i < userInput.length(); i++) // "size_t is an unsigned integer data type...used to represent the size of objects in bytes..." (geeksforgeeks, 2025) https://www.geeksforgeeks.org/size_t-data-type-c-language/
	{ // for the length of the inputted string...
		// cout << "USER SENTENCE: ";
		userSentence[i] = ASCIItoBinary(userInput[i]); // run the ASCIItoBinary function on the current userInput value
		// cout << userSentence[i] << " " << endl;
		
	}

	for (size_t i = 0; i < XORinput.length(); i++) 
	{ 
		// cout << "XOR SENTENCE: ";
		XORsentence[i] = ASCIItoBinary(XORinput[i]);
		// cout << XORsentence[i] << " " << endl;

	}

	// cout << "userSentence[4] = " << userSentence[4] << endl;

	cout << "XOR Result: " << XORencrypt(userInput, XORinput);
	

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

	for (int i = 0; i < userInput.length(); i++)
	{
		binaryUser = ASCIItoBinary(userInput[i]);
		binaryXOR = ASCIItoBinary(XORinput[i]);

		for (int j = 0; j < binaryUser.length(); j++)
		{
			bitResult = ((binaryUser[j] - '0') ^ (binaryXOR[j] - '0')) + '0'; // https://www.geeksforgeeks.org/xor-of-two-binary-strings/
			XORencrypt = XORencrypt + bitResult;
		}

	}

	return XORencrypt;
}

string XORdecrypt(string binaryUser, string binaryXOR)
{
	string XORdecrypt = "";
	return XORdecrypt;
}

