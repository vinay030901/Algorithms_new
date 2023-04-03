#include <bits/stdc++.h>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a = 5, b = 7;
    cout << (a & b) << endl;
    // Interestingly!! The bitwise OR of two numbers is just the sum of those two numbers if there is no carry involved, otherwise you just add their bitwise AND. Let’s say, we have a=5(101) and b=2(010), since there is no carry involved, their sum is just a|b. Now, if we change ‘a’ to 6 which is 110 in binary, their sum would change to a|b + a&b since there is a carry involved
    cout << (a | b) << endl;
    cout << (a ^ b) << endl; // xor operator
    cout << (~a) << endl;    // negation operator, flips th bits

    // right shift operator
    // the bits will move right side and rightmost bits
    // will be removed
    // the right shift operator is equivalent to divide by 2
    // and a>>b means a*(2 power -b)
    cout << (a >> 1) << endl;

    // left shift operator, the bits will move right side and 0 will be inserted at start
    // it is equivalent to multiply by 2^y
    cout << (a << 1) << endl;
    cout<<(1<<4)<<endl;
}