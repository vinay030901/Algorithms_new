#include <bits/stdc++.h>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int N, long long int k)
{
    vector<long long> res;
    deque<long long> dq;
    for (long long i = 0; i < N; i++)
    {
        // while (!dq.empty() && arr[dq.back()] <= arr[i])
        //     dq.pop_back();
        if (arr[i] < 0)
            dq.push_back(i);
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        if (i >= k - 1)
            if (dq.empty())
                res.push_back(0);
            else
                res.push_back(arr[dq.front()]);
    }
    return res;
}
int main()
{
}