// create a pascal triangle
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    vector<vector<int>> arr(5);
    for (int i = 0; i < 5; i++)
    {
        arr[i].resize(i + 1);
        arr[i][0] = arr[i][i] = 1;
        for (int j = 1; j < i; j++)
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}