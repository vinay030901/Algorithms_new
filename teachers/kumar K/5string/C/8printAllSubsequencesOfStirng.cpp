#include <bits/stdc++.h>
using namespace std;
void printSubsequences(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }
    // output is passed with including
    // the Ist character of
    // Input string
    printSubsequences(input.substr(1), output + input[0]);
    // output is passed without
    // including the Ist character
    // of Input string
    printSubsequences(input.substr(1), output);
}
int main()
{
    string str = "abcd";
    printSubsequences(str, "");
    return 0;
}