#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long mod = 1000000007;
    int kvowelwords(int n, int k)
    {
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1));
        for (int i = 0; i <= k; i++)
            dp[0][i] = 0;
        dp[1][0] = 21;
        for (int i = 1; i <= k; i++)
            dp[1][i] = 26;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                if (i == 0)
                    dp[i][j] = 1;
                else
                {
                    dp[i][j] = (dp[i - 1][k] * 21) % mod;
                    if (j > 0)
                    {
                        dp[i][j] = (dp[i][j] + (dp[i - 1][j - 1] * 5) % mod) % mod;
                    }
                }
            }
        }

        return dp[n][k];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        int K;
        cin >> N >> K;

        Solution ob;
        int ans = ob.kvowelwords(N, K);
        cout << ans << endl;
    }
    return 0;
}