
#include <bits/stdc++.h>
using namespace std;

/* fibonacci function to find the value in a fibonacci sequence
we are first doing it using memoization where we will put a vector to stop the overlapping computation

so by using this, the time complexity becomes linear and the space complexity will be O(2N) with stack space and memoization space
*/
int f(int n, vector<int> &v)
{
    if (n <= 1)
        return n;
    if (v[n] != -1)
        return v[n];
    return v[n] = f(n - 1, v) + f(n - 2, v);
}

/*
now, we will convert the program into tabulation
since it is bottom up, we will have calculated values of base cases and then we will move forward using those previoud values to find
the later values
the time complexity in this case is linear and space is O(N) now because of no stack space*/
int fibonacciTabulation(int n)
{
    vector<int> v(n + 1);
    v[0] = 0;
    v[1] = 1;
    for (int i = 2; i <= n; i++)
        v[i] = v[i - 1] + v[i - 2];
    return v[n];
}

/*
now we will try to remove that extra space complexity too
since we are using only the two previous values of the vector only,
so instead of using the vector, we will use two variables in it*/
int fibonacciSpace(int n)
{
    int prev1 = 0, prev2 = 1;
    for (int i = 2; i <= n; i++)
    {
        int total = prev1 + prev2;
        prev1 = prev2;
        prev2 = total;
    }
    return prev2;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n+1, -1);
    cout << "Using memoization: " << f(n, v);
    cout << "\nUsing tabulation: " << fibonacciTabulation(n);
    cout << "\n space complexity solution: " << fibonacciSpace(n);
}


int fib(int n)
{
    if(n<=1) return n;
    return fib(n-1)+fib(n-2);
}