#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int solve(int arr[], int curIndex, int curSum, int sum, int n, vector<vector<int>> &dp)
    {
        if (curIndex == n)
            return abs(sum - (curSum * 2));
        if (dp[curIndex][curSum] != -1)
            return dp[curIndex][curSum];
        return dp[curIndex][curSum] = min(solve(arr, curIndex + 1, curSum + arr[curIndex], sum, n, dp), solve(arr, curIndex + 1, curSum, sum, n, dp));
    }

    int minDifference(int arr[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        vector<vector<int>> dp(n, vector<int>(sum, -1));
        return solve(arr, 0, 0, sum, n, dp);
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
}