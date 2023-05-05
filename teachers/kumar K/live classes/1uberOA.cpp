/*
Given an undirected graph having V nodes and E edges and each is of 2 colours(blue and red).
We have also been provided with a source node and destination node
Find out the max no of blue nodes in the shorted path from the source node to the destination node

how to solve:
1. keep the track of the level of each node
2. We have to figure out the shorted path from the source node to the destination node
3. When we travel the path

if we are visiting a node for the very first time, then-
- that node is on the shortest path
but if we are visiting a node for the second time, then that node could be on the shortest path or not on the shortest path
so if a node is visited, then we are going to verify if it is on the shortest path or not by checking if adding 1 to the current node level will give the level of the node we encountered.
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 5];
    int i = 1;
    // while ()
}