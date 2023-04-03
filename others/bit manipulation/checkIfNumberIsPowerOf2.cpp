#include <bits/stdc++.h>
using namespace std;
bool fun1(int n)
{
    int set = 0;
    while (n)
    {
        if ((n & 1) == 1)
            set++;
        n = n >> 1;
    }
    return set == 1;
}
int fun2(int n)
{
    return n!=0 && (n & (n - 1));
}
int main()
{
    /*
    there are two methods to do this question:

    1. any number which is power of 2 has only single set bit, so we can count the set bits

    2. any 2 power is of the form 1000, so if we decrease it by 1, then it become 0111, so & of them is zero
    and that's how we can find it, 0 is exception here*/
}