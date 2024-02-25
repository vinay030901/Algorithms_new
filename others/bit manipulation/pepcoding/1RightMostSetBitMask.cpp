// we have to find the right most set bit mask here
// so 11011010, then position of rsb is 2, we can do this by dividing the number into 2 parts
// the right part which is right of rsb, and it should be all zeros, then left part of rsb which is 0s and 1s
// we are going to do AND with 2s compliment here
// x= 00011100 1 000 and ~x=11100011 0 111 and ~x+1= 11100011 1 000
// and their AND is 0000000 1 000
#include <bits/stdc++.h>
using namespace std;
void findRSBMask(int num)
{
    cout << (num & -num) << " "; // -n means 2's compliment only here
    cout << (num & ~(num - 1)) << "\n";
}
int main()
{
    // Your code here
    findRSBMask(23);
    findRSBMask(45);
    findRSBMask(12);
    return 0;
}