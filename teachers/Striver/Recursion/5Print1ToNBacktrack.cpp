#include <bits/stdc++.h>
using namespace std;
void print(int i)
{
    if (i < 1)
        return;
    print(i - 1);
    cout << i << " ";
}
int main()
{
    int n;
    cin >> n;
    print(n);
}