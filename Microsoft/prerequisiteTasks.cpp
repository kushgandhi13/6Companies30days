#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int i, vector<int> adj[], vector<bool> &visited, vector<bool> &curr)
    {
        visited[i] = true;
        curr[i] = true;

        for (auto x : adj[i])
        {
            if (!visited[x] && dfs(x, adj, visited, curr))
                return true;
            else if (curr[x])
                return true;
        }
        curr[i] = false;
        return false;
    }

    bool isPossible(int n, vector<pair<int, int>> &pre)
    {
        vector<int> adj[n];
        for (int i = 0; i < pre.size(); i++)
        {
            auto temp = pre[i];
            adj[temp.second].push_back(temp.first);
        }

        vector<bool> visited(n, false);
        vector<bool> curr(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, curr))
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}