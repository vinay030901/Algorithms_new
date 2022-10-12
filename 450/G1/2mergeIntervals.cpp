#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int, int>> v{{1, 3}, {2, 6}, {8, 10}, {8, 9}, {9, 11}, {15, 18}, {2, 4}, {16, 17}};
    // we need to merge the intervals
    /*For example, let the given set of intervals be {{1,3}, {2,4}, {5,7}, {6,8}}.
    The intervals {1,3} and {2,4} overlap with each other,
    so they should be merged and become {1, 4}. Similarly, {5, 7} and {6, 8} should be merged and become {5, 8}*/

    // if the start of an element is greater than the other, they can be merged,
    // then we need to find the max of end of both of them

    // the first task we will do is to sort the intervals
    sort(v.begin(), v.end());
    cout << "sorted vector: \n";
    for (int i = 0; i < v.size(); i++)
        cout << v[i].first << " " << v[i].second << endl;
    // this could be done with and without extra space
    // first of all, with extra space
    vector<pair<int, int>> ans;
    int n = v.size(), i;
    for (i = 0; i < n; i++)
    {
        if (v[i].second > v[i + 1].first)
        {
            cout << "value: " << v[i].first << " " << v[i].second << endl;
            v[i + 1].first = v[i].first;
            v[i + 1].second = max(v[i].second, v[i + 1].second);
        }
        else
        {
            ans.push_back({v[i].first, v[i].second});
            cout << "ans: " << v[i].first << " " << v[i].second << endl;
        }
    }
    ans.push_back({v[i].first, v[i].second});
    cout << "merged with extra vector: \n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << endl;

    // merge without extra space
    int index = 0; // this will be the index for the answer
    for (int i = 1; i < n; i++)
    {
        if (v[index].second >= v[i].first)
            v[index].second = max(v[index].second, v[i].second);
        else
        {
            index++;
            v[index] = v[i]; // so that new value be compared now
        }
    }
    cout << "merged without extra space: \n";
    for (int i = 0; i <= index; i++)
        cout << v[i].first << " " << v[i].second << endl;
}