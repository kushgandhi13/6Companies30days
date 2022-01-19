#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    long long solve(int n, int temp, int x, vector<vector<long long>> &dp)
    {
        if (n == 0)
            return 1;
        if (n < 0 || temp <= 0)
            return 0;
        if (dp[n][temp] != -1)
            return dp[n][temp];
        return dp[n][temp] = solve(n - pow(temp, x), temp - 1, x, dp) + solve(n, temp - 1, x, dp);
    }

    long long numOfWays(int n, int x)
    {
        if (n == 1)
            return 1;
        int temp = pow(n, 1.0 / x);
        vector<vector<long long>> dp(n + 1, vector<long long>(temp + 1, -1));
        return solve(n, temp, x, dp);
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        Solution ob;
        cout << ob.numOfWays(n, x) << endl;
    }
    return 0;
}
