#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMoneyAmount(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int len = 1; len < n; len++)
        {
            for (int i = 1; i + len <= n; i++)
            {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j; k++)
                {
                    int temp = k + max(k - 1 >= i ? dp[i][k - 1] : 0, k + 1 <= j ? dp[k + 1][j] : 0);
                    dp[i][j] = min(dp[i][j], temp);
                }
            }
        }
        return dp[1][n];
    }
};