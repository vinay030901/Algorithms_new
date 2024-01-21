/*
Trie is an efficient information reTrieval data structure. Using Trie, search complexities can be brought to optimal limit (key length).
If we store keys in binary search tree, a well balanced BST will need time proportional to M * log N,
where M is maximum string length and N is number of keys in tree. Using Trie, we can search the key in O(M) time.
However the penalty is on Trie storage requirements

                       root
                    /   \    \
                    t   a     b
                    |   |     |
                    h   n     y
                    |   |  \  |
                    e   s  y  e
                 /  |   |
                 i  r   w
                 |  |   |
                 r  e   e
                        |
                        r*/

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int endwith = 0, countprefix = 0;
    node *next[26];
};

// this function is used to initialise the node for us
// all the 26 links are null and isWord is false
// isWord is only true when a word is ending there
node *newNode()
{
    // reference node is created here
    node *temp = new node();

    //here we have two variables, count ends with which is used to cound the word ending with some valaue, so they would be 
    // incremented at the end of the loop, so we will be having a certain count of words
    temp->endwith = 0;

    // count prefix is used for counting the words starting with certain values, if any word repeats with its starting values
    // this count will increase
    temp->countprefix = 0;
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

        // so here we are incrementing the count of the prefix, whenver a character occur, it coult be 1 or higher
        // 0 is only for the starting character of the word
        temp->countprefix += 1;
        temp = temp->next[key[i] - 'a']; // referencing our node to the new node
    }

    // we increase the end with at the end of the array and this will help to count the words
    temp->endwith += 1;
}

int countWords(node *head, string key)
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

    // if we reach here, means the word is found, so we can now return the count
    return temp->endwith;
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
    return temp->countprefix;
}
void erase(node *head, string key)
{
    node *temp = head;
    for(int i = 0; i < key.length(); i++)
    {
        if(temp->countprefix>0)
        temp->countprefix-=1;
    }
    if(temp->endwith>0)
    temp->endwith-=1;
}
int main()
{
    node *head = newNode();
    string key;
    for (int i = 0; i < key.length(); i++)
        key[i] = tolower(key[i]);
    int ch;
    do
    {
        cout << "1 - insert\n2 - count words equal to\n3 - count words starting with\n4 - erase\nelse - exit\nenter your choice: ";
        cin >> ch;
        cout << "enter the key: ";
        cin >> key;
        if (ch == 1)
        {
            insert(head, key);
            cout << "key inserted\n";
        }
        else if (ch == 2)
        {
            int ans = countWords(head, key);
            if (ans == 0)
                cout << key << "not found\n";
            else
                cout << key << "  found " << ans << " times.\n";
        }

        else if (ch == 3)
        {
            int ans = countStartsWith(head, key);
            if (ans == 0)
                cout << "no words starts with " << key << "\n";
            else
                cout << ans << " words starts with " << key << "\n";
        }
        else if(ch==4){
            erase(head, key);
            cout<<key << " erased\n";
        }
        else
            exit(0);
    } while (true);
    return 0;
}