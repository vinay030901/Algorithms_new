/*
This problem is named after Flavius Josephus a Jewish historian who fought against the Romans. According to Josephus he and his group of Jewish soldiers were cornered & surrounded by the Romans inside a cave, and they choose to murder and suicide inside of surrender and capture. They decided that all the soldiers will sit in a circle and starting from the soldier sitting at the first position every soldier will kill the soldier to their sequentially. So if there are 5 soldiers sitting in a circle with positions numbered as 1, 2, 3, 4, 5. The soldier 1 kills 2, then 3 kills 4, then 5 kills 1, then 3 kills 5, and since 3 is the only one left then 3 commits suicide.


The Pattern

If you work this out for different values of n you will find a pattern here. If n is a true power of 2 then the answer is always 1. For every n greater than that power of 2 the answer is incremented by 2.

n soldiers	2a+ l	Survivor W(n) = 2l + 1
1	1 + 0	2 * 0 + 1 = 1
2	2 + 0	2 * 0 + 1 = 1
3	2 + 1	2 * 1 + 1 = 3
4	4 + 0	2 * 0 + 1 = 1
5	4 + 1	2 * 1 + 1 = 3
6	4 + 2	2 * 2 + 1 = 5
7	4 + 3	2 * 3 + 1 = 7
8	8 + 0	2 * 0 + 1 = 1
9	8 + 1	2 * 1 + 1 = 3
10	8 + 2	2 * 2 + 1 = 5
11	8 + 3	2 * 3 + 1 = 7
12	8 + 4	2 * 4 + 1 = 9*/

#include <bits/stdc++.h>
using namespace std;
int josephify(int n)
{

    int ans = log2(n);
    int l = n - pow(2, ans);
    return 2 * l + 1;
}

// hard coded driver main function to run the program
int main()
{
    int n = 41;
    cout << josephify(n);
    return 0;
}
