#include <bits/stdc++.h>
using namespace std;
struct Result
{
    Result() : output1(){};
    int output1[100];
};
Result duplicateArray(int n, int arr[])
{
    Result r;
    int mp[256] = {0};
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
    int i = 0;
    return r;
}
int main()
{
    int n = 6;
    int arr[] = {4, 4, 7, 8, 8, 9};
    Result r = duplicateArray(n, arr);
    cout << r.output1[0] << " " << r.output1[1];
    return 0;
}