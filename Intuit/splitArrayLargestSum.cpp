#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(vector<int> &nums, int m, int mid)
    {
        int totalSum = 0;
        int totalSubarrays = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > mid)
                return false;

            if (nums[i] + totalSum <= mid)
                totalSum += nums[i];
            else
            {
                totalSubarrays++;
                totalSum = nums[i];
            }
        }
        totalSubarrays++;
        return (totalSubarrays <= m);
    }

    int splitArray(vector<int> &nums, int m)
    {
        int l = 0, r = (int)(1e9 + 1);
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (solve(nums, m, mid))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};