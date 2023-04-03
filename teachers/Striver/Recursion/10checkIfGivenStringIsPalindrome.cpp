#include <bits/stdc++.h>
using namespace std;
bool check(string str, int l, int h)
{
    if (l >= h)
        return true;
    else
    {
        if (str[l] != str[h])
            return false;
        return check(str, l + 1, h - 1);
    }
}
int main()
{
    string str = "abcdba";
    if (check(str, 0, str.length() - 1))
        cout << "string is palindrome";
    else
        cout << "string is not palindrome";
}
