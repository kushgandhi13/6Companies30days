#include <bits/stdc++.h>
using namespace std;

class Solution
{

    map<string, pair<int, string>> dp;

public:
    string matrixChainOrder(int A[], int n)
    {
        return solve(A, 0, n - 1).second;
    }

    pair<int, string> solve(int p[], int l, int r)
    {

        if (l + 1 == r)
            return {0, "" + string(1, l + 'A')};
        string key = to_string(l) + ";" + to_string(r);
        if (dp.count(key))
            return dp[key];

        int currMin = INT_MAX;
        string minString;
        for (int k = l + 1; k < r; k++)
        {
            auto temp = solve(p, l, k), p2 = solve(p, k, r);
            if (temp.first + p2.first + p[l] * p[k] * p[r] < currMin)
            {
                currMin = temp.first + p2.first + p[l] * p[k] * p[r];

                minString = temp.second + p2.second;
            }
        }

        return dp[key] = {currMin, "(" + minString + ")"};
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
        int p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i];

        Solution ob;
        cout << ob.matrixChainOrder(p, n) << "\n";
    }
    return 0;
}