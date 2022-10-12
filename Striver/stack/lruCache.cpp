#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    // we will use doubly linked list for the task of checking the least recently used
    // and map for checking if the key is there or not
    struct Node
    {
        int key, value;
        Node *next;
        Node *prev;
        Node(int _key, int _value)
        {
            key = _key;
            value = _value;
        }
    };
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    unordered_map<int, Node *> mp;
    int cap;
    LRUCache(int capacity)
    {
        // for initialising the capacity of the cache.
        cap = capacity;
        // initialise the doubly linkedlist
        head->next = tail;
        tail->prev = head;
    }

    Node *addNode(Node *newnode)
    {
        Node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
        mp[newnode->key] = newnode;
    }
    Node *deleteNode(Node *deletenode)
    {
        Node *deleteprev = deletenode->prev;
        Node *deletenext = deletenode->next;
        deleteprev->next = deletenext;
        deletenext->prev = deleteprev;
    }
    int get(int key_)
    {
        if (mp.find(key_) != mp.end()) // key exists in map
        {
            Node *resnode = mp[key_];
            int res = resnode->value;
            mp.erase(key_);
            deleteNode(resnode); // delete the node from its position
            addNode(resnode);    // add the node to the head of the list
            mp[key_] = head->next;
            return res;
        }
        // if we don't find the node in map, we will return -1
        else
            return -1;
    }

    void put(int _key, int _value)
    {
        if (mp.find(_key) != mp.end()) // key exists in map
        {
            Node *existingnode = mp[_key];
            mp.erase(_key); // remove the node from
            deleteNode(existingnode);
        }
        if (mp.size() == cap) // if map size is equal to capacity, then we delete the least recently used value from map as well as list
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node *resnode = new Node(_key, _value);
        addNode(resnode);
        mp[_key] = resnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */