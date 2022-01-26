#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int ans = 0;
        int n = points.size();

        for (int i = 0; i < n; i++)
        {
            unordered_map<long long, int> mp(points.size());

            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                int yy = points[i][1] - points[j][1];
                int xx = points[i][0] - points[j][0];

                int dist = yy * yy;
                dist += xx * xx;

                mp[dist]++;
            }

            for (auto &x : mp)
            {
                if (x.second >= 2)
                    ans += (x.second) * (x.second - 1);
            }
        }

        return ans;
    }
};