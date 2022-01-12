#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bfs(int i, int j, vector<vector<int>> &grid, int n, int m)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        int x[] = {0, 0, 1, 1, 1, -1, -1, -1};
        int y[] = {1, -1, 0, 1, -1, 0, 1, -1};
        int count = 0;
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            // count++;
            for (int i = 0; i < 8; i++)
            {
                int xx = temp.first + x[i];
                int yy = temp.second + y[i];

                if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == 1)
                {
                    grid[xx][yy] = 0;
                    q.push({xx, yy});
                }
            }
            if (q.size())
                count++;
        }

        return count;
    }

    int findMaxArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    int count = bfs(i, j, grid, n, m);
                    ans = max(ans, count);
                }
            }
        }

        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //         cout<<grid[i][j]<<" ";
        //     cout<<endl;
        // }

        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.findMaxArea(grid);
        cout << ans << "\n";
    }
    return 0;
}