#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        set<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                int low = j + 1, high = n - 1;
                vector<int> v;
                while (low < high)
                {
                    int sum = arr[i] + arr[j] + arr[low] + arr[high];
                    if (sum == k)
                    {
                        v.push_back(arr[i]);
                        v.push_back(arr[j]);
                        v.push_back(arr[low]);
                        v.push_back(arr[high]);
                        ans.insert(v);
                        v.clear();
                        low++;
                        high--;
                    }
                    else if (sum < k)
                        low++;
                    else
                        high--;
                }
            }
        }

        vector<vector<int>> temp;
        for (auto x : ans)
            temp.push_back(x);
        return temp;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.fourSum(a, k);
        for (auto &v : ans)
        {
            for (int &u : v)
            {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty())
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}