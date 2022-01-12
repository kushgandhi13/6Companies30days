#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
   
    vector<int> calculateSpan(int price[], int n)
    {
        vector<int> ans(n, 0);
        stack<pair<int, int>> s;
        s.push({INT_MAX, 0});
        for (int i = 0; i < n; i++)
        {

            if (s.top().first > price[i])
            {
                ans[i] = i - (s.top().second) + 1;
                s.push({price[i], i + 1});
            }
            else
            {
                while (s.top().first <= price[i])
                {
                    s.pop();
                }

                ans[i] = i - (s.top().second) + 1;
                s.push({price[i], i + 1});
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
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> s = obj.calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
