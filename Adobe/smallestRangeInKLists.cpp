#include <bits/stdc++.h>
using namespace std;
#define N 1000

class Solution
{
public:
    pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v.push_back({KSortedArray[i][j], i});
            }
        }
        pair<int, int> ans;
        sort(v.begin(), v.end());
        unordered_map<int, int> mp;
        int i = 0, j = 0, size = v.size(), minn = INT_MAX;

        while (j < size)
        {
            auto temp = v[j];
            mp[temp.second]++;

            if (mp.size() < k)
                j++;
            else if (mp.size() == k)
            {
                while (mp.size() == k)
                {
                    if (v[j].first - v[i].first + 1 < minn)
                    {
                        minn = v[j].first - v[i].first + 1;
                        ans = {v[i].first, v[j].first};
                    }
                    mp[v[i].second]--;

                    if (mp[v[i].second] == 0)
                        mp.erase(v[i].second);

                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[N][N];
        pair<int, int> rangee;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        rangee = obj.findSmallestRange(arr, n, k);
        cout << rangee.first << " " << rangee.second << "\n";
    }
    return 0;
}
