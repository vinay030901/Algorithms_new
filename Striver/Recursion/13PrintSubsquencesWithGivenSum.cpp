// print the subseqences with given sum
#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}
void printSubsequences(int arr[], int ind, int sum, int target, vector<int> &v, int n)
{
    if (ind == n)
    {
        if (sum == target)
        {
            print(v);
            return;
        }
        else
            return;
    }
    v.push_back(arr[ind]);
    printSubsequences(arr, ind + 1, sum + arr[ind], target, v, n);
    v.pop_back();
    printSubsequences(arr, ind + 1, sum , target, v, n);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int sum = 5;
    vector<int> v;
    int n = sizeof(arr) / sizeof(arr[0]);
    printSubsequences(arr, 0, 0, sum, v, n);
}