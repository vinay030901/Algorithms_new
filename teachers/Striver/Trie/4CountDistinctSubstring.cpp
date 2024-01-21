#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *next[26];
    bool isend;
};
node *newNode()
{
    node *temp = new node();
    temp->isend = false;
    for (int i = 0; i < 26; i++)
        temp->next[i] = NULL;
    return temp;
}
int countDistinctSubstrings(node *head, string key)
{
    int cnt = 0;
    node *t = head;
    for (int j = 0; j < key.length(); j++)
    {
        node *temp = t;
        for (int i = j; i < key.length(); i++)
        {
            if (temp->next[key[i] - 'a'] == NULL)
            {
                temp->next[key[i] - 'a'] = newNode();
                cnt += 1;
            }
            temp = temp->next[key[i] - 'a'];
        }
        temp->isend = true;
    }
    return cnt + 1;
}
int main()
{
    string key = "abab";
    node *head = newNode();
    cout << countDistinctSubstrings(head, key);
}