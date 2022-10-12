/* a topo sort is defined as the linear ordering of vertices such that if there is an edge u->v, then u appears before v in
that ordering

topological sort is for directed acyclic graph only*/

#include <bits/stdc++.h>
using namespace std;

/*to find topological sort, we first find the indegree of every element in it, means the number of edges coming towards the element
we make a vector and put all the indegrees in it
we require another data structure, that is, queue
we traverse the indegree vector and push the elements which has the lowest indegrees
and then we will do basic bfs, first we will take out an element and then traverse its childs
and then decrease their indegree by 1
as soon as the indegree of any element become zero, we pickup the node and put into the queue
then we can put the element, that was popped out of queue into our answer vector

THIS IS ALSO CALLED KAHN'S ALGO
*/

vector<int> topoSort(int n, vector<int> adj[])
{
    vector<int> indegree(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++)
        for (auto it : adj[i])
            indegree[it]++;

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return topo;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 0; i < n; i++)
    {
        cout << i;
        for (auto x : adj[i])
            cout << " --> " << x;
        cout << "\n";
    }
    vector<int> topo = topoSort(n, adj);
    for (int i = 0; i < topo.size(); i++)
        cout << topo[i] << " ";
}