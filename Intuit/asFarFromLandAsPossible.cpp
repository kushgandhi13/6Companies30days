#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        queue<pair<int, int>> q;
        map<pair<int, int>, bool> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    q.push({i, j}), mp[{i, j}] = true;
            }
        }

        if (q.size() == n * n)
            return -1;

        int step = 0;
        int x[] = {0, 0, 1, -1};
        int y[] = {1, -1, 0, 0};

        while (!q.empty())
        {
            step++;
            int size = q.size();
            for (int j = 0; j < size; j++)
            {
                auto temp = q.front();
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int xx = temp.first + x[i];
                    int yy = temp.second + y[i];
                    if (xx >= 0 && xx < n && yy >= 0 && yy < n && !mp[{xx, yy}])
                    {
                        grid[xx][yy] = step;
                        mp[{xx, yy}] = true;
                        q.push({xx, yy});
                    }
                }
            }
            // step++;
        }

        if (step == 0)
            return -1;
        return step - 1;
    }
};