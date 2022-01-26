#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int index, vector<bool> &vis, vector<int> adj[])
    {
        vis[index] = true;

        for (auto x : adj[index])
        {
            if (!vis[x] && x != index)
                dfs(x, vis, adj);
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (isConnected[i][j])
                    adj[i].push_back(j);
            }
        }

        int ans = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj);
                ans++;
            }
        }

        return ans;
    }
};