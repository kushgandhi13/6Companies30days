#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string str, int i, vector<int> &dp)
    {
        int temp1 = 0, temp2 = 0;
        if (i == str.length())
            return 1;
        if (str[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];

        if ((str[i] - '0') > 0)
            temp1 = solve(str, i + 1, dp);
        // temp2 = 0;
        if (i < str.length() - 1)
        {
            int num = (int)(str[i] - '0') * 10 + (int)(str[i + 1] - '0');
            if (num >= 10 && num <= 26)
                temp2 = solve(str, i + 2, dp);
        }

        return dp[i] = (temp1 + temp2) % 1000000007;
    }

    int CountWays(string str)
    {
        if (str[0] == '0')
            return 0;
        if (str.length() == 1)
            return 1;
        int n = str.length();
        vector<int> dp(10001, -1);
        return solve(str, 0, dp) % 1000000007;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.CountWays(str);
        cout << ans << "\n";
    }
    return 0;
}