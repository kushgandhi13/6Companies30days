// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string solve(const string &s, int &curIndex)
    {
        string ans = "";
        while (curIndex < s.length() && s[curIndex] != ']')
        {
            if (!isdigit(s[curIndex]))
                ans += s[curIndex++];
            else
            {
                int temp = 0;
                while (curIndex < s.length() && isdigit(s[curIndex]))
                    temp = temp * 10 + (s[curIndex++] - '0');

                curIndex++;
                string str = solve(s, curIndex);
                curIndex++;
                // temp--;
                while (temp--)
                    ans += str;
            }
        }

        return ans;
    }

    string decodedString(string s)
    {
        int curIndex = 0;
        return solve(s, curIndex);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";
    }
    return 0;
} // } Driver Code Ends