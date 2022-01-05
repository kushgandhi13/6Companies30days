// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string printMinNumberForPattern(string s)
    {
        int count = 1;
        stack<int> st;
        int n = s.length();
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'D')
                st.push(count++);
            else
            {
                st.push(count++);
                while (!st.empty())
                {
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }

        ans += to_string(count);
        // cout<<ans<<" "<<st.size()<<endl;
        while (!st.empty())
        {
            ans += to_string(st.top());
            st.pop();
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0;
}
