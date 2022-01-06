#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string s)
    {
        int n = s.size();
        string str = "";

        vector<int> freq(26, 0);
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
            if (freq[s[i] - 'a'] == 1)
            {
                q.push(s[i] - 'a');
            }

            while (!q.empty() && freq[q.front()] != 1)
            {
                q.pop();
            }
            if (q.empty())
                s[i] = '#';
            else
                s[i] = q.front() + 'a';
        }
        return s;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}