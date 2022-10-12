/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.



Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4*/

#include <bits/stdc++.h>
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
int main()
{
}