#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    struct Node
    {
        int val, key;
        struct Node *next, *prev;
        Node(int _key, int _val)
        {
            val = _val;
            key = _key;
        }
    };
    int cap;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    unordered_map<int, Node *> mp;
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node *node)
    {
        Node *temp = head->next;
        node->prev = head;
        node->next = temp;
        head->next = node;
        temp->prev = node;
        mp[node->key] = node;
    }
    void deleteNode(Node *node)
    {
        Node *prenode = node->prev;
        Node *nex = node->next;
        prenode->next = node->next;
        nex->prev = node->prev;
    }
    int get(int _key)
    {
        if (mp.find(_key) != mp.end())
        {
            Node *res = mp[_key];
            int ans = res->val;
            mp.erase(_key);
            deleteNode(res);
            addNode(res);
            return ans;
        }
        return -1;
    }

    void put(int _key, int _value)
    {
        if (mp.find(_key) != mp.end())
        {
            Node *node = mp[_key];
            deleteNode(node);
            mp.erase(_key);
        }
        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node *p = new Node(_key, _value);
        addNode(p);
    }
};