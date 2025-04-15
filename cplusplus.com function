
/*
XOR -> true if only one input is true, else false
//-------------------------
0 XOR 0 = 0
0 XOR 1 = 1
1 XOR 0 = 1
1 XOR 1 = 0.
//-------------------------
*/


#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


// cplusplus.com (2009) Masking Password Input. Available at: https://cplusplus.com/articles/E6vU7k9E/. (Accessed: 18th March 2025)
string getpass(const char* prompt, bool show_asterisk = true)
{
    const char BACKSPACE = 8;
    const char RETURN = 13;

    string password;
    unsigned char ch = 0;

    cout << prompt; // removed an endl here - so it's all on the same line

    DWORD con_mode;
    DWORD dwRead;

    HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

    GetConsoleMode(hIn, &con_mode);
    SetConsoleMode(hIn, con_mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

    while (ReadConsoleA(hIn, &ch, 1, &dwRead, NULL) && ch != RETURN)
    {
        if (ch == BACKSPACE)
        {
            if (password.length() != 0)
            {
                if (show_asterisk)
                    cout << "\b \b";
                password.resize(password.length() - 1);
            }
        }
        else
        {
            password += ch;
            if (show_asterisk)
                cout << '*';
        }
    }
    cout << endl;
    return password;
}
// end of referenced code -------------------------------------


int main()
{
    cout << "Welcome!" << endl;
    string password = getpass("Enter: ", true); // true - askterisks will show (function from cplusplus.com)
    cout << password;
    return 0;


  }
