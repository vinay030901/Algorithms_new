#include <bits/stdc++.h>
using namespace std;

    long long countPairs(vector<int> &m, int kk)
    {
        vector<int> v(kk, 0);
        long long c = 0;
        long long n = m.size();
        for (int i = 0; i < n; i++)
        {
            v[m[i] % kk]++;
        }
        c += (v[0] * (v[0] - 1)) / 2;
        for (long long i = 1; i < kk; i++)
            c += v[i] * v[0];
        for (long long k = kk; k <= (kk - 1) * kk; k += kk)
        {
            for (int i = 2; i * i <= (k); i++)
            {
                if (k % i == 0 && i * i != k)
                    c += v[i] * v[k / i];
                else if (i * i == k && k % i == 0)
                    c += ((v[0] * (v[0] - 1)) / 2);
            }
        }
        return c;
    }
int main()
{
    vector<int> arr = {1,2,3,4};
    cout << countPairs(arr,5);
}
