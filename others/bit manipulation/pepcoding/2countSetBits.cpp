#include <bits/stdc++.h>
using namespace std;

// the first method is we can check all the bits and check if it set or not, then count it
int countSetBits(int number)
{
    int mask = 1, cnt = 0;
    for (int i = 0; i < 31; i++)
    {
        if ((number & (mask << i)) > 0)
            cnt++;
    }
    return cnt;
}

// the second method doesn't have to go through all the bits, it just jumps to all the RSB
// here we find the rsb mask, and minus it from the number, that will make remove the rsb from the number and we can increase the counter
int countSetBits1(int number)
{
    int cnt = 0;
    while (number)
    {
        int rsbm = (number & ~(number - 1));
        number -= rsbm;
        cnt++;
    }
    return cnt;
}
int countSetBits2(int number)
{
    return __builtin_popcount(number);
}
int main()
{
    // Your code here
    cout << countSetBits(15) << endl;
    cout << countSetBits1(15) << endl;
    cout << countSetBits2(22) << endl;
    return 0;
}