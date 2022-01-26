#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(vector<int> &weights, int days, int mid)
    {
        int totalDays = 0;
        int curSum = 0;

        for (int i = 0; i < weights.size(); i++)
        {
            if (weights[i] > mid)
                return false;

            if (weights[i] + curSum <= mid)
                curSum += weights[i];
            else
            {
                totalDays++;
                curSum = weights[i];
            }
        }

        totalDays++;
        return (totalDays <= days);
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int l = 0, r = 25000001;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (solve(weights, days, mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};