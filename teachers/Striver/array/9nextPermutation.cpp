// find the next permutation */
#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int> &nums, int i, int j)
{
    while (i < j)
    {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    if (nums.size() <= 1)
        return;
    int ind;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }

    int j = n - 1;
    if (ind >= 0)
    {
        while (nums[ind] >= nums[j])
            j--;
        swap(nums[ind], nums[j]);
    }
    cout << "value of j is: " << j << endl;
    cout << "value of string before reverse: ";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    reverse(nums, ind + 1, n - 1);
    cout << "\n value after reverse: ";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
}
int main()
{
    vector<int> nums = {1, 3, 5, 4, 2};
    nextPermutation(nums);
}