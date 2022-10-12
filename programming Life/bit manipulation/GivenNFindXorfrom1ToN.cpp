#include <bits/stdc++.h>
using namespace std;
int computeXOR(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}
int main()
{
    /* to find the xor of numbers from 1 to n, there is a certain trick
    the trick involves modding that number of 4

    if n%4==0- then answer is n
    if n%4==1 then answer is 1
    if n%4==2 then answer is 2
    if n%4==3 then answer is 0
    */
    int n;
    cin >> n;
    cout << computeXOR(n);
}