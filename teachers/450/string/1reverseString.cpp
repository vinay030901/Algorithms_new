#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "hello brother";
    // string could easily reversed using reverse function
    reverse(str.begin(), str.end());
    cout << "string reversed using reverse function: " << str << endl;

    // but we can also use swapping to reverse a string
    string s = "hello brother";
    int n = s.length();
    for (int i = 0, j = n - 1; i < n / 2; i++, j--)
    {
        swap(s[i], s[j]);
    }
    cout << "string reversed using swapping: " << s << endl;
}