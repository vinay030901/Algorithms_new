/*
Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.
Example 1:

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
Example 2:

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.
Example 3:

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.*/

/*
lets talk about the case when k<s.size() // coz it is confusing lol

it means we have to do k partitions

suppose no of odd occuring characters be : o
assuming o<=k

suppose these are k partitions, of different lengths ( might be of same length too)
i am represeting them by ---- ---- ----- ----- , where a character is present at ' - '

now there are 2 subcases , either all of the k partitions contain one odd character

here q->denotes any character with odd freq
---q1--- ---q2--- --q3-- --q4-- --q5--

---q1--- is one partition , while ---q2--- is another and so on

suppose character a and b have odd frequeny, so q1 can be a or b
and q2 can be b or a respectively

so after eliminating "odd frequency of odd occuring characters"
WE KNOW know every character has even freq.

now we can fill remaining spaces with elements .

---q1--- | ---q2--- | ---q3---| ---q4---

these are the partitions and we are left with characters having even freqency,
and the remaining length to be filled in all the partitions is s.size()-[q1+q2...(odd frequency)]
if any position of any partition is filled with any character,
we know that characters have even freq , so corresponding palindromic [reverse right to left]
position can be filled with same character.
and we have used 2 characters of same type, so we still have all the characters with even freq.

this is how we can fill all partitions.

now same ideology can be extended when o<k

suppose we put one odd character in each partition
so new partitions formed = o
partitions we need to create =k-o
remaining characters left=s.size()-o

now the ques is can we form k-o palindromic paritions given that
we are left with all even freqency characters

now there are further 2 subcases
when k-o is even
we are left with s.size()-o characters where (size()-o>k-o)
we know all the size()-o character has its sibling ( it occurs even number of time)

we need to create k-o ( even no. of partitions)
so what we can do, choose one character and its sibling, and you can create two new partitions
now in last steps, you will be left with characters , having even freq.
and you can put it anywhere. [ in any partition]

what if k-o is odd?

we know k-o-1 is even so first fill at the remaining k-o-1 places .
now we want to create one new partition right?
place all the remaining characters in that partition.

IT CAN BE SHOWED THAT WE CAN ALWAYS CONSTRUCT K-PALINDROMS!
;) THIS IS INDEPTH PROOF OF THE SOLUTION :D

i've not considered the trivial cases when s.size()<k || s.size()==k ;) they are self explanatory!*/
#include <bits/stdc++.h>
using namespace std;
bool canConstruct(string s, int k)
{
    if (s.size() < k)
        return false;
    int freq[26] = {0};
    for (auto &it : s)
        freq[it - 'a']++;
    int odd = 0;
    for (auto it : freq)
        odd += (it % 2);
    return odd <= k;
}
int main()
{
}