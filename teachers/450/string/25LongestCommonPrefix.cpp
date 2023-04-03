/*
Given a set of strings, find the longest common prefix. 
Examples: 
 

Input  : {“geeksforgeeks”, “geeks”, “geek”, “geezer”}
Output : "gee"

Input  : {"apple", "ape", "april"}
Output : "ap"*/
#include<bits/stdc++.h>
using namespace std;
struct node{
    int isword=0,countPrefix=0;
    node *next[26];
};
string findLCP(string str1,string str2)
{
    string max="";
    int n=str1.length(),m=str2.length();
    for(int i=0;i<min(n,m);i++)
    {
        if(str1[i]==str2[i])
        max+=str1[i];
        else
        {
            return max;
        }
    }
    return max;
}
string WordByWord(vector<string>strings,int n)
{
    string lcp=strings[0];
    for(int i=1;i<n;i++)
    {
        lcp=findLCP(lcp,strings[i]);
    }
    return lcp;
}
string characterByCharacter(vector<string>strings,int n)
{
    int minlen=strings[0].length();
    for(int i=1;i<n; i++) 
    if(strings[i].length()<minlen)
    minlen=strings[i].length();

    string lcp="";
    for(int i=0;i<minlen;i++)
    {
        char str=strings[0][i];
        for(int j=1;j<strings.size();j++)
            if(strings[j][i]!=str)
            return lcp;
        lcp+=str;
    }
    return lcp;
}

int countStartsWith(node *head, string key)
{
    node *temp = head;
    for (int i = 0; i < key.length(); i++)
    {
        if (temp->next[key[i] - 'a'] == NULL)
            return false;
        temp = temp->next[key[i] - 'a'];
    }
    return temp->countPrefix;
}
node *newNode()
{
    node *temp=new node();
    temp->isword = 0;
    temp->countPrefix=0;

    for(int i=0;i<26;i++)
    temp->next[i] = NULL;
    return temp;
}
void insert(node *head, string key)
{
    node *temp=head;
    for(int i=0;i<key.length(); i++)
    {
        if(temp->next[key[i] - 'a'] == NULL)
        temp->next[key[i] - 'a'] = newNode();
        temp->countPrefix+=1;

        temp=temp->next[key[i] - 'a'];
    }
    temp->isword +=1;
}
string trie(vector<string>strings,int n)
{
    node *head=newNode();
    for(int i=0;i<n;i++) insert(head,strings[i]);

    string str=strings[0],key="",ans="";
    for(int i=0;i<str.length();i++)
    {
        key+=str[i];
        if(countStartsWith(head,key)!=n)
            return ans;
        else ans+=str[i];
    }
    return key;
}
string sorting(vector<string>strings,int n)
{
    if(n==0) return "";
    if(n==1) return strings[0];
    sort(strings.begin(), strings.end());
    string str1=strings[0],str2=strings[n-1];
    int s1=str1.length(),s2=str2.length();
    int len=min(s1,s2);
    string lcp="";
    for(int i=0;i<len;i++)
    if(str1[i]==str2[i]) lcp+=str1[i];
    else return lcp;
    return lcp;
}
int main()
{
    vector<string>strings={"geeksforgeeks", "geeks", "geek", "geezer"};
    int n=strings.size();

    /* the first method which comes in the mind is to match every character one by one, we will traverse the whole vector
    and find the longest common prefix in pairs, as we can see that
    LCP(s1,s2,s3)=LCP(LCP(s1,s2),s3)
    */

    cout<<"longest common prefix using word by word matching: "<<WordByWord(strings,strings.size())<<endl;

    /*word by word matching works in O(mn) complexity, similar method is character by character matching, here instead 
    of going one by one, we make a 2D vector and then check if the values in that column in equal or not

    c1 c2 c3 c4 c5
    g  e  e  k  s
    g  e  e  k  s  f o r 
    g  e  e  z  e r

    so the column are same till c3 and therefore our lcp is gee*/

    cout<<"longest common prefix using character by character matching: "<<characterByCharacter(strings,strings.size());

    /*next method is to sort the string, its obvious that whenever we sort the string, if the starting alphabets are same
    they will be in the same position, ex - geets, gen, geep, geex
    so when we sort this, we will have: geep,geets,geex,gen
    so the same character are ahead here, and when we find the lcp of geep and gen, we will arrive with ge which 
    is the longest palindromic substrint among them*/

    cout<<"\nlongest common prefix using sorting: "<<sorting(strings,n);

    /* we can also do this using tree, we will first insert all the string the trie, then we traverse the trie and 
    check the word count there, that is how many strings reached at the same characters, if we it is equal to no of strings,
    then we will traverse further and if it is less, then we will return the resultant string*/

    cout<<"\nlongest common prefix using trie: "<<trie(strings,n);  
}