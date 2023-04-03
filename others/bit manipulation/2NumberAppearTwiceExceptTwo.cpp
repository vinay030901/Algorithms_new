#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {2, 1, 2, 5, 1, 4, 4, 7, 3, 3};
    int xor_val = 0;

    // in this solution 5 and 7 appear once and all other appear twice
    // when we do xor of all the element, we will get 2, means 5 xor 7 is 2
    // now we can see that 2 is 010, the reason there is xor on second position,
    // is because there was 0 in 5 and 1 in 7, and there xor gave the answer
    // now we can traverse the whole array and check if the 1st bit is set or not
    /*
    (1st bit unset)  (1st bit set)
        5 group   |   7 group
        1               2
        5               2
        1               7
        4               3
        4               3
    now when we do xor of both these groups, we will get 2 numbers- 5 and 7, and that's our answer*/
    for (auto it : arr)
        xor_val = (xor_val ^ it);
    int cnt = 0;
    while (xor_val)
    {
        if (xor_val & 1)
            break;
        xor_val = xor_val >> 1;
        cnt++;
    }
    int set_bit = 0, unset_bit = 0, mask = (1 << cnt);
    for (auto it : arr)
    {
        if (mask & it)
            set_bit = set_bit ^ it;
        else
            unset_bit = unset_bit ^ it;
    }
    cout << "answer: " << set_bit << " " << unset_bit << endl;
}