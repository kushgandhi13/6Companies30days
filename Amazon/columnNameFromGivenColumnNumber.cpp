#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string colName(long long int n)
    {
        string ans = "";
        while (n > 0)
        {
            char temp = 'A' + (n - 1) % 26;
            ans = temp + ans;
            n = (n - 1) / 26;
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
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.colName(n) << '\n';
    }
}
