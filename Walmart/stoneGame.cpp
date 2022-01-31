#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int l, int r, vector<int> &piles, vector<vector<int>> &dp)
    {
        if (r < 0 || l >= piles.size())
            return 0;
        if (l >= r)
            return dp[l][r] = 0;
        if (dp[l][r] != -1)
            return dp[l][r];
        int left = piles[l] + min(solve(l + 2, r, piles, dp), solve(l + 1, r - 1, piles, dp));
        int right = piles[r] + min(solve(l + 1, r - 1, piles, dp), solve(l, r - 2, piles, dp));
        return dp[l][r] = max(left, right);
    }

    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        int sum = 0;
        for (auto &x : piles)
            sum += x;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = solve(0, n - 1, piles, dp);

        // if(sum&1)
        return (ans * 2 > sum);
    }
};