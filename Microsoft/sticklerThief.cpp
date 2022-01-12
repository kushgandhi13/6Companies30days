#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int FindMaxSum(int arr[], int n)
    {
        if (n == 1)
            return arr[0];

        vector<int> dp(n);
        dp[0] = arr[0];
        dp[1] = max(arr[1], arr[0]);

        for (int i = 2; i < n; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
        return dp[n - 1];
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

        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;

        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends