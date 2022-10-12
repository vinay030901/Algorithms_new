class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int> &col)
    {
        if(col[node]==-1) col[node]=1;
        for (auto it : adj[node])
        {
            if (col[it] == -1)
            {
                col[it]=1-col[node];
                if (dfs(it, adj, col))
                    return true;
            }
            else if (col[node] == col[it])
                return true;
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> col(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        if (col[i] == -1)
            if (dfs(i, adj, col))
                return false;
    }
    return true;
    }
};