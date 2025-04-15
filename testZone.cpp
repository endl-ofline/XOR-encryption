/*
Rana Mitchell - 2403597
CMP111 Personal Project (April 2025)
XOR Encryption | Digital Forensics
*/

#include <iostream>
#include <bitset>
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

int main()
{
	int a = 0; // 0000 (0) - false
	int b = 1; // 0001 (1) - true

	int c = a ^ b; // a XOR b

	cout << "A: " << a << endl;
	cout << "B: " << b << endl;
	cout << "Result: " << c << endl; // one input is true - so the output must be true (it is)

	// ----------------------------------------------------------------------------

	int d = 6; // 0110 (6)
	int e = 11; // 1011 (11)

	int f = d ^ e; // d XOR e

	cout << endl << "D: " << d << endl;
	cout << "E: " << e << endl;
	cout << "Result: " << f << endl; // 1101 (13)

	// ----------------------------------------------------------------------------

	return 0;
}
