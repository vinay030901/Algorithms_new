/*
Check if string is shuffled substring of another string two string
Today we will be learning about how to Check if string is shuffled substring of another string.

Input string :-

  string 1 :- ABC

  string 2 :- DEF

  string 3 :- ABCDEF

Output:- here every character in string 3 is present in the shuffled form of string one and string 2.
that’s why string 3 is shuffled substring if another string*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
  string str1 = "abc", str2 = "def";
  string res = "adefbc";
  // one easy method is to sort all three strings and then compare them one by one
  // this method obviously take O(NlogN) complexity
  sort(res.begin(), res.end());
  string nstr = str1 + str2;
  sort(nstr.begin(), nstr.end());
  if (res == nstr)
    cout << "valid shuffle\n";
  else
    cout << "not a valid\n";

  /*another method could be to just traverse one by one and compare both of them
  if we reach the end of all three strings and all comparisons were equal,
  then it is a valid shuffle of two strings*/
  string s1 = "abc", s2 = "def";
  string r = "adefbc";

  int s1l = s1.length(), s2l = s2.length(), j = 0, k = 0, f = 0;
  if ((s1l + s2l) != r.length()) // if length is unequal, our answer is false
    f = 1;
  for (int i = 0; i < r.length(); i++)
  {
    if (j < s1l && r[i] == s1[j]) // if element is equal to string 1, then increase j
      j++;
    else if (k < s2l && r[i] == s2[k])
      k++;
    else
    {
      f = 1; // if encounter any other element other than of s1 and s2, we make f 1 and break
      break;
    }
  }
  if (f == 1 || j < s1l || k < s2l)
    cout << "not a valid shuffle";
  // if j is not equal to s1l, or k not equal to s2l or above is false, our answer is false
  else
    cout << "this is a valid shuffle";
}