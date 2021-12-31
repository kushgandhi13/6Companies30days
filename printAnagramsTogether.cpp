#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &v)
    {
        int n = v.size();
        // sort(v.begin(),v.end());
        map<string, int> mp;
        int k = 1;
        vector<string> copy = v;
        for (int i = 0; i < n; i++)
        {
            string str = copy[i];
            sort(str.begin(), str.end());
            if (mp[str] == 0)
                mp[str] = k++;
            copy[i] = str;
        }
        // for(int i=0;i<n;i++)
        //     cout<<copy[i]<<" ";
        vector<vector<string>> ans(k - 1);
        for (int i = 0; i < n; i++)
        {
            int temp = mp[copy[i]];
            ans[temp - 1].push_back(v[i]);
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        Solution ob;
        vector<vector<string>> result = ob.Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends