/*
Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details. 
This is a famous Google interview question, also being asked by many other companies now a days.

Consider the following dictionary 
{ i, like, sam, sung, samsung, mobile, ice, 
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes 
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" 
or "i like sam sung".*/
#include<bits/stdc++.h>
using namespace std;
bool dictionaryContains(string word)
{
    vector<string>dictionary={"i","like","sam","sung","samsung","mobile","ice", "cream","icecream","man","go","mango"};

    for(int i=0;i<dictionary.size(); i++)
    if(dictionary[i]==word) return true;
    return false;
}
bool wordBreak(string str){
  int n=str.size();
  if(n==0) return true;
  
  for(int i=1;i<=n;i++) // here we are checking for the every possible size of the string
  {
    if(dictionaryContains(str.substr(0,i)) && wordBreak(str.substr(i,n-i))){
      return true;
    }
  }
  return false;
}
int main()
{
    string str="ilikesamsung";
    int n=str.size();

    /*here we need to find proper words, this string can have any number of words of the dictionary
    and we need to find break the string to make it a sentence of those words
    
    constraint: 
    1.segmented word must be present in dictionary
    2. we can have more than one string.
    3. we can use reuse dictionary words
    
    the most intuitive approach is to use backtracking,
    we can do this using recursion, we will partition at each point, all the character will give us a partition point.
    
    if we have string: "mypenmy" with dic={"my","pen"} 
    so we will not partition at m, because word it not valid, then we will check for "my"
    so will partition, then "pen" will occurr and then "my"
    
    but unlike the above, we don't know whether our choice of word is correct or not, there could be an answer 
    where we are not taking my and need to take a longer one.
    
    so in recursion, each position will have two choices, so the time complexity of this approach is O(2^n)
    
    we can see the we have various subproblems forming here, so dp approach is possible*/

    cout<<"using recursion"<<endl;
    wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    wordBreak("iiiiiiiimangos")? cout <<"Yes\n": cout << "No\n";
    wordBreak("isung")? cout <<"Yes\n": cout << "No\n";

    /*
    dp states:
    1. When we are at pos, previous substring is guaranteed to be present in set/dict.
    then we need to check only from pos to endl
    2. if substring from pos to end have valid segements then the entire string 0 to end will valid
    
    so we need to store result of validity for subproblems from pos to end
    weeeeWEEEEEEEEEEEEEEEEEEEEE3EWWWWWWWWWWWWhere time complexity: O(n^3)*/

  unordered_set<string>dict={"i","like","sam","sung","samsung","mobile","ice", "cream","icecream","man","go","mango"};
  bool dp[n+1][n+1];
  memset(dp,0,sizeof(dp));
  for(int length=1;length<=n;++length){
    int start=1;
    int end=length;
    while(end<=n)
    {
      string temp=str.substr(start-1,length);
      if(dict.find(temp)!=dict.end())
      {
        dp[start][end]=true;
      }
      else
      {
        bool flag=false;
        for(int i=start;i<end;i++) // checking for the every possibility of that substring
        {
          if(dp[start][i] and dp[i+1][end])
          {
            flag=true;
            break;
          }
          dp[start][end]=flag;
        }
      }
      start+=1;
      end+=1;
    }
  }
  cout<<"using dp: ";
  cout<<dp[1][n]<<endl;
  for(int i=0;i<=n; i++)
  {
    for(int j=0;j<= n; j++)
    cout<<dp[i][j]<<" ";
    cout<<"\n";
  }
}
