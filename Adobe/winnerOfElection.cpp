#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> winner(string arr[], int n)
    {
        map<string, int> mp;
        int maxx = 0;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
            maxx = max(maxx, mp[arr[i]]);
        }

        for (auto x : mp)
            if (x.second != maxx)
                continue;
            else
                return {x.first, to_string(maxx)};

        return {};
    }
};

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int n;
        cin >> n;

        string arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr, n);

        cout << result[0] << " " << result[1] << endl;
    }
    return 0;
}
