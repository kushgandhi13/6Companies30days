#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> &p)
    {
        vector<int> v;
        vector<int> adj[n + 1];
        map<int, int> mp;
        for (auto x : p)
        {
            adj[x[0]].push_back(x[1]);
            mp[x[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (mp[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int temp = q.front();
            v.push_back(temp);
            q.pop();
            for (auto x : adj[temp])
            {
                mp[x]--;
                if (mp[x] == 0)
                    q.push(x);
            }
        }
        if (v.size() == n)
        {
            reverse(v.begin(), v.end());
            return v;
        }
        else
        {
            v.clear();
            return v;
        }
    }
};