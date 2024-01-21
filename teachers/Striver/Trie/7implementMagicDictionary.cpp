/*
Design a data structure that is initialized with a list of different words. Provided a string, you should determine 
if you can change exactly one character in this string to match any word in the data structure.
Implement the MagicDictionary class:

MagicDictionary() Initializes the object.
void buildDict(String[] dictionary) Sets the data structure with an array of distinct strings dictionary.
bool search(String searchWord) Returns true if you can change exactly one character in searchWord to match any string in 
the data structure, otherwise returns false.
2. Example
Example 1:
Input
[“MagicDictionary”, “buildDict”, “search”, “search”, “search”, “search”]
[[], [[“hello”, “leetcode”]], [“hello”], [“hhllo”], [“hell”], [“leetcoded”]]
Output
[null, null, false, true, false, false]

Explanation
MagicDictionary magicDictionary = new MagicDictionary();
magicDictionary.buildDict([“hello”, “leetcode”]);
magicDictionary.search(“hello”); // return False
magicDictionary.search(“hhllo”); // We can change the second ‘h’ to ‘e’ to match “hello” so we return True
magicDictionary.search(“hell”); // return False
magicDictionary.search(“leetcoded”); // return False*/

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

bool check(node *head, string key)
{
    
    for(int i=0; i < key.length(); i++)
    {
        
        for(int j=0;j<26;j++)
        {
            node*temp = head;
            string str=key;
            char c=j+'a';
            str[i]=c;
            if(str==key)
            {
                continue;
            }
            //cout<<str<<endl;
            if(search(temp,str)){
                cout<<str<<endl;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    node *head=newNode();
    insert(head,"leetcode");
    insert(head,"hello");
    if(check(head,"hhllo")==true) cout<<"hhllo is possible\n";
    else cout<<"hhllo is not possible\n";
    if(check(head,"leetcose")==true) cout<<"leetcose is possible\n";
    else cout<<"leetcose is not possible\n"; 
    
}