#include <bits/stdc++.h>
using namespace std;
#define max 500
int multiply(int *arr, int n, int m)
{
    int carry = 0;
    for (int i = 0; i < m; i++) // so we will do usual multiplication but instead of storing the whole value in a block, we'll just store
    // the value of digit in it and remaining digits will be stored in other array blocks
    {
        int data = arr[i] * n + carry; // we will calculate the data value, if i has value>0 then carry might be getting added to data
        arr[i] = data % 10;            // here the single digit of data is put into array block.
        carry = data / 10;             // the remaining value becomes carry and will be added into next blocks
    }
    while (carry) // if we get extra size or carry remaining after filling the number of values, we put in previous traverse, then
    // new values will be added in next array blocks
    {
        arr[m] = carry % 10;
        carry /= 10;
        m++; // length increasing
    }
    return m;
}
int main()
{
    int n;
    cin >> n;
    int arr[max];
    arr[0] = 1;
    int m = 1;
    // so, this question is a little bit different than usual ones
    // what we will do in create an array of some size beforehand
    for (int i = 2; i <= n; i++) // than we will loop over every value to send it to multiply function
    {
        m = multiply(arr, i, m); // here we are getting the new length of the array
    }
    for (int i = m - 1; i >= 0; i--)
        cout << arr[i];
}