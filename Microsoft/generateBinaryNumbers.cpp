#include <bits/stdc++.h>
using namespace std;

vector<string> generate(int n)
{
    vector<string> ans;
    // solve(ans,"1",n-1);
    // ans.push_back("1");
    queue<string> q;
    q.push("1");
    // n--;

    while (!q.empty() && n > 0)
    {
        int size = q.size();
        for (int i = 0; i < size && n > 0; i++)
        {
            auto temp = q.front();
            ans.push_back(temp);
            q.pop();
            q.push(temp + "0");
            q.push(temp + "1");
            n--;
        }
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> ans = generate(n);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}