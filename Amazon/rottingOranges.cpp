#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        int dir[] = {0, 1, 0, -1, 0};
        int ans = -1;
        while (!q.empty())
        {

            int size = q.size();
            while (size--)
            {
                auto temp = q.front();
                int r = temp.first;
                int c = temp.second;
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int xx = r + dir[i];
                    int yy = c + dir[i + 1];

                    if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == 1)
                    {
                        grid[xx][yy] = 2;
                        q.push({xx, yy});
                        fresh--;
                    }
                }
            }
            ans++;
        }

        if (fresh > 0)
            return -1;
        if (ans == -1)
            return 0;
        return ans;
        ;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int rows, cols;
        cin >> rows >> cols;
        vector<vector<int>> grid(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> grid[i][j];
            }
        }

        Solution ob;
        cout << ob.orangesRotting(grid) << "\n";
    }
    return 0;
}