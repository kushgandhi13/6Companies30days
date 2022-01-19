#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &arr, int left, int right, vector<vector<int>> &dp)
    {
        if (left > right)
            return dp[left][right] = 0;
        if (left == right)
            return dp[left][right] = arr[left];
        if (dp[left][right] != -1)
            return dp[left][right];

        int lchoice = arr[left] + min(solve(arr, left + 2, right, dp), solve(arr, left + 1, right - 1, dp));
        int rchoice = arr[right] + min(solve(arr, left + 1, right - 1, dp), solve(arr, left, right - 2, dp));
        return dp[left][right] = max(lchoice, rchoice);
    }

    int maxCoins(vector<int> &arr, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(arr, 0, n - 1, dp);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
