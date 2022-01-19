#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string amendSentence(string s)
    {
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (isupper(s[i]))
            {
                if (i != 0)
                    ans += " ";

                s[i] ^= (1 << 5);
                ans += s[i];
            }
            else
                ans += s[i];
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.amendSentence(s) << endl;
    }
}