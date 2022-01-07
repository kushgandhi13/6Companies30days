#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        set<string> st;
        for (int i = 0; i < n; i++)
            st.insert(contact[i]);

        vector<string> contacts(n);
        int k = 0;
        for (auto x : st)
            contacts[k++] = x;

        int first = 0, last = n - 1;
        vector<vector<string>> ans(s.length());
        int temp = -1;
        for (int i = 1; i <= s.length(); i++)
        {
            int f1 = -1, l1 = -1;
            for (int j = first; j <= last; j++)
            {
                if (s.substr(0, i) == contacts[j].substr(0, i))
                {
                    ans[i - 1].push_back(contacts[j]);
                    if (f1 == -1)
                        f1 = j;
                    else
                        l1 = j;
                }
            }
            if (f1 != -1 && l1 != -1)
                first = f1, last = l1;
            else if (f1 != -1 && l1 == -1)
                first = f1, last = f1;
            else
            {
                temp = i;
                break;
            }
        }
        // cout<<temp;
        if (temp != -1)
        {
            while (temp <= s.length())
            {
                ans[temp - 1].push_back("0");
                temp++;
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
        string contact[n], s;
        for (int i = 0; i < n; i++)
            cin >> contact[i];
        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < s.size(); i++)
        {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
}