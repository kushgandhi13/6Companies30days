#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int arr[], int curIndex, bool buy, int capacity, int k, vector<vector<vector<int>>> &dp, int n)
    {
        if (curIndex == n || capacity == k)
            return 0;
        if (dp[curIndex][buy][capacity] != -1)
            return dp[curIndex][buy][capacity];
        if (buy)
            return dp[curIndex][buy][capacity] = max(solve(arr, curIndex + 1, !buy, capacity, k, dp, n) - arr[curIndex], solve(arr, curIndex + 1, buy, capacity, k, dp, n));
        else
            return dp[curIndex][buy][capacity] = max(solve(arr, curIndex + 1, !buy, capacity + 1, k, dp, n) + arr[curIndex], solve(arr, curIndex + 1, buy, capacity, k, dp, n));
    }

    int maxProfit(int k, int n, int arr[])
    {
        if (k == 0)
            return 0;

        if (2 * k > n)
        {
            int ans = 0;
            for (int i = 1; i < n; i++)
                ans += max(0, arr[i] - arr[i - 1]);

            return ans;
        }

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(arr, 0, true, 0, k, dp, n);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}