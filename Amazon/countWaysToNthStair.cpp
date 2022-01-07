#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int curr, bool flag, int n, vector<vector<int>> &dp)
    {
        if (curr > n)
            return 0;
        if (curr == n)
            return 1;
        if (dp[curr][flag] != -1)
            return dp[curr][flag];
        if (!flag)
            return dp[curr][flag] = solve(curr + 1, flag, n, dp) + solve(curr + 2, !flag, n, dp);
        else
            return dp[curr][flag] = solve(curr + 2, flag, n, dp);
    }

    long long countWays(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return (long long)solve(0, false, n, dp);
    }
};

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl;
    }
    return 0;
}