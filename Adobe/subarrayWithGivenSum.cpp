#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int i, j;
        for (i = 0; i < n; i++)
        {
            long long sum = 0;
            for (j = i; j < n; j++)
            {
                sum += arr[j];
                if (sum >= s)
                    break;
            }
            if (sum == s)
                break;
        }
        vector<int> ans;
        if (i == n)
        {
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(i + 1);
        ans.push_back(j + 1);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long s;
        cin >> n >> s;
        int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}