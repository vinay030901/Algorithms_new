#include <bits/stdc++.h>
using namespace std;
void print(int i)
{
    if (i < 1)
        return;
    cout << i << "\n";
    print(i - 1);
}
int main()
{
    int n;
    cin >> n;
    print(n);
}
