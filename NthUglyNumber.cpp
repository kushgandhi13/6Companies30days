// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
// #define ull unsigned long long
/* Function to get the nth ugly number*/
#define ll unsigned long long
    ull getNthUglyNo(int n)
    {
        if (n == 1)
            return 1;
        vector<ll> v(1, 1);
        ll i, j, k;
        i = j = k = 0;
        while (v.size() < n)
        {
            v.push_back(min(v[i] * 2, min(v[j] * 3, v[k] * 5)));
            if (v.back() == v[i] * 2)
                i++;
            if (v.back() == v[j] * 3)
                j++;
            if (v.back() == v[k] * 5)
                k++;
        }

        return v.back();
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends