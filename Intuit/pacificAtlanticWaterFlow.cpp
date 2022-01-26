#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int row, int col, int ocean, int pre, vector<vector<int>> &vis, vector<vector<int>> &heights, vector<vector<int>> &ans)
    {
        if (row >= heights.size() || row < 0 || col >= heights[0].size() || col < 0 || vis[row][col] == 3 || vis[row][col] == ocean || heights[row][col] < pre)
            return;

        vis[row][col] += ocean;
        if (vis[row][col] == 3)
            ans.push_back({row, col});
        dfs(row + 1, col, ocean, heights[row][col], vis, heights, ans);
        dfs(row, col + 1, ocean, heights[row][col], vis, heights, ans);
        dfs(row - 1, col, ocean, heights[row][col], vis, heights, ans);
        dfs(row, col - 1, ocean, heights[row][col], vis, heights, ans);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        vector<vector<int>> ans;
        int n = heights.size();
        int m = heights[0].size();

        int x[] = {0, 0, 1, -1};
        int y[] = {1, -1, 0, 0};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++)
        {
            // pacific[0][i] = true;
            // atlantic[n-1][i] = true;
            dfs(0, i, 1, INT_MIN, vis, heights, ans);
            dfs(n - 1, i, 2, INT_MIN, vis, heights, ans);
        }

        for (int i = 0; i < n; i++)
        {
            // pacific[i][0] = true;
            // atlantic[i][m-1] = true;
            dfs(i, 0, 1, INT_MIN, vis, heights, ans);
            dfs(i, m - 1, 2, INT_MIN, vis, heights, ans);
        }

        return ans;
    }
};