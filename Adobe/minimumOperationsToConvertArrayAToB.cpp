#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &v)
    {
        vector<int> ans;
        // ans.push_back(v[0]);

        for (int i = 0; i < v.size(); i++)
        {
            auto pos = lower_bound(ans.begin(), ans.end(), v[i]);
            if (pos == ans.end())
                ans.push_back(v[i]);
            else
                ans[pos - ans.begin()] = v[i];
        }

        return ans.size();
    }

    int minInsAndDel(int a[], int b[], int n, int m)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < m; i++)
            mp[b[i]]++;

        vector<int> v;
        for (int i = 0; i < n; i++)
            if (mp.find(a[i]) != mp.end())
            {
                v.push_back(a[i]);
                mp[a[i]]--;
            }
        int temp = solve(v);
        return (n + m) - (2 * temp);
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;

        int A[N], B[M];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < M; i++)
            cin >> B[i];

        Solution ob;
        cout << ob.minInsAndDel(A, B, N, M) << endl;
    }
    return 0;
} 