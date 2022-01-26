#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(vector<int> &piles, int h, long long mid)
    {
        // int curSum=0;
        long long curHours = 0;
        for (int i = 0; i < piles.size(); i++)
            curHours += (int)ceil((piles[i] * 1.0) / mid);

        return (curHours <= (long long)h);
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        long long r = 0;
        for (auto x : piles)
            r += x;
        long long l = 1;
        long long ans = -1;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            if (solve(piles, h, mid))
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }

        return (int)ans;
    }
};