/*
Given an array of strings words, find the longest string in words such that every prefix of it is also in words.

For example, let words = ["a", "app", "ap"]. The string "app" has prefixes "ap" and "a", all of which are in words.
Return the string described above. If there is more than one string with the same length, return the lexicographically smallest one, and if no string exists, return "".

Example 1:

Input: words = [“k”,”ki”,”kir”,”kira”, “kiran”]

Output: “kiran”

Explanation: “kiran” has prefixes “kira”, “kir”, “ki”, and “k”, and all of them appear in words.

Example 2:

Input: words = [“a”, “banana”, “app”, “appl”, “ap”, “apply”, “apple”]

Output: “apple”

Explanation: Both “apple” and “apply” have all their prefixes in words. However, “apple” is lexicographically smaller, so we return that.

Example 3:

Input: words = [“abc”, “bc”, “ab”, “qwe”]

Output: “”  */

#include <bits/stdc++.h>
using namespace std;
struct node
{
    bool isWord;
    node *next[26];
};
node *newNode()
{
    node *temp = new node();
    temp->isWord = false;
    for (int i = 0; i < 26; i++)
        temp->next[i] = NULL;
    return temp;
}
void insert(node *head, string key)
{
    node *temp = head;
    for (int i = 0; i < key.length(); i++)
    {
        if (temp->next[key[i] - 'a'] == NULL)
            temp->next[key[i] - 'a'] = newNode();
        temp = temp->next[key[i] - 'a'];
    }
    temp->isWord = true;
}
bool search(node *head, string key)
{
    node *temp = head;
    for (int i = 0; i < key.length(); i++)
    {
        if (temp->next[key[i] - 'a'] == NULL)
            return false;
        temp = temp->next[key[i] - 'a'];
    }
    return temp->isWord;
}
bool allPrefixExists(node *head, string it)
{
    string s="";
    for(int i=0;i<it.length();i++)
    {
        s+=it[i];
        if(!search(head,s)) return false;
    }
    return true;
}
string LongestWordWithAllPrefixes(node *head,vector<string>str)
{
    node *temp = head;
    for(auto &it:str)
    insert(head,it);

    string longest="";
    for(auto &it:str)
    {
        if(allPrefixExists(head,it))
        {
            if(it.length()>longest.length())
            longest=it;
            else if(it.length()==longest.length() && it<longest) it=longest;
        }
    }
    return longest;
}
int main()
{
    vector<string> str = {"n", "ni", "nin", "ninj", "ning", "ninja","ninjas"};
    node *head= newNode();
    cout<<LongestWordWithAllPrefixes(head,str);
}