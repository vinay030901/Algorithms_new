/*Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate 
characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped. 
Examples : 
 

Input : str = “001”
Output : 1
Minimum number of flips required = 1
We can flip 1st bit from 0 to 1 

Input : str = “0001010111”
Output : 2
Minimum number of flips required = 2
We can flip 2nd bit from 0 to 1 and 9th 
bit from 1 to 0 to make alternate 
string “0101010101”.*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str = "001";

    // if it start with 0

    // in this question we will have two condition, either start with 0 or with 1
    int cnt=0,cnt1=0;
    for(int i=0;i<str.length();i++)
    {
        // if we start with 0, then we will count the value in which we are having 1 at even position or 0 at odd position
        if(i%2==0 && str[i]=='1') cnt++;
        if(i%2==1 && str[i]=='0') cnt++;

        // if we start with 1, then we will count the value in which we are having 1 at odd position or 0 at even position
        if(i%2==1 && str[i]=='1') cnt1++;
        if(i%2==0 && str[i]=='0') cnt1++;
    }
    cout<<min(cnt,cnt1);// then we will return the minimum of those values
}