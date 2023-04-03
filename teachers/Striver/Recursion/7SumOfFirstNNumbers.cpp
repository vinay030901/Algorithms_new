// we need to find the sum of first N natural numbers
#include <bits/stdc++.h>
using namespace std;

// using parameterized recursion
// we are sending parameters using the function here and then changes are made in the parameters itself
// that way, when we get the base condition, we can print the answer which is one of the parameters itself
void funParameterized(int i, int sum)
{
    // I have taken a basic approach which is to sum the value of i till it becomes less than 1. I am calling the function and adding
    // the value of i in sum after every function call.
    if (i < 1)
    {
        cout << "sum = " << sum;
        return;
    }
    funParameterized(i - 1, sum + i);
}

// so this is functional recursion where the problem is broken down into smaller parts
int funFunctional(int n)
{
    if (n < 1)
        return 0;
    else
        return n + funFunctional(n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << "Using parameterized function: ";
    funParameterized(n, 0);
    cout << "\nUsing functional recursion: ";
    cout << funFunctional(n);
}