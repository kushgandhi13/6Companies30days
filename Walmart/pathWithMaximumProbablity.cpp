#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<pair<int, double>> adj[n];

        for (int i = 0; i < edges.size(); i++)
        {
            int first = edges[i][0];
            int second = edges[i][1];
            adj[first].push_back({second, succProb[i]});
            adj[second].push_back({first, succProb[i]});
        }

        priority_queue<pair<int, double>> q;
        vector<double> prob(n, INT_MIN);
        // prob[0]=1;
        // prob[end] = 0;
        q.push({start, 1});
        while (!q.empty())
        {

            auto temp = q.top();
            q.pop();
            for (auto x : adj[temp.first])
            {
                if (x.second * temp.second > prob[x.first])
                {
                    prob[x.first] = x.second * temp.second;
                    q.push({x.first, prob[x.first]});
                }
            }
        }
        if (prob[end] == INT_MIN)
            return 0;
        return prob[end];
    }
};