// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestAP(int arr[], int n)
    {
        if (n <= 2)
            return n;

        vector<unordered_map<int, int>> dp(n);
        int maxx = 2;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int diff = arr[j] - arr[i];
                if (dp[i].find(diff) != dp[i].end())
                    dp[j][diff] = dp[i][diff] + 1;
                else
                    dp[j][diff] = 2;

                maxx = max(maxx, dp[j][diff]);
            }
        }
        return maxx;
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
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}