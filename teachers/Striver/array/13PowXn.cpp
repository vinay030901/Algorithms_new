// find pow(x,n)
#include <bits/stdc++.h>
using namespace std;
/*for example we need to calculate 3 power 13, then 13 could be divided into 13=8+4+1
so we just need 3 power 8 * 3 power 4 and 3 power 1 to get our answer
*/
int main()
{
    int x = 2, n = 10;
    long long ans = 1;
    while (n != 0)
    {
        if (n % 2 == 0)
        {
            x = x * x;
            n /= 2;
        }
        else
        {
            ans = ans * x;
            n -= 1;
        }
    }
    if (n < 0)
        ans = float(1 / ans);
    cout << "ans: " << ans << endl;
}