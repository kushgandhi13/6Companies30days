#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(string str, int left, int right, vector<string> &ans)
    {
        if (left == 0 && right == 0)
        {
            ans.push_back(str);
            return;
        }
        if (left < 0 || right < 0)
            return;

        if (left == right)
            solve(str + "(", left - 1, right, ans);

        if (right > left)
        {
            solve(str + "(", left - 1, right, ans);
            solve(str + ")", left, right - 1, ans);
        }
    }

    vector<string> AllParenthesis(int n)
    {
        vector<string> ans;
        solve("", n, n, ans);
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
        Solution ob;
        vector<string> result = ob.AllParenthesis(n);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << "\n";
    }
    return 0;
}
