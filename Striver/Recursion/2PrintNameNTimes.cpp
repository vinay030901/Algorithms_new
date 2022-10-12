#include <bits/stdc++.h>
using namespace std;
void print(int cnt, int n)
{
    if (cnt == n)
        return;
    cout << "Vinay Kumar\n";
    print(cnt + 1, n);
}
int main()
{
    int n;
    cout << "enter count: ";
    cin >> n;
    print(0, n);
}