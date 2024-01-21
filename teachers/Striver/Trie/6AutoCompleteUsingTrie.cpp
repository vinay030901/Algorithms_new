/*
We are given a Trie with a set of strings stored in it. Now the user types in a prefix of his search query, 
we need to give him all recommendations to auto-complete his query based on the strings stored in the Trie. 
We assume that the Trie stores past searches by the users.
For example if the Trie store {“abc”, “abcd”, “aa”, “abbbaba”} 
and the User types in “ab” then he must be shown {“abc”, “abcd”, “abbbaba”}.*/

#include<bits/stdc++.h>
using namespace std;
struct node
{
    bool isWord;
    node *next[26];
};

// this function is used to initialise the node for us
// all the 26 links are null and isWord is false
// isWord is only true when a word is ending there
node *newNode()
{
    // reference node is created here
    node *temp = new node();
    temp->isWord = false;
    for (int i = 0; i < 26; i++)
        temp->next[i] = NULL;

    return temp;
}

void insert(node *head, string key)
{
    // we are inserting the word here, we will traverse the whole key and check if the character is available
    // or not, if it is not available, we will make a new node for it which would be reference node for the present character
    // when the loop completes, we will make isWord tree, which marks the end of the word
    node *temp = head;
    for (int i = 0; i < key.length(); i++)
    {
        if (temp->next[key[i] - 'a'] == NULL)
            temp->next[key[i] - 'a'] = newNode(); // creating a new node
        temp = temp->next[key[i] - 'a'];          // referencing our node to the new node
    }
    temp->isWord = true;
}

bool search(node *head, string key)
{
    // in search we will traverse the node and if the node is not there, we will return false, if we reach the end of the
    // string, we will check if the isWord is true, marking it as the end of the word, if true return true else false
    node *temp = head;
    for (int i = 0; i < key.length(); i++)
    {
        if (temp->next[key[i] - 'a'] == NULL)
            return false;
        temp = temp->next[key[i] - 'a'];
    }
    return temp->isWord;
}

bool startsWith(node *head, string key)
{
    node *temp = head;
    for (int i = 0; i < key.length(); i++)
    {
        if (temp->next[key[i] - 'a'] == NULL)
            return false;
        temp = temp->next[key[i] - 'a'];
    }
    return true;
}

void suggest(node *head, string key)
{
    if(head->isWord==true) cout<<key<<endl;

    for(int i=0;i<26;i++)
    {
        if(head->next[i]){
            char c=i+'a';
            suggest(head->next[i],key+c);
        }
    }
}
int printAutoSuggestions(node *head,string key)
{
    node *temp=head;
    for(int i=0; i < key.length(); i++)
    {
        if(!temp->next[key[i] - 'a']) return 0;
        temp= temp->next[key[i] - 'a'];
    }

    if(temp->isWord==true){
        cout<<key<<endl;
        return -1;
    }
    suggest(temp,key);
    return 1;
}
int main()
{
    node *head=newNode();
    vector<string>str={"abb","abc","abd","bce","bcd","b"};
    for(int i=0;i<str.size();i++)
    insert(head,str[i]);

    string key="ab";
    if(printAutoSuggestions(head,key)==-1) cout<<key<<" is itself a word and no other suggestions found\n";
    else if(printAutoSuggestions(head,key)==0) cout<<"no suggestions found\n";
    else cout<<"these words were found\n";
}