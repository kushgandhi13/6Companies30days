#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countWays(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        return (long long)(1 + (n / 2));
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array
    }
    return 0;
}