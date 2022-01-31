#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(string &ans, string str, int curIndex, int k)
    {
        if (k == 0)
            return;

        int n = str.length();

        char ch = str[curIndex];
        for (int i = curIndex + 1; i < n; i++)
            ch = max(ch, str[i]);

        if (ch != str[curIndex])
            k--;

        for (int j = n - 1; j >= curIndex; j--)
        {
            if (ch == str[j])
            {
                swap(str[curIndex], str[j]);
                if (str.compare(ans) > 0)
                    ans = str;

                solve(ans, str, curIndex + 1, k);
                swap(str[curIndex], str[j]);
            }
        }
    }

    string findMaximumNum(string str, int k)
    {
        string ans = str;
        solve(ans, str, 0, k);
        return ans;
    }
};

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
