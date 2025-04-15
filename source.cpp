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

int main() // https://cplusplus.com/forum/general/224178/
{
	string userInput = "";
	string xorInput = "";
	int check = 0;

	do {
			cout << "Enter a sentence: ";
			cin >> userInput;

			cout << "Enter a sentence to XOR with (has to be the same length): ";
			cin >> xorInput;

		if (userInput.length() != xorInput.length())
		{
			cout << "Please enter sentences that are the same length!" << endl;
			check = 0;
		}
		else if (userInput.length() == xorInput.length())
		{
			check = 1;
		}

	} while (check != 1);

return 0;
}
