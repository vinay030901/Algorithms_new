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
int main()
{
    node *head = newNode();
    string key;
    for (int i = 0; i < key.length(); i++)
        key[i] = tolower(key[i]);
    int ch;
    do
    {
        cout << "1 - insert\n2 - search\n3 - start with\nelse - exit\nenter your choice: ";
        cin >> ch;
        cout << "enter the key: ";
        cin >> key;
        if (ch == 1)
        {
            insert(head, key);
            cout << "key inserted\n";
        }
        else if (ch == 2)
            if (search(head, key))
                cout << key << " found\n";
            else
                cout << key << " not found\n";

        else if (ch == 3)
            if (startsWith(head, key))
                cout << "a word starts with " << key << endl;
            else
                cout << "a word doesn't start with " << key << endl;
        else
            exit(0);
    } while (true);
    return 0;
}