#include <bits/stdc++.h>
using namespace std;
int minimumNumberOfSwaps(string str)
{
    // code here
    int ans = 0, c = 0;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '[') // we will count the number of opening brackets here and decrease at the time of closing brackets
            c++;
        else
        {
            c--;
            if (c < 0)
                // if the count decrease than 0, it means we have encounterd more closing brackets than opening one, so we will increase
                // the answer, which is the number of swaps we will do
                ans -= c;
        }
    }
    return ans += c;
}
int main()
{

    return 0;
}