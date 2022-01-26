#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> v;
        // unordered_map<int,int>mp;

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == 0)
                    count++;
                else
                    break;
            }
            v.push_back(count);
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] >= n - i - 1)
                continue;
            int j = i;
            while (j < n && v[j] < n - i - 1)
                j++;
            if (j == n)
                return -1;

            while (j > i)
            {
                swap(v[j], v[j - 1]);
                j--;
                sum++;
            }
        }

        return sum;
    }
};