/*
Given a list of word lists How to print all sentences possible taking one word from a list at a time via recursion?

Example:

Input: {{"you", "we"},
        {"have", "are"},
        {"sleep", "eat", "drink"}}

Output:
  you have sleep
  you have eat
  you have drink
  you are sleep
  you are eat
  you are drink
  we have sleep
  we have eat
  we have drink
  we are sleep
  we are eat
  we are drink */

#include <bits/stdc++.h>
using namespace std;
int R = 3, C = 3;
void printAll(vector<vector<string>> &arr, int row, int col, vector<string> output)
{
  output[row] = arr[row][col];
  if (row == R - 1)
  {
    for (auto &it : output)
      cout << it << " ";
    cout << endl;
    return;
  }
  for (int i = 0; i < C; i++)
  {
    if (arr[row + 1][i] != "")
      printAll(arr, row + 1, i, output);
  }
}
int main()
{
  vector<vector<string>> arr(R, vector<string>(C));
  arr = {{"you", "we"}, {"have", "are"}, {"sleep", "eat", "drink"}};
  vector<string> output(R);
  for (int i = 0; i < C; i++)
    if (arr[0][i] != "")
      printAll(arr, 0, i, output);
}